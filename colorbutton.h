#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QPushButton>


/**
 * @brief The ColorButton class is a new button type which displays a
 * configurable colored rectangle in its center
 */
class ColorButton : public QPushButton
{
    Q_OBJECT
public:
    /**
     * @brief create a new ColorButton object with default color
     * @param parent object (see QObject documentation)
     */
    explicit ColorButton(QWidget *parent = nullptr);

    /**
     * @brief create a new ColorButton object with user selectable color
     * @param color initial color of the button
     * @param parent object (see QObject documentation)
     */
    explicit ColorButton(QColor color, QWidget *parent = nullptr);

    /**
     * @brief returns the current color of the button
     * @return current color
     */
    QColor color() const;

    /**
     * @brief sets the new color of the button and redraws the button
     * @param new color
     */
    void setColor(const QColor &color);

signals:

public slots:


protected:
    QColor m_color;     ///< current color of the button (class member)

    void paintEvent(QPaintEvent *);
};

#endif // COLORBUTTON_H
