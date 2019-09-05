#ifndef GRAPHICSOBJECT_H
#define GRAPHICSOBJECT_H

#include <QObject>
#include <QString>
#include <QGraphicsItem>
#include <QJsonObject>




/**
 * @brief The GraphicsObject class is the base class for all graphic objects
 * The current version only contains a name and a counter
 */
class GraphicsObject : public QObject
{
    Q_OBJECT

public:

    /**
     * @brief create a new GraphicsObject object
     * @param parent object (see QObject documentation)
     */
    explicit GraphicsObject(QObject *parent = nullptr);

    /**
     * @brief create a new graphic object from JSON object
     * @param jsonObject JSON object that holds the data for the object
     * @param parent object (see QObject documentation)
     */
    explicit GraphicsObject(const QJsonObject &jsonObj, QObject *parent = nullptr);

    /**
     * @brief destructor. Destroys the QGraphicsItem object
     */
    ~GraphicsObject();

    /**
     * @brief returns the user definable name of the object
     * @return name
     */
    QString name() const;

    /**
     * @brief returns the corresponding QGraphicsItem object
     * @return name
     */
    virtual QGraphicsItem *graphicsItem() const;

    /**
     * @brief create a string with selected information about the object
     * type, name
     * @return string with selected information about the object
     */
    virtual QString toString();

    /**
     * @brief create a JSON-object with all information about the object
     * @return JSON-object
     */
    virtual QJsonObject toJson();

public slots:
    /**
     * @brief sets a new name for the object
     * @param new name
     */
    void setName(const QString &name);



signals:
    void nameChanged(QString name);

protected:
    QString m_name;                                 ///< user definable name for the object
    static unsigned long m_graphicsObjectCounter;   ///< counter for number for of graphics objects created so far (class member)
    QGraphicsItem *m_graphicsItem;                  ///< the Qt Graphics Object for drawing in a QGraphicsScene


};

#endif // GRAPHICSOBJECT_H
