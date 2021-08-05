#include "PathsWidget.h"

#include "ui_PathsWidget.h"

PathsWidget::PathsWidget(QWidget* _parent)
        : QWidget(_parent)
        , ui(new Ui::PathsWidget)
{
    ui->setupUi(this);
}