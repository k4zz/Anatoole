#include "LogConsoleWidget.h"

#include "ui_LogConsoleWidget.h"

LogConsoleWidget::LogConsoleWidget(QWidget* _parent)
        : QWidget(_parent)
        , ui(new Ui::LogConsoleWidget)
{
    ui->setupUi(this);
}
