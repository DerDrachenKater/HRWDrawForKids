#include "graphicsobjectsmap.h"
#include "rectangle.h"
#include "circle.h"


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
GraphicsObjectsMap::GraphicsObjectsMap()
{

}




/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
GraphicsObjectsMap::GraphicsObjectsMap(const QJsonArray &jsonArray, QObject *parent)
{
    foreach(QJsonValue jsonVal, jsonArray) {
        QJsonObject jsonObj = jsonVal.toObject();

        // create object depending on type
        if(jsonObj["type"] == "GraphicsObject") {
            GraphicsObject *g = new GraphicsObject(jsonObj);
            insert(g->graphicsItem(), g);
        }
        else if(jsonObj["type"] == "Rectangle") {
            Rectangle *r = new Rectangle(jsonObj);
            insert(r->graphicsItem(), r);
        }
        else if(jsonObj["type"] == "Circle") {
            Circle *c = new Circle(jsonObj);
            insert(c->graphicsItem(), c);
        }

    }
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-10
 */
QJsonArray GraphicsObjectsMap::toJson()
{
    QJsonArray jsonArray;
    foreach(GraphicsObject *go, *this) {
        jsonArray.append(go->toJson());
    }

    return jsonArray;
}

