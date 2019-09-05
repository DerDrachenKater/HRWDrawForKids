#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "graphicsobject.h"
#include <QGraphicsRectItem>
#include <QJsonObject>

class Rectangle : public GraphicsObject
{
    Q_OBJECT

public:
    /**
     * @brief create a new Rectangle object
     * @param parent object (see QObject documentation)
     */
    explicit Rectangle(QObject *parent = nullptr);


    /**
     * @brief create a new Rectangle object
     * @param x x-position of upper left corner
     * @param y y-position of upper left corner
     * @param z z-Value of the object
     * @param width width of rectangle
     * @param height height of rectangle
     * @param parent object (see QObject documentation)
     */
    explicit Rectangle(qreal x, qreal y, qreal z, qreal width, qreal height, QColor fillColor, QColor lineColor, QObject *parent = nullptr);


    /**
     * @brief create a new Rectangle object from JSON object
     * @param jsonObject JSON object that holds the data for the object
     * @param parent object (see QObject documentation)
     */
    explicit Rectangle(const QJsonObject &jsonObj, QObject *parent = nullptr);

    /**
     * @brief destructor. Destroys the QGraphicsRectangleItem object
     */
    ~Rectangle();



    /**
     * @brief returns the corresponding QGraphicsItem object
     * @return name
     */
    virtual QGraphicsItem *graphicsItem() const;

    /**
     * @brief create a string with selected information about the object
     * type, name, position, dimension, colors
     * @return string with selected information about the object
     */
    virtual QString toString();


    /**
     * @brief create a JSON-pbject with all information about the object
     * @return JSON-object
     */
    virtual QJsonObject toJson();


    void setX(qreal x);
    void setY(qreal y);
    void setZ(qreal z);
    void setWidth(qreal width);
    void setHeight(qreal height);

protected:
    static unsigned long m_rectangleCounter;    ///< counter for number for of rectangle objects created so far (class member)
    QGraphicsRectItem *m_graphicsRect;          ///< the Qt Graphics Object for drawing in a QGraphicsScene

private:
    void createFromParameters(QString name, qreal x, qreal y, qreal z,
            qreal width, qreal height, QColor fillColor, QColor lineColor);

};

#endif // RECTANGLE_H
