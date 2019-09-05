#include "circlepropertieswidget.h"
#include "ui_circlepropertieswidget.h"

#include "circle.h"

#include <QDebug>

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
CirclePropertiesWidget::CirclePropertiesWidget(QWidget *parent) :
    GraphicsObjectPropertiesWidget(parent),
    ui(new Ui::CirclePropertiesWidget)
{
    ui->setupUi(this);
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
CirclePropertiesWidget::~CirclePropertiesWidget()
{
    delete ui;
}




/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
int CirclePropertiesWidget::radius() const
{
    return m_radius;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void CirclePropertiesWidget::setRadius(int radius)
{
    if(m_radius != radius) {
        m_radius = radius;
        emit propertiesChanged(this);
    }
}





/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2016-01-11
 * added z-value
 * @version 0.1
 * @date 2015-11-23
 */
void CirclePropertiesWidget::setProperties(int x, int y, int z, int radius, QString name)
{
    setX(x);
    setY(y);
    setZ(z);
    setRadius(radius);
    setName(name);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void CirclePropertiesWidget::setRelatedGraphicsObject(GraphicsObject *relatedGraphicsObject)
{
    GraphicsObjectPropertiesWidget::setRelatedGraphicsObject(relatedGraphicsObject);

    if(m_relatedGraphicsObject->inherits("Circle")) {
        Circle *relatedCircle = (Circle *)m_relatedGraphicsObject;
        ui->nameEdit->setText(relatedCircle->name());

        QGraphicsEllipseItem *ge = (QGraphicsEllipseItem *)m_relatedGraphicsObject->graphicsItem();
        ui->xSpinner->setValue(ge->rect().x() + ge->rect().width()/2);
        ui->ySpinner->setValue(ge->rect().y() + ge->rect().width()/2);
        ui->zSpinner->setValue(ge->zValue());
        ui->radiusSpinner->setValue(ge->rect().width()/2);
    }
    else {
        qDebug() << "ERROR: calling RectanglePropertiesWidget with non-Rectangle";
    }
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void CirclePropertiesWidget::on_nameEdit_editingFinished()
{
    m_relatedGraphicsObject->setName(ui->nameEdit->text());
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void CirclePropertiesWidget::on_xSpinner_valueChanged(int arg1)
{
    ((Circle *)m_relatedGraphicsObject)->setX(ui->xSpinner->value());
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void CirclePropertiesWidget::on_ySpinner_valueChanged(int arg1)
{
    ((Circle *)m_relatedGraphicsObject)->setY(ui->ySpinner->value());
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
void CirclePropertiesWidget::on_zSpinner_valueChanged(int arg1)
{
    ((Circle *)m_relatedGraphicsObject)->setZ(ui->zSpinner->value());
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void CirclePropertiesWidget::on_radiusSpinner_valueChanged(int arg1)
{
    ((Circle *)m_relatedGraphicsObject)->setRadius(ui->radiusSpinner->value());
}
