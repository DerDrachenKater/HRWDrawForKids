#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QAbstractGraphicsShapeItem>
#include <QColorDialog>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonParseError>
#include <QFileDialog>
#include <QFile>

#include "propertywidget.h"



/**
 * @author Mario Breitenbach
 * @version 0.4
 * @date 2016-01-11
 * m_goMap is no a po
 * @version 0.3
 * @date 2015-12-20
 * Fixed bug which resulted in undefined drawing tool state
 * after program start
 * @version 0.2
 * @date 2015-11-23
 * Prepared for drawing tool selector widgets
 * @version 0.1
 * @date 2015-10-24
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_goMap(NULL)
{
    m_goMap = new GraphicsObjectsMap();
    if(!m_goMap) {
        qDebug() << "cannot allocate memory for goMap";
        return;
    }
    ui->setupUi(this);

    // Connections for the drawing tool
    connect(&m_drawingOptions, SIGNAL(activeDrawingToolChanged(DrawingOptions::DrawingTool)),
            ui->drawingToolSelector, SLOT(setActiveDrawingTool(DrawingOptions::DrawingTool)));
    connect(ui->drawingToolSelector, SIGNAL(activeDrawingToolChanged(DrawingOptions::DrawingTool)),
            &m_drawingOptions, SLOT(setActiveDrawingTool(DrawingOptions::DrawingTool)));

    connect(&m_drawingOptions, SIGNAL(activeDrawingToolChanged(DrawingOptions::DrawingTool)),
            this, SLOT(on_activeDrawingToolChanged(DrawingOptions::DrawingTool)));
    connect(this, SIGNAL(activeDrawingToolChanged(DrawingOptions::DrawingTool)),
            &m_drawingOptions, SLOT(setActiveDrawingTool(DrawingOptions::DrawingTool)));

    // Connections for the fill color
    connect(&m_drawingOptions, SIGNAL(activeFillColorChanged(QColor)),
            ui->colorSelector, SLOT(setActiveFillColor(QColor)));
    connect(ui->colorSelector, SIGNAL(activeFillColorChanged(QColor)),
            &m_drawingOptions, SLOT(setActiveFillColor(QColor)));

    // Connections for the line color
    connect(&m_drawingOptions, SIGNAL(activeLineColorChanged(QColor)),
            ui->colorSelector, SLOT(setActiveLineColor(QColor)));
    connect(ui->colorSelector, SIGNAL(activeLineColorChanged(QColor)),
            &m_drawingOptions, SLOT(setActiveLineColor(QColor)));


    // Initialize scene
    m_scene = new GraphicsScene();
    if(!m_scene) {
        qDebug() << "WARNING: Unable to create scene!";
        return;
    }

    m_scene->setSceneRect(0, 0, 400, 400);
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setSceneRect(0, 0, 400, 400);

    m_scene->setBackgroundBrush(QBrush(Qt::white));

    // Connection from and to scene
    connect(&m_drawingOptions, SIGNAL(drawingOptionsChanged(DrawingOptions*)),
            m_scene, SLOT(setDrawingOptions(DrawingOptions*)));
    connect(m_scene, SIGNAL(newGraphicsObjectCreated(GraphicsObject*)),
            this, SLOT(on_newGraphicsObjectCreated(GraphicsObject*)));
    connect(m_scene, SIGNAL(newGraphicsItemSelected(QGraphicsItem*)),
            this, SLOT(on_newGraphicsItemSelected(QGraphicsItem*)));



    // Initialize drawing options
    m_drawingOptions.setActiveDrawingTool(DrawingOptions::SelectTool);
    m_drawingOptions.setActiveFillColor(Qt::red);
    m_drawingOptions.setActiveLineColor(Qt::blue);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief handles the change of the drawing tool
 * changes the active tool
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void MainWindow::on_activeDrawingToolChanged(DrawingOptions::DrawingTool drawingTool)
{
    if(drawingTool == DrawingOptions::SelectTool) {
        ui->actionSelect->setChecked(true);
        ui->actionRectangle->setChecked(false);
        ui->actionCircle->setChecked(false);

        ui->propertyWidget->setActiveView(PropertyWidget::NoPropertyView);
    }

    else if(drawingTool == DrawingOptions::DrawRectangleTool)
    {
        ui->actionSelect->setChecked(false);
        ui->actionRectangle->setChecked(true);
        ui->actionCircle->setChecked(false);


        ui->propertyWidget->setActiveView(PropertyWidget::RectanglePropertyView);
    }
    else if(drawingTool == DrawingOptions::DrawCircleTool)
    {
        ui->actionSelect->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionCircle->setChecked(true);


        ui->propertyWidget->setActiveView(PropertyWidget::CirclePropertyView);
    }
    else {
        ui->actionSelect->setChecked(false);
        ui->actionRectangle->setChecked(false);
        ui->actionCircle->setChecked(false);

        ui->propertyWidget->setActiveView(PropertyWidget::NoPropertyView);
    }
}



/**
 * @brief handles the change of the selected graphics item
 * adapts property view
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void MainWindow::on_newGraphicsItemSelected(QGraphicsItem *selectedItem)
{

    if(selectedItem != nullptr) {
        GraphicsObjectsMap::const_iterator i = m_goMap->find(selectedItem);
        if(i != m_goMap->end()) {
            GraphicsObject *go = *i;

            if(go->inherits("Rectangle")) {
                ui->propertyWidget->setActiveView(PropertyWidget::RectanglePropertyView);
                ui->propertyWidget->setRelatedGraphicsObject(go);

            }
            else if(go->inherits("Circle")) {
                ui->propertyWidget->setActiveView(PropertyWidget::CirclePropertyView);
                ui->propertyWidget->setRelatedGraphicsObject(go);
            }
            else {
                qDebug() << "ERROR: Unknown Object Type!";
                ui->propertyWidget->setActiveView(PropertyWidget::NoPropertyView);
                return;
            }
        }
        else {
            qDebug() << "ERROR: Item not found in goMap!";
            ui->propertyWidget->setActiveView(PropertyWidget::NoPropertyView);
            return;
        }
    }
    else {
        ui->propertyWidget->setActiveView(PropertyWidget::NoPropertyView);
    }
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open...", "", "HRW-Images (*.hrw)");
    // check if cancel was selected
    if(fileName.isNull()) return;

    // open file
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file " << fileName << " for reading!";  // better implement a MessageBox for the user
        return;
    }

    // read from file
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(),&jsonError);
    if(jsonError.error != QJsonParseError::NoError) {
        qDebug() << "JSON Error: " << jsonError.errorString();
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    // check app string
    if(jsonObj["app"] != "HRW Vector Drawing") {
        qDebug() << "This file is not from the HRW Vector Drawing app!"; // better implement a MessageBox for the user
        return;
    }

    // delete old objects
    if(m_goMap) {
        foreach(GraphicsObject *go, *m_goMap) {
            delete go;
        }
        delete m_goMap;
    }

    // read width and height but currently ignore the value as they are currently fixed
    int width = jsonObj["width"].toInt();
    int height = jsonObj["height"].toInt();

    // read graphics objects
    QJsonArray jsonGraphicsObjects = jsonObj["graphicsObjects"].toArray();

    m_goMap = new GraphicsObjectsMap(jsonGraphicsObjects);
    if(!m_goMap) {
        qDebug() << "cannot allocate memory for goMap";
        return;
    }

    // add new objects to scene
    foreach(GraphicsObject *go, *m_goMap) {
        m_scene->addItem(go->graphicsItem());
    }

    // close file
    file.close();

}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save as...", "", "HRW-Images (*.hrw)");
    // check if cancel was selected
    if(fileName.isNull()) return;

    // add .hrw if not done by user
    if(!fileName.endsWith(".hrw", Qt::CaseInsensitive)) {
        fileName += ".hrw";
    }


    // create JSON Object
    QJsonObject jsonObj;
    jsonObj["app"] = "HRW Vector Drawing";
    jsonObj["width"] = m_scene->width();
    jsonObj["height"] = m_scene->height();

    jsonObj["graphicsObjects"] = m_goMap->toJson();

    QJsonDocument jsonDoc(jsonObj);

    // open file
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Unable to open file " << fileName << " for writing!";  // better implement a MessageBox for the user
        return;
    }

    // write to file
    QTextStream stream(&file);
    stream << jsonDoc.toJson();

    // close file
    file.close();

}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void MainWindow::on_actionSelect_triggered()
{
    emit activeDrawingToolChanged(DrawingOptions::SelectTool);
    on_activeDrawingToolChanged(DrawingOptions::SelectTool);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void MainWindow::on_actionRectangle_triggered()
{
    emit activeDrawingToolChanged(DrawingOptions::DrawRectangleTool);
    on_activeDrawingToolChanged(DrawingOptions::DrawRectangleTool);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void MainWindow::on_actionCircle_triggered()
{
    emit activeDrawingToolChanged(DrawingOptions::DrawCircleTool);
    on_activeDrawingToolChanged(DrawingOptions::DrawCircleTool);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void MainWindow::on_newGraphicsObjectCreated(GraphicsObject *newObject)
{
    m_goMap->insert(newObject->graphicsItem(), newObject);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-20
 */
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox aboutMsg;
    aboutMsg.setWindowTitle("About HRWDraw");
    aboutMsg.setIconPixmap(QPixmap(":/icons/icons/hrw_icon.png"));
    aboutMsg.setWindowIcon(QPixmap(":/icons/icons/hrw_icon.png"));


    aboutMsg.setInformativeText("An example for GUI programming.<p>"
                                "<i>(C) Mario Breitenbach, Hochschule Ruhr West, University "
                                "of Applied Sciences.");
    aboutMsg.setDetailedText("This program is an example for "
                             "GUI programming with Qt. \n"
                             "It is part of a programming course "
                             "at the Hochschule Ruhr West, University "
                             "of Applied Sciences.\n");
    aboutMsg.exec();
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-01
 */
void MainWindow::on_toolAndColorDock_visibilityChanged(bool visible)
{
   ui->actionTools->setChecked(visible);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-01
 */
void MainWindow::on_propertiesDock_visibilityChanged(bool visible)
{
    ui->actionProperties->setChecked(visible);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-01
 */
void MainWindow::on_actionTools_toggled(bool arg1)
{
    ui->toolAndColorDock->setVisible(arg1);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-01
 */
void MainWindow::on_actionProperties_toggled(bool arg1)
{
    ui->propertiesDock->setVisible(arg1);
}


/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2016-01-10)
 */
void MainWindow::on_actionExport_PNG_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export as PNG", "", "Images (*.png)");
    // check if cancel was selected
    if(fileName.isNull()) return;

    // add .png if not done by user
    if(!fileName.endsWith(".png", Qt::CaseInsensitive)) {
        fileName += ".png";
    }

    // create image
    QImage img(m_scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
    m_scene->clearSelection();
    m_scene->createImage(img);
    img.save(fileName);
}
