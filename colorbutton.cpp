#include "colorbutton.h"
#include <QPainter>
#include <QString>
#include <QDebug>


/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-31
 */
ColorButton::ColorButton(QWidget *parent) :
    QPushButton(parent),
    m_color(Qt::blue)
{

}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-31
 */
ColorButton::ColorButton(QColor color, QWidget *parent) :
    QPushButton(parent),
    m_color(color)
{

}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-31
 */
QColor ColorButton::color() const
{
    return m_color;
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-31
 */
void ColorButton::setColor(const QColor &color)
{
    m_color = color;
    repaint();
}




/**
 * Paint event of button
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-31
 */
void ColorButton::paintEvent(QPaintEvent *paint)
{
    // paint standard look of button
    QPushButton::paintEvent(paint);

    // Start the own painting...
    QPainter p(this);
    p.save();

    // Draw the rectangle border in black
    p.setPen(Qt::black);
    p.drawRect(10, 10, width()-20, height()-20);

    // Draw the rectangle with user defined fill color
    p.fillRect(11, 11, width()-21, height()-21, m_color);

    // finished...
    p.restore();
}
