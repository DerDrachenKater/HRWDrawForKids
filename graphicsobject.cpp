#include "graphicsobject.h"
#include <QDebug>



/**
 * @brief class member which stores the number of created graphics objects
 *
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
unsigned long GraphicsObject::m_graphicsObjectCounter = 0;





/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
GraphicsObject::GraphicsObject(QObject *parent) : QObject(parent)
{
    //creating automatic name for object
    m_graphicsObjectCounter++;
    m_name = QString("graphic_object_%1").arg(m_graphicsObjectCounter);

    // creating graphics item
    m_graphicsItem = NULL;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
GraphicsObject::GraphicsObject(const QJsonObject &jsonObj, QObject *parent)
{
    m_name = jsonObj["name"].toString();

    // creating graphics item
    m_graphicsItem = NULL;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
GraphicsObject::~GraphicsObject()
{
    if(m_graphicsItem) delete m_graphicsItem;
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
QString GraphicsObject::name() const
{
    return m_name;
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
void GraphicsObject::setName(const QString &name)
{
    if(m_name != name) {
        m_name = name;
        emit nameChanged(m_name);

        qDebug() << "GraphicsObject: Setting name to: " << name;
    }
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
QGraphicsItem *GraphicsObject::graphicsItem() const
{
    return m_graphicsItem;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
QString GraphicsObject::toString()
{
    return "GraphicsObject: " + m_name;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-10
 */
QJsonObject GraphicsObject::toJson()
{
    QJsonObject jsonObj;
    jsonObj["type"] = "GraphicsObject";
    jsonObj["name"] = m_name;

    return jsonObj;
}

