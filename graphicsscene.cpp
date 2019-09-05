#include "graphicsscene.h"

#include <QAbstractGraphicsShapeItem>
#include <QGraphicsItem>
#include <QDebug>
#include <QList>
#include <QPainter>

#include "rectangle.h"
#include "circle.h"


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
GraphicsScene::GraphicsScene(QObject *parent) : QGraphicsScene(parent), m_isDrawing(false), m_drawingOptions(NULL)
{

}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-01-09
 */
void GraphicsScene::createImage(QImage &img)
{
    img.fill(Qt::transparent);


    QPainter painter(&img);
    render(&painter);
}



/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2015-12-02
 */
QRectF GraphicsScene::calculateNewBoundingBox(qreal startX, qreal startY, qreal mouseX, qreal mouseY)
{
    QRectF res;

    res.setX(startX);
    res.setY(startY);

    if(mouseX - startX >= 0) {
        res.setWidth(mouseX - startX);
    }
    else {
        res.setX(mouseX);
        res.setWidth(startX - mouseX);
    }

    if(mouseY - startY >= 0) {
        res.setHeight(mouseY - startY);
    }
    else {
        res.setY(mouseY);
        res.setHeight(startY - mouseY);
    }

    return res;
}

/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2015-12-02
 */
QRectF GraphicsScene::calculateNewBoundingBoxSquare(qreal startX, qreal startY, qreal mouseX, qreal mouseY)
{
    QRectF res;

    qreal size = 0;
    if(qAbs(mouseX-startX) > qAbs(mouseY-startY)) {
        size = qAbs(mouseX - startX);
    }
    else {
        size = qAbs(mouseY - startY);
    }

    res.setX(startX);
    res.setY(startY);


    if(mouseX - startX <= 0) {
        res.setX(startX - size);
    }

    if(mouseY - startY <= 0) {
        res.setY(startY - size);
    }

    res.setWidth(size);
    res.setHeight(size);

    return res;
}

/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2015-12-02
 */
void GraphicsScene::setDrawingOptions(DrawingOptions *value)
{
    m_drawingOptions = value;
    clearSelection();
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-01-09
 */
void GraphicsScene::clearSelection()
{
    QGraphicsScene::clearSelection();
    emit newGraphicsItemSelected(NULL);
}


/**
 * @author Mario Breitenbach
 * @version 0.3
 * @date 2015-12-02
 * added z-value consideration
 * @version 0.2
 * @date 2015-12-02
 */
void GraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // ignore other button presses than left button
    if(mouseEvent->button() != Qt::LeftButton) {
        mouseEvent->ignore();
        return;
    }

    int mouseX = mouseEvent->scenePos().x();
    int mouseY = mouseEvent->scenePos().y();

    if(m_drawingOptions == NULL) {
        qDebug() << "DrawingOption is NULL!";
        return;
    }

    GraphicsObject *newObject = NULL;

    DrawingOptions::DrawingTool activeDrawingTool = m_drawingOptions->getActiveDrawingTool();
    QList<QGraphicsItem *> itemsAtClick;
    QGraphicsItem *topItem;
    qreal topZ = 0;
    if(items().size() > 0) {
        topZ = items()[0]->zValue();
    }

    switch(activeDrawingTool) {
    case DrawingOptions::SelectTool:
        clearSelection();
        itemsAtClick = items(mouseEvent->scenePos());
        topItem = NULL;

        if(itemsAtClick.size() > 0)
        {
            topItem = itemsAtClick.front();
            if(!topItem->isSelected()) {
                topItem->setSelected(true);
            }
        }

        emit newGraphicsItemSelected(topItem);

        return;

    case DrawingOptions::DrawRectangleTool:
        newObject = new Rectangle(mouseX, mouseY, topZ+1, 1, 1,
           m_drawingOptions->activeFillColor(), m_drawingOptions->activeLineColor());
        break;
    case DrawingOptions::DrawCircleTool:
        newObject = new Circle(mouseX, mouseY, topZ+1, 1,
           m_drawingOptions->activeFillColor(), m_drawingOptions->activeLineColor());
        break;
    default:
        qDebug() << "Unsupported Drawing Tool!";
        return;
    }


    // draw the new object (if one was created)
    if(newObject) {

        emit newGraphicsObjectCreated(newObject);

        addItem(newObject->graphicsItem());

        m_workingGraphicsObject = newObject;
        m_drawingStartX = mouseX;
        m_drawingStartY = mouseY;
        m_isDrawing = true;

        clearSelection();
        newObject->graphicsItem()->setSelected(true);
        emit newGraphicsItemSelected(newObject->graphicsItem());

    }
}


/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2015-12-02
 */
void GraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(!m_isDrawing) {
        mouseEvent->ignore();
        return;
    }

    if(mouseEvent->button() != Qt::LeftButton) {
        mouseEvent->ignore();
        return;
    }

    int mouseX = mouseEvent->scenePos().x();
    int mouseY = mouseEvent->scenePos().y();

    if(m_workingGraphicsObject->inherits("Rectangle")) {
        QRectF newRect = calculateNewBoundingBox(m_drawingStartX, m_drawingStartY, mouseX, mouseY);
        ((QGraphicsRectItem*)m_workingGraphicsObject->graphicsItem())->setRect(newRect);
    }
    else if(m_workingGraphicsObject->inherits("Circle")) {
        QRectF newRect = calculateNewBoundingBoxSquare(m_drawingStartX, m_drawingStartY, mouseX, mouseY);
        ((QGraphicsEllipseItem*)m_workingGraphicsObject->graphicsItem())->setRect(newRect);
    }



    emit newGraphicsItemSelected(m_workingGraphicsObject->graphicsItem());

    mouseEvent->accept();

    m_isDrawing = false;
}



/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2015-12-02
 */
void GraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(!m_isDrawing) {
        mouseEvent->ignore();
        return;
    }

    int mouseX = mouseEvent->scenePos().x();
    int mouseY = mouseEvent->scenePos().y();

    if(m_workingGraphicsObject->inherits("Rectangle")) {
        QRectF newRect = calculateNewBoundingBox(m_drawingStartX, m_drawingStartY, mouseX, mouseY);
        ((QGraphicsRectItem*)m_workingGraphicsObject->graphicsItem())->setRect(newRect);
    }
    else if(m_workingGraphicsObject->inherits("Circle")) {
        QRectF newRect = calculateNewBoundingBoxSquare(m_drawingStartX, m_drawingStartY, mouseX, mouseY);
        ((QGraphicsEllipseItem*)m_workingGraphicsObject->graphicsItem())->setRect(newRect);
    }
    else {
        qDebug() << "Unknown object: " << m_workingGraphicsObject->metaObject()->className();
    }

    emit newGraphicsItemSelected(m_workingGraphicsObject->graphicsItem());
    mouseEvent->accept();
}
