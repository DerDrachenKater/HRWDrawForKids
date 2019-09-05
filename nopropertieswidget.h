#ifndef NOPROPERTIES_H
#define NOPROPERTIES_H

#include "graphicsobjectpropertieswidget.h"

#include <QWidget>

namespace Ui {
class NoPropertiesWidget;
}

class NoPropertiesWidget : public GraphicsObjectPropertiesWidget
{
    Q_OBJECT

public:
    explicit NoPropertiesWidget(QWidget *parent = nullptr);
    ~NoPropertiesWidget();

private:
    Ui::NoPropertiesWidget *ui;
};

#endif // NOPROPERTIES_H
