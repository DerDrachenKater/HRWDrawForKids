#ifndef PROPERTYWIDGET_H
#define PROPERTYWIDGET_H

#include "graphicsobject.h"
#include "graphicsobjectpropertieswidget.h"

#include <QWidget>

namespace Ui {
class PropertyWidget;
}

class PropertyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PropertyWidget(QWidget *parent = nullptr);
    ~PropertyWidget();


    /**
     * @brief Enum to define constants for the different views
     */
    enum PropertyViews {
        NoPropertyView = 0,

        RectanglePropertyView = 100,

        CirclePropertyView = 200
    };


    PropertyViews activeView() const;

    GraphicsObject *relatedGraphicsObject() const;


public slots:
    void setActiveView(const PropertyWidget::PropertyViews &activeView);
    void setRelatedGraphicsObject(GraphicsObject *relatedGraphicsObject);

protected:
    PropertyViews m_activeView;
    GraphicsObjectPropertiesWidget *m_activeViewWidget;
    GraphicsObject *m_relatedGraphicsObject;

private:
    Ui::PropertyWidget *ui;
};

#endif // PROPERTYWIDGET_H
