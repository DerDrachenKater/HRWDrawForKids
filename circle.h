#ifndef CIRCLE_H
#define CIRCLE_H

#include "graphicsobject.h"
#include <QColor>
#include <QGraphicsEllipseItem>
#include <QJsonObject>

class Circle : public GraphicsObject
{
    Q_OBJECT
public:
    /**
     * @brief create a new Circle object
     * @param parent object (see QObject documentation)
     */
    explicit Circle(QObject *parent = nullptr);

    /**
     * @brief create a new Circle object
     * @param x x-position of center
     * @param y y-position of center
     * @param z z-value of the circle
     * @param radius of circle
     * @param parent object (see QObject documentation)
     */
    explicit Circle(qreal x, qreal y, qreal z, qreal radius, QColor fillColor, QColor lineColor, QObject *parent = 0);

    /**
     * @brief create a new Circle object from JSON object
     * @param jsonObject JSON object that holds the data for the object
     * @param parent object (see QObject documentation)
     */
    explicit Circle(const QJsonObject &jsonObj, QObject *parent = nullptr);

    /**
     * @brief destructor. Destroys the QGraphicsEllipseItem object
     */
    ~Circle();


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
     * @brief create a JSON-object with all information about the object
     * @return JSON-object
     */
    virtual QJsonObject toJson();


public slots:
    void setX(qreal x);
    void setY(qreal y);
    void setZ(qreal z);
    void setRadius(qreal radius);


protected:
    static unsigned long m_circleCounter;       ///< counter for number for of circle objects created so far (class member)
    QGraphicsEllipseItem *m_graphicsEllipse;    ///< the Qt Graphics Object for drawing in a QGraphicsScene


private:
    void createFromParameters(QString name, qreal x, qreal y, qreal z, qreal radius,
                         QColor fillColor, QColor lineColor);

};

#endif // CIRCLE_H
