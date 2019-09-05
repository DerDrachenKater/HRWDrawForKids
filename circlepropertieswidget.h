#ifndef CIRCLEPROPERTIES_H
#define CIRCLEPROPERTIES_H

#include "graphicsobjectpropertieswidget.h"

#include <QWidget>

namespace Ui {
class CirclePropertiesWidget;
}

/**
 * @brief This class holds and manages the Property-GUI (position and size) of a circle
 */
class CirclePropertiesWidget : public GraphicsObjectPropertiesWidget
{
    Q_OBJECT

public:
    /**
     * @brief create a new CircleProperties object
     */
    explicit CirclePropertiesWidget(QWidget *parent = nullptr);
    ~CirclePropertiesWidget();


    /**
     * @brief returns the radius of the circle
     * @return radius
     */
    int radius() const;



signals:
    /**
     * @brief signal indicates that properties were changed
     * @param new properties
     */
    void propertiesChanged(CirclePropertiesWidget *properties);

public slots:


    /**
     * @brief sets a new radius for the circle
     * @param new radius
     */
    void setRadius(int radius);





    /**
     * @brief sets new properties for the circle
     * @param x new x-position
     * @param y new y-position
     * @param z new z-value
     * @param radius new radius
     * @param name new name
     */
    void setProperties(int x, int y, int z, int radius, QString name);


    /**
     * @brief sets a new related graphicsObject
     * @param graphicsObject
     */
    virtual void setRelatedGraphicsObject(GraphicsObject *relatedGraphicsObject);

protected:

    int m_radius;   ///< radius of the circle


private slots:
    void on_nameEdit_editingFinished();

    void on_xSpinner_valueChanged(int arg1);

    void on_ySpinner_valueChanged(int arg1);

    void on_zSpinner_valueChanged(int arg1);

    void on_radiusSpinner_valueChanged(int arg1);

private:
    Ui::CirclePropertiesWidget *ui;
};

#endif // CIRCLEPROPERTIES_H
