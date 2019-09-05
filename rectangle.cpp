#include "rectangle.h"

#include <QBrush>
#include <QPen>
#include <QDebug>


/**
 * @brief class member which stores the number of created rectangle objects
 *
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
unsigned long Rectangle::m_rectangleCounter = 0;



/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2016-01-11
 * added z-value
 * @version 0.1
 * @date 2015-10-24
 */
Rectangle::Rectangle(QObject *parent) : Rectangle(10, 10, 0, 100, 100, Qt::blue, Qt::black, parent)
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
Rectangle::Rectangle(qreal x, qreal y, qreal z, qreal width, qreal height, QColor fillColor, QColor lineColor, QObject *parent) : GraphicsObject(parent)
{
    //creating automatic name for object
    m_rectangleCounter++;
    QString name = QString("rectangle_%1").arg(m_rectangleCounter);

    createFromParameters(name, x, y, z, width, height, fillColor, lineColor);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
Rectangle::Rectangle(const QJsonObject &jsonObj, QObject *parent)
{
    m_rectangleCounter++;

    QString name = jsonObj["name"].toString();
    qreal x = jsonObj["x"].toDouble();
    qreal y = jsonObj["y"].toDouble();
    qreal z = jsonObj["z"].toDouble();
    qreal width = jsonObj["width"].toDouble();
    qreal height = jsonObj["height"].toDouble();
    QString fillColor = jsonObj["fillColor"].toString();
    QString lineColor = jsonObj["lineColor"].toString();

    createFromParameters(name, x, y, z, width, height, QColor(fillColor), QColor(lineColor));
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
Rectangle::~Rectangle()
{
    if(m_graphicsRect) delete m_graphicsRect;
}





/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
void Rectangle::createFromParameters(QString name, qreal x, qreal y, qreal z,
                     qreal width, qreal height, QColor fillColor, QColor lineColor)
{
    m_name = name;

    // creating graphics item
    m_graphicsRect = new QGraphicsRectItem(x, y, width, height) ;
    if(!m_graphicsRect) {
        qDebug() << "WARNING! Creating graphicsItem (QGraphicsRectItem) failed!";
        return;
    }

    // setting z
    m_graphicsRect->setZValue(z);

    // setting colors
    m_graphicsRect->setBrush(QBrush(fillColor));
    m_graphicsRect->setPen(QPen(lineColor));

    // setting flags
    m_graphicsRect->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

}





/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
QGraphicsItem *Rectangle::graphicsItem() const
{
    return m_graphicsRect;
}


/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2016-01-11
 * added z-value
 * @version 0.1
 * @date 2015-10-24
 */
QString Rectangle::toString()
{
    return "Rectangle: " + m_name
            + " x: " + QString::number(m_graphicsRect->rect().x())
            + " y: " + QString::number(m_graphicsRect->rect().y())
            + " z: " + QString::number(m_graphicsRect->zValue())
            + " width: " + QString::number(m_graphicsRect->rect().width())
            + " height: " + QString::number(m_graphicsRect->rect().height())
            + " fill color: " + m_graphicsRect->brush().color().name()
            + " line color: " + m_graphicsRect->pen().color().name();
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-10
 */
QJsonObject Rectangle::toJson()
{
    QJsonObject jsonObj;
    jsonObj["type"] = "Rectangle";
    jsonObj["name"] = m_name;
    jsonObj["x"] = m_graphicsRect->rect().x();
    jsonObj["y"] = m_graphicsRect->rect().y();
    jsonObj["z"] = m_graphicsRect->zValue();
    jsonObj["width"] = m_graphicsRect->rect().width();
    jsonObj["height"] = m_graphicsRect->rect().height();
    jsonObj["fillColor"] = m_graphicsRect->brush().color().name(QColor::HexArgb);
    jsonObj["lineColor"] = m_graphicsRect->pen().color().name(QColor::HexArgb);

    return jsonObj;
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
void Rectangle::setX(qreal x)
{
    QRectF rect = m_graphicsRect->rect();
    qreal oldWidth = rect.width();
    rect.setX(x);
    rect.setWidth(oldWidth);
    m_graphicsRect->setRect(rect);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
void Rectangle::setY(qreal y)
{
    QRectF rect = m_graphicsRect->rect();
    qreal oldHeight = rect.height();
    rect.setY(y);
    rect.setHeight(oldHeight);
    m_graphicsRect->setRect(rect);
}

void Rectangle::setZ(qreal z)
{
    m_graphicsRect->setZValue(z);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
void Rectangle::setWidth(qreal width)
{
    QRectF rect = m_graphicsRect->rect();
    rect.setWidth(width);
    m_graphicsRect->setRect(rect);
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
void Rectangle::setHeight(qreal height)
{
    QRectF rect = m_graphicsRect->rect();
    rect.setHeight(height);
    m_graphicsRect->setRect(rect);
}
