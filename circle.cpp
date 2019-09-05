#include "circle.h"


#include <QBrush>
#include <QPen>
#include <QDebug>


/**
 * @brief class member which stores the number of created circle objects
 *
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
unsigned long Circle::m_circleCounter = 0;


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
Circle::Circle(QObject *parent) : Circle(100, 100, 0, 50, Qt::blue, Qt::black, parent)
{
}


/**
 * @author Mario Breitenbach
 * @version 0.3
 * @date 2016-01-11
 * moved most assignments to new createFromParameters function
 * added z-value
 * @version 0.2
 * @date 2015-12-06
 * added flags setting
 * @version 0.1
 * @date 2015-10-24
 */
Circle::Circle(qreal x, qreal y, qreal z, qreal radius, QColor fillColor, QColor lineColor,  QObject *parent) : GraphicsObject(parent)
{
    //creating automatic name for object
    m_circleCounter++;
    QString name = QString("circle_%1").arg(m_circleCounter);

    createFromParameters(name, x, y, z, radius, QColor(fillColor), QColor(lineColor));
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
Circle::Circle(const QJsonObject &jsonObj, QObject *parent)
{
    m_circleCounter++;

    QString name = jsonObj["name"].toString();
    qreal x = jsonObj["x"].toDouble();
    qreal y = jsonObj["y"].toDouble();
    qreal z = jsonObj["z"].toDouble();
    qreal radius = jsonObj["radius"].toDouble();
    QString fillColor = jsonObj["fillColor"].toString();
    QString lineColor = jsonObj["lineColor"].toString();

    createFromParameters(name, x, y, z, radius, QColor(fillColor), QColor(lineColor));
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
Circle::~Circle()
{
    if(m_graphicsEllipse) delete m_graphicsEllipse;
}




/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-01-11
 */
void Circle::createFromParameters(QString name, qreal x, qreal y, qreal z, qreal radius, QColor fillColor, QColor lineColor)
{
    m_name = name;

    // crteating graphics item
    QGraphicsEllipseItem *ellipse = new QGraphicsEllipseItem(x-radius, y-radius, 2*radius, 2*radius);
    if(!ellipse) {
        qDebug() << "WARNING! Creating graphicsItem (QGraphicsEllipseItem) failed!";
        return;
    }


    // setting z
    ellipse->setZValue(z);

    // setting colors
    ellipse->setBrush(QBrush(fillColor));
    ellipse->setPen(QPen(lineColor));

    // set graphicsItem to new ellipse
    m_graphicsEllipse = ellipse;

    // setting flags
    m_graphicsEllipse->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
QGraphicsItem *Circle::graphicsItem() const
{
    return m_graphicsEllipse;
}


/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2016-01-11
 * added z-value
 * @version 0.1
 * @date 2015-10-24
 */
QString Circle::toString()
{
    qreal radius = m_graphicsEllipse->rect().width() / 2;
    return "Circle: " + m_name
            + " center x: " + QString::number(m_graphicsEllipse->rect().x() + radius)
            + " center y: " + QString::number(m_graphicsEllipse->rect().y() + radius)
            + " z-value: " + QString::number(m_graphicsEllipse->zValue())
            + " radius: " + QString::number(radius)
            + " fill color: " + m_graphicsEllipse->brush().color().name()
            + " line color: " + m_graphicsEllipse->pen().color().name();
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-10
 */
QJsonObject Circle::toJson()
{
    QJsonObject jsonObj;
    jsonObj["type"] = "Circle";
    jsonObj["name"] = m_name;

    qreal radius = m_graphicsEllipse->rect().width()/2;
    jsonObj["x"] = m_graphicsEllipse->rect().x() + radius;
    jsonObj["y"] = m_graphicsEllipse->rect().y() + radius;
    jsonObj["z"] = m_graphicsEllipse->zValue();
    jsonObj["radius"] = radius;
    jsonObj["fillColor"] = m_graphicsEllipse->brush().color().name(QColor::HexArgb);
    jsonObj["lineColor"] = m_graphicsEllipse->pen().color().name(QColor::HexArgb);

    return jsonObj;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
void Circle::setX(qreal x)
{
    QRectF rect = m_graphicsEllipse->rect();
    qreal oldWidth = rect.width();
    rect.setX(x - oldWidth/2);
    rect.setWidth(oldWidth);
    m_graphicsEllipse->setRect(rect);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
void Circle::setY(qreal y)
{
    QRectF rect = m_graphicsEllipse->rect();
    qreal oldHeight = rect.height();
    rect.setY(y-oldHeight/2);
    rect.setHeight(oldHeight);
    m_graphicsEllipse->setRect(rect);
}

void Circle::setZ(qreal z)
{
    m_graphicsEllipse->setZValue(z);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
void Circle::setRadius(qreal radius)
{
    QRectF rect = m_graphicsEllipse->rect();
    rect.setWidth(2*radius);
    rect.setHeight(2*radius);
    m_graphicsEllipse->setRect(rect);
}




