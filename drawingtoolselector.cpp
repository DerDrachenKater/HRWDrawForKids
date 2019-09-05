#include "drawingtoolselector.h"
#include "ui_drawingtoolselector.h"



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
DrawingToolSelector::DrawingToolSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DrawingToolSelector),
    m_activeDrawingTool(DrawingOptions::NoTool)
{
    ui->setupUi(this);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
DrawingToolSelector::~DrawingToolSelector()
{
    delete ui;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
DrawingOptions::DrawingTool DrawingToolSelector::activeDrawingTool() const
{
    return m_activeDrawingTool;
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void DrawingToolSelector::setActiveDrawingTool(const DrawingOptions::DrawingTool &activeDrawingTool)
{
    if(m_activeDrawingTool != activeDrawingTool) {

        ui->selectButton->setChecked(false);
        ui->rectangleButton->setChecked(false);
        ui->circleButton->setChecked(false);
        switch(activeDrawingTool) {
            case DrawingOptions::SelectTool: ui->selectButton->setChecked(true); break;
            case DrawingOptions::DrawRectangleTool: ui->rectangleButton->setChecked(true); break;
            case DrawingOptions::DrawCircleTool: ui->circleButton->setChecked(true); break;
            default: break;
        }

        m_activeDrawingTool = activeDrawingTool;
        emit activeDrawingToolChanged(m_activeDrawingTool);
    }
}




/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void DrawingToolSelector::on_selectButton_clicked()
{
    m_activeDrawingTool = DrawingOptions::SelectTool;
    emit activeDrawingToolChanged(m_activeDrawingTool);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void DrawingToolSelector::on_rectangleButton_clicked()
{
    m_activeDrawingTool = DrawingOptions::DrawRectangleTool;
    emit activeDrawingToolChanged(m_activeDrawingTool);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-11-23
 */
void DrawingToolSelector::on_circleButton_clicked()
{
    m_activeDrawingTool = DrawingOptions::DrawCircleTool;
    emit activeDrawingToolChanged(m_activeDrawingTool);
}
