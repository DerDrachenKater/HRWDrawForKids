#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>

#include "rectangle.h"
#include "circle.h"
#include "drawingoptions.h"
#include "graphicsobjectsmap.h"
#include "graphicsscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void activeDrawingToolChanged(DrawingOptions::DrawingTool activeDrawingTool);

protected slots:

    void on_activeDrawingToolChanged(DrawingOptions::DrawingTool drawingTool);
    void on_newGraphicsItemSelected(QGraphicsItem *selectedItem);
    void on_newGraphicsObjectCreated(GraphicsObject *newObject);

    // GUI-Slots
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionSelect_triggered();
    void on_actionRectangle_triggered();
    void on_actionCircle_triggered();
    void on_actionTools_toggled(bool arg1);
    void on_actionProperties_toggled(bool arg1);
    void on_actionAbout_triggered();
    void on_propertiesDock_visibilityChanged(bool visible);
    void on_toolAndColorDock_visibilityChanged(bool visible);

private:
    Ui::MainWindow *ui;             ///< access to ui-Objects


protected:
    DrawingOptions m_drawingOptions;  ///< options from tool bar for drawing the next object
    GraphicsObjectsMap *m_goMap;      ///< stores all graphic objects in the scene
    GraphicsScene *m_scene;           ///< the scene object that holds the objects that shall be drawn



private slots:
    void on_actionExport_PNG_triggered();
};

#endif // MAINWINDOW_H
