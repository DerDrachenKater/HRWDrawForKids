#include "nopropertieswidget.h"
#include "ui_nopropertieswidget.h"

/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
NoPropertiesWidget::NoPropertiesWidget(QWidget *parent) :
    GraphicsObjectPropertiesWidget(parent),
    ui(new Ui::NoPropertiesWidget)
{
    ui->setupUi(this);
}



/**
 * @author Mario Breitenbach
 * @version 0.1
 * @date 2015-12-05
 */
NoPropertiesWidget::~NoPropertiesWidget()
{
    delete ui;
}
