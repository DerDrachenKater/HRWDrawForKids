#ifndef GRAPHICSOBJECTPROPERTIESWIDGET_H
#define GRAPHICSOBJECTPROPERTIESWIDGET_H

#include "graphicsobject.h"

#include <QWidget>

namespace Ui {
class GraphicsObjectPropertiesWidget;
}

class GraphicsObjectPropertiesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphicsObjectPropertiesWidget(QWidget *parent = nullptr);
    ~GraphicsObjectPropertiesWidget();

    /**
     * @brief returns the name of the graphicsObject
     * @return name
     */
    virtual QString name() const;

    /**
     * @brief returns the x-position of the graphicsObject
     * @return x-position
     */
    virtual int x() const;

    /**
     * @brief returns the y-position of the graphicsObject
     * @return y-position
     */
    virtual int y() const;

    /**
     * @brief returns the z-value of the graphicsObject
     * @return z-value
     */
    virtual int z() const;

    /**
     * @brief returns the related graphicsObject
     * @return related graphicsObject
     */
    virtual GraphicsObject *relatedGraphicsObject() const;



public slots:
    /**
     * @brief sets a new x-position for the graphicsObject
     * @param new x-position
     */
    virtual void setX(int x);

    /**
     * @brief sets a new y-position for the graphicsObject
     * @param new y-position
     */
    virtual void setY(int y);

    /**
     * @brief sets a new z-value for the graphicsObject
     * @param new z-value
     */
    virtual void setZ(int z);


    /**
     * @brief sets a new name for the graphicsObject
     * @param new name
     */
    virtual void setName(const QString &name);


    /**
     * @brief sets a new related graphicsObject
     * @param graphicsObject
     */
    virtual void setRelatedGraphicsObject(GraphicsObject *relatedGraphicsObject);

signals:
    /**
     * @brief signal indicates that properties were changed
     * @param new properties
     */
    void propertiesChanged(GraphicsObjectPropertiesWidget *properties);


protected:
    QString m_name; ///< name of the graphicsObject
    int m_x;        ///< x-position of the graphicsObject
    int m_y;        ///< y-position of the graphicsObject
    int m_z;        ///< z-value of the graphicsObject

    GraphicsObject *m_relatedGraphicsObject;

private:
    Ui::GraphicsObjectPropertiesWidget *ui;


};

#endif // GRAPHICSOBJECTPROPERTIESWIDGET_H
