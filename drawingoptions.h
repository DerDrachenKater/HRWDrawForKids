#ifndef DRAWINGOPTIONS_H
#define DRAWINGOPTIONS_H

#include <QObject>
#include <QColor>

class DrawingOptions : public QObject
{
    Q_OBJECT
public:

    /**
     * @brief create a new object for the drawing options
     */
    explicit DrawingOptions(QObject *parent = nullptr);


    /**
     * @brief Enum to define constants for the drawing tools
     */
    enum DrawingTool {
        NoTool = 0,

        SelectTool = 100,

        DrawRectangleTool = 200,

        DrawCircleTool = 300
    };


    /**
     * @brief returns the active drawing tool
     * @return active drawing tool
     */
    DrawingTool getActiveDrawingTool() const;

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
    void activeDrawingToolChanged(DrawingOptions::DrawingTool activeDrawingTool);
    void activeFillColorChanged(QColor activeFillColor);
    void activeLineColorChanged(QColor activeLineColor);
    void drawingOptionsChanged(DrawingOptions *drawingOptions);


public slots:

    /**
     * @brief sets a new drawing tool
     * @param value the new tool, should be from DrawingTool enum
     */
    void setActiveDrawingTool(const DrawingOptions::DrawingTool &value);

    /**
     * @brief sets a new fill color
     * @param value of new fill color
     */
    void setActiveFillColor(const QColor &value);

    /**
     * @brief sets a new line color
     * @param value of new line color
     */
    void setActiveLineColor(const QColor &value);


protected:
    DrawingTool m_activeDrawingTool;    ///< active drawing tool
    QColor m_activeFillColor;           ///< active fill color
    QColor m_activeLineColor;           ///< active line color
};

#endif // DRAWINGOPTIONS_H
