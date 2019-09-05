#include <QColorDialog>
#include "colorselector.h"
#include "ui_colorselector.h"


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
ColorSelector::ColorSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSelector)
{
    ui->setupUi(this);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
ColorSelector::~ColorSelector()
{
    delete ui;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
QColor ColorSelector::activeFillColor() const
{
    return m_activeFillColor;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void ColorSelector::setActiveFillColor(const QColor &activeFillColor)
{
    if(m_activeFillColor != activeFillColor) {
        m_activeFillColor = activeFillColor;
        ui->fillColorButton->setColor(m_activeFillColor);
        emit activeFillColorChanged(m_activeFillColor);
    }
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
QColor ColorSelector::activeLineColor() const
{
    return m_activeLineColor;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void ColorSelector::setActiveLineColor(const QColor &activeLineColor)
{
    if(m_activeLineColor != activeLineColor) {
        m_activeLineColor = activeLineColor;
        ui->lineColorButton->setColor(m_activeLineColor);
        emit activeLineColorChanged(m_activeLineColor);
    }
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void ColorSelector::on_fillColorButton_clicked()
{
    QColor newColor = QColorDialog::getColor(m_activeFillColor, this, "Select Fill Color", QColorDialog::ShowAlphaChannel);
    if(newColor.isValid()) {
        m_activeFillColor = newColor;
        ui->fillColorButton->setColor(m_activeFillColor);
        emit activeFillColorChanged(m_activeFillColor);
    }
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void ColorSelector::on_lineColorButton_clicked()
{
    QColor newColor = QColorDialog::getColor(m_activeLineColor, this, "Select Line Color", QColorDialog::ShowAlphaChannel);
    if(newColor.isValid()) {
        m_activeLineColor = newColor;
        ui->lineColorButton->setColor(m_activeLineColor);
        emit activeLineColorChanged(m_activeLineColor);
    }
}
