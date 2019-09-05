#include "drawingoptions.h"

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
DrawingOptions::DrawingOptions(QObject *parent) : QObject(parent)
{

}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
DrawingOptions::DrawingTool DrawingOptions::getActiveDrawingTool() const
{
    return m_activeDrawingTool;
}

/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2015-11-23
 * Prepared for signal/slot-robustness:
 * only work if new value differs from current value
 * emit signal on data change
 * @version 0.1
 * @date 2015-10-24
 */
void DrawingOptions::setActiveDrawingTool(const DrawingOptions::DrawingTool &value)
{
    if(m_activeDrawingTool != value) {
        m_activeDrawingTool = value;
        emit activeDrawingToolChanged(m_activeDrawingTool);
        emit drawingOptionsChanged(this);
    }
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
QColor DrawingOptions::activeFillColor() const
{
    return m_activeFillColor;
}

/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2015-11-23
 * Prepared for signal/slot-robustness:
 * only work if new value differs from current value
 * emit signal on data change
 * @version 0.1
 * @date 2015-10-24
 */
void DrawingOptions::setActiveFillColor(const QColor &value)
{
    if(m_activeFillColor != value) {
        m_activeFillColor = value;
        emit activeFillColorChanged(m_activeFillColor);
        emit drawingOptionsChanged(this);
    }
}

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-10-24
 */
QColor DrawingOptions::activeLineColor() const
{
    return m_activeLineColor;
}

/**
 * @author Mario Breitenbach
 * @version 0.2
 * @date 2015-11-23
 * Prepared for signal/slot-robustness:
 * only work if new value differs from current value
 * emit signal on data change
 * @version 0.1
 * @date 2015-10-24
 */
void DrawingOptions::setActiveLineColor(const QColor &value)
{
    if(m_activeLineColor != value) {
        m_activeLineColor = value;
        emit activeLineColorChanged(m_activeLineColor);
        emit drawingOptionsChanged(this);
    }
}



