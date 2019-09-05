#include "graphicsobjectpropertieswidget.h"
#include "ui_graphicsobjectpropertieswidget.h"



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
GraphicsObjectPropertiesWidget::GraphicsObjectPropertiesWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphicsObjectPropertiesWidget)
{
    ui->setupUi(this);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
GraphicsObjectPropertiesWidget::~GraphicsObjectPropertiesWidget()
{
    delete ui;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
GraphicsObject *GraphicsObjectPropertiesWidget::relatedGraphicsObject() const
{
    return m_relatedGraphicsObject;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
void GraphicsObjectPropertiesWidget::setRelatedGraphicsObject(GraphicsObject *relatedGraphicsObject)
{
    m_relatedGraphicsObject = relatedGraphicsObject;
}




/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
int GraphicsObjectPropertiesWidget::x() const
{
    return m_x;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
void GraphicsObjectPropertiesWidget::setX(int x)
{
    if(m_x != x) {
        m_x = x;
        emit propertiesChanged(this);
    }
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
int GraphicsObjectPropertiesWidget::y() const
{
    return m_y;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
void GraphicsObjectPropertiesWidget::setY(int y)
{
    if(m_y != y) {
        m_y = y;
        emit propertiesChanged(this);
    }
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
int GraphicsObjectPropertiesWidget::z() const
{
    return m_z;
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
void GraphicsObjectPropertiesWidget::setZ(int z)
{
    if(m_z != z) {
        m_z = z;
        emit propertiesChanged(this);
    }
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
QString GraphicsObjectPropertiesWidget::name() const
{
    return m_name;
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
void GraphicsObjectPropertiesWidget::setName(const QString &name)
{
    if(m_name.compare(name) != 0) {
        m_name = name;
        emit propertiesChanged(this);
    }
}
