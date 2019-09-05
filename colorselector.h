#ifndef COLORSELECTOR_H
#define COLORSELECTOR_H

#include <QWidget>
#include <QColor>

namespace Ui {
class ColorSelector;
}

/**
 * @brief The ColorSelector class is a new widget type which displays
 * two ColorButtons, one for fill, the other for line color
 */
class ColorSelector : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief create a new object
     */
    explicit ColorSelector(QWidget *parent = nullptr);
    ~ColorSelector();

    /**
     * @brief returns the active fill color
     * @return active fill color
     */
    QColor activeFillColor() const;

    /**
     * @brief returns the active line color
     * @return active line color
     */
    QColor activeLineColor() const;

signals:

    /**
     * @brief indicates that the fill color has changed
     * @param new active fill color
     */
    void activeFillColorChanged(QColor activeFillColor);

    /**
     * @brief indicates that the line color has changed
     * @param new active line color
     */
    void activeLineColorChanged(QColor activeLineColor);


public slots:
    /**
     * @brief set a new fill color
     * @param new active fill color
     */
    void setActiveFillColor(const QColor &activeFillColor);

    /**
     * @brief set a new line color
     * @param new active line color
     */
    void setActiveLineColor(const QColor &activeLineColor);

protected:
    QColor m_activeFillColor;           ///< active fill color
    QColor m_activeLineColor;           ///< active line color


private slots:
    void on_fillColorButton_clicked();
    void on_lineColorButton_clicked();

private:
    Ui::ColorSelector *ui;


};

#endif // COLORSELECTOR_H
