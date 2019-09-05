#ifndef DRAWINGTOOLSELECTOR_H
#define DRAWINGTOOLSELECTOR_H

#include <QWidget>
#include "drawingoptions.h"

namespace Ui {
class DrawingToolSelector;
}

/**
 * @brief The DrawingToolSelector class is a new widget type which displays
 * buttons for the drawing tools
 */
class DrawingToolSelector : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief create a new object
     */
    explicit DrawingToolSelector(QWidget *parent = nullptr);
    ~DrawingToolSelector();

    /**
     * @brief returns the active drawing tool
     * @return active drawing tool
     */
    DrawingOptions::DrawingTool activeDrawingTool() const;

public slots:
    /**
     * @brief set a new active drawing tool
     * @param new active drawing tool
     */
    void setActiveDrawingTool(const DrawingOptions::DrawingTool &activeDrawingTool);

signals:
    /**
     * @brief indicates that the drawing tool has changed
     * @param new active drawing tool
     */
    void activeDrawingToolChanged(DrawingOptions::DrawingTool activeDrawingTool);

protected:
    DrawingOptions::DrawingTool m_activeDrawingTool;        ///< active drawing tool

private slots:
    void on_selectButton_clicked();

    void on_rectangleButton_clicked();

    void on_circleButton_clicked();

private:
    Ui::DrawingToolSelector *ui;
};

#endif // DRAWINGTOOLSELECTOR_H
