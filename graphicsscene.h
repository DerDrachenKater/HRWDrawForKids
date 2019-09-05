#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include "drawingoptions.h"
#include "graphicsobject.h"

/**
 * @brief The GraphicsScene class stores takes the graphic objects that shall be displayed
 */
class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    /**
     * @brief create a new GraphicsScene object
     * @see QGraphicsScene documentation for more details
     */
    explicit GraphicsScene(QObject *parent = nullptr);

    /**
     * @brief render the scene and store the image in img
     * @param img image to store the rendered image
     */
    void createImage(QImage &img);


signals:
    /**
     * @brief indicates that a new graphics object was created
     * @param the new graphics object
     */
    void newGraphicsObjectCreated(GraphicsObject *);

    /**
     * @brief indicates that a new graphics item was selected
     * @param the selected graphics item, or NULL if nothing was selected
     */
    void newGraphicsItemSelected(QGraphicsItem *);




public slots:
    /**
     * @brief set new active drawing options
     * @param new drawing options
     */
    void setDrawingOptions(DrawingOptions *value);


    /**
     * @brief clears the selected elements
     */
    void clearSelection();


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);

    GraphicsObject *m_workingGraphicsObject;    ///< new graphics object during positioning phase
    bool m_isDrawing;                           ///< indicates if a drawing process is running (normally if the left mouse button is pressed)
    int m_drawingStartX;                      ///< start position (x) of the current drawing process
    int m_drawingStartY;                      ///< start position (y) of the current drawing process
    DrawingOptions *m_drawingOptions;           ///< current drawing options

    /**
     * @brief calculate new bounding box around the mouse positions while drawing
     * it considers that current mouse x can be smaller than start x, in this case the
     * bounding box starts at current mouse x (same for y)
     * @param startX start x position
     * @param startY start y position
     * @param mouseX current x position
     * @param mouseY current y position
     */
    QRectF calculateNewBoundingBox(qreal startX, qreal startY, qreal mouseX, qreal mouseY);

    /**
     * @brief calculate new bounding box around the mouse positions while drawing
     * it considers that current mouse x can be smaller than start x, in this case the
     * bounding box starts at current mouse x (same for y).
     * In addition the box will be a square with size of the maximum difference
     * in x vs. y dimension.
     * @param startX start x position
     * @param startY start y position
     * @param mouseX current x position
     * @param mouseY current y position
     */
    QRectF calculateNewBoundingBoxSquare(qreal startX, qreal startY, qreal mouseX, qreal mouseY);




};

#endif // GRAPHICSSCENE_H


