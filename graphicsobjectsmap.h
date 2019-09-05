#ifndef GRAPHICSOBJECTSMAP_H
#define GRAPHICSOBJECTSMAP_H

#include <QGraphicsItem>
#include <QJsonArray>
#include "graphicsobject.h"

/**
 * @brief The GraphicsObjectMap class stores all graphic objects
 * The QGraphicsItem is the key so that it can be used to search the
 * map for the GraphicsObject object pointer. This will be helpfull
 * when an object will be clicked in the graphics view
 */
class GraphicsObjectsMap : public QMap<QGraphicsItem *, GraphicsObject *>
{
public:
    /**
     * @brief create a new empty GraphicsObjectMap object
     * @see QMap documentation for more details
     */
    GraphicsObjectsMap();


    /**
     * @brief create a new GraphicsObjectMap with objects from JSON object array
     * @param jsonArray array of JSON objects that hold the data for the graphic objects
     * @param parent object (see QObject documentation)
     */
    explicit GraphicsObjectsMap(const QJsonArray &jsonArray, QObject *parent = nullptr);


    /**
     * @brief create a JSON-object with all information about the object
     * @return JSON-object
     */
    virtual QJsonArray toJson();



};

#endif // GRAPHICSOBJECTSMAP_H
