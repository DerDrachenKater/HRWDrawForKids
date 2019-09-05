#ifndef RECTANGLEPROPERTIES_H
#define RECTANGLEPROPERTIES_H

#include "graphicsobjectpropertieswidget.h"
#include "rectangle.h"

#include <QWidget>

namespace Ui {
class RectanglePropertiesWidget;
}

/**
 * @brief This class holds and manages the Property-GUI (position and size) of a rectangle
 */
class RectanglePropertiesWidget : public GraphicsObjectPropertiesWidget
{
    Q_OBJECT

public:
    /**
     * @brief create a new RectangleProperties object
     */
    explicit RectanglePropertiesWidget(QWidget *parent = nullptr);
    ~RectanglePropertiesWidget();



    /**
     * @brief returns the width of the rectangle
     * @return width
     */
    int width() const;

    /**
     * @brief returns the height of the rectangle
     * @return height
     */
    int height() const;


    /**
     * @brief returns the related graphicsObject
     * @return related graphicsObject
     */
//    virtual GraphicsObject *relatedGraphicsObject() const;


signals:
    /**
     * @brief signal indicates that properties were changed
     * @param new properties
     */
    void propertiesChanged(RectanglePropertiesWidget *properties);

public slots:


    /**
     * @brief sets a new width for the rectangle
     * @param new width
     */
    void setWidth(int width);

    /**
     * @brief sets a new height for the rectangle
     * @param new height
     */
    void setHeight(int height);



    /**
     * @brief sets new properties for the rectangle
     * @param x new x-position
     * @param y new y-position
     * @param z new z-value
     * @param width new width
     * @param height new height
     * @param name new name
     */
    void setProperties(int x, int y, int z, int width, int height, QString name);




    /**
     * @brief sets a new related graphicsObject
     * @param graphicsObject
     */
    virtual void setRelatedGraphicsObject(GraphicsObject *relatedGraphicsObject);


protected:

    int m_width;    ///< width of the rectangle
    int m_height;   ///< height of the rectangle




private slots:
    void on_nameEdit_editingFinished();

    void on_xSpinner_valueChanged(int arg1);

    void on_ySpinner_valueChanged(int arg1);

    void on_zSpinner_valueChanged(int arg1);

    void on_widthSpinner_valueChanged(int arg1);

    void on_heightSpinner_valueChanged(int arg1);



private:
    Ui::RectanglePropertiesWidget *ui;
};

#endif // RECTANGLEPROPERTIES_H
