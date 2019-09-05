#include "propertywidget.h"
#include "ui_propertywidget.h"

#include "nopropertieswidget.h"
#include "rectanglepropertieswidget.h"
#include "circlepropertieswidget.h"



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
PropertyWidget::PropertyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PropertyWidget),
    m_activeView(PropertyWidget::NoPropertyView),
    m_relatedGraphicsObject(NULL)
{
    ui->setupUi(this);

    m_activeViewWidget = new NoPropertiesWidget(this);
    ui->verticalLayout->addWidget(m_activeViewWidget);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
PropertyWidget::~PropertyWidget()
{
    delete ui;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
PropertyWidget::PropertyViews PropertyWidget::activeView() const
{
    return m_activeView;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
void PropertyWidget::setActiveView(const PropertyWidget::PropertyViews &activeView)
{
    if(activeView != m_activeView) {
        m_activeView = activeView;

        // delete current widget
        ui->verticalLayout->removeWidget(m_activeViewWidget);
        m_activeViewWidget->deleteLater();

        // create new widget
        if(m_activeView == RectanglePropertyView) {
            m_activeViewWidget = new RectanglePropertiesWidget(this);
        }
        else if(m_activeView == CirclePropertyView) {
            m_activeViewWidget = new CirclePropertiesWidget(this);
        }
        else {
            m_activeViewWidget = new NoPropertiesWidget(this);
        }
        ui->verticalLayout->addWidget(m_activeViewWidget);
    }
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
GraphicsObject *PropertyWidget::relatedGraphicsObject() const
{
    return m_relatedGraphicsObject;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
void PropertyWidget::setRelatedGraphicsObject(GraphicsObject *relatedGraphicsObject)
{
    m_relatedGraphicsObject = relatedGraphicsObject;

    m_activeViewWidget->setRelatedGraphicsObject(m_relatedGraphicsObject);
}



