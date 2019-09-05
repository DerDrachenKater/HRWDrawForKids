#include "rectanglepropertieswidget.h"
#include "ui_rectanglepropertieswidget.h"

#include <QDebug>

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
RectanglePropertiesWidget::RectanglePropertiesWidget(QWidget *parent) :
    GraphicsObjectPropertiesWidget(parent),
    ui(new Ui::RectanglePropertiesWidget)
{
    ui->setupUi(this);
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
RectanglePropertiesWidget::~RectanglePropertiesWidget()
{
    delete ui;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
int RectanglePropertiesWidget::width() const
{
    return m_width;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void RectanglePropertiesWidget::setWidth(int width)
{
    if(m_width != width) {
        m_width = width;
        emit propertiesChanged(this);
    }
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
int RectanglePropertiesWidget::height() const
{
    return m_height;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void RectanglePropertiesWidget::setHeight(int height)
{
    if(m_height != height) {
        m_height = height;
        emit propertiesChanged(this);
    }
}






/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2016-01-11
 * added z-value
 * @version 0.1
 * @date 2015-12-06
 */
void RectanglePropertiesWidget::setProperties(int x, int y, int z, int width, int height, QString name)
{
    setX(x);
    setY(y);
    setZ(z);
    setWidth(width);
    setHeight(height);
    setName(name);
}


/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2016-01-11
 * added z-value
 * @version 0.1
 * @date 2015-12-06
 */
void RectanglePropertiesWidget::setRelatedGraphicsObject(GraphicsObject *relatedGraphicsObject)
{
    GraphicsObjectPropertiesWidget::setRelatedGraphicsObject(relatedGraphicsObject);

    if(m_relatedGraphicsObject->inherits("Rectangle")) {
        Rectangle *relatedRectangle = (Rectangle *)m_relatedGraphicsObject;
        ui->nameEdit->setText(relatedRectangle->name());

        QGraphicsRectItem *gr = (QGraphicsRectItem *)m_relatedGraphicsObject->graphicsItem();
        ui->xSpinner->setValue(gr->rect().x());
        ui->ySpinner->setValue(gr->rect().y());
        ui->zSpinner->setValue(gr->zValue());
        ui->widthSpinner->setValue(gr->rect().width());
        ui->heightSpinner->setValue(gr->rect().height());
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
void RectanglePropertiesWidget::on_nameEdit_editingFinished()
{
    m_relatedGraphicsObject->setName(ui->nameEdit->text());
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void RectanglePropertiesWidget::on_xSpinner_valueChanged(int arg1)
{
    ((Rectangle *)m_relatedGraphicsObject)->setX(ui->xSpinner->value());
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void RectanglePropertiesWidget::on_ySpinner_valueChanged(int arg1)
{
    ((Rectangle *)m_relatedGraphicsObject)->setY(ui->ySpinner->value());
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2016-01-11
 */
void RectanglePropertiesWidget::on_zSpinner_valueChanged(int arg1)
{
    ((Rectangle *)m_relatedGraphicsObject)->setZ(ui->zSpinner->value());
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void RectanglePropertiesWidget::on_widthSpinner_valueChanged(int arg1)
{
    ((Rectangle *)m_relatedGraphicsObject)->setWidth(ui->widthSpinner->value());
}


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-06
 */
void RectanglePropertiesWidget::on_heightSpinner_valueChanged(int arg1)
{
    ((Rectangle *)m_relatedGraphicsObject)->setHeight(ui->heightSpinner->value());
}


