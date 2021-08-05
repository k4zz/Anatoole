#include "SettingsWidget.h"

#include "ui_SettingsWidget.h"

SettingsWidget::SettingsWidget(QWidget* _parent)
: QWidget(_parent)
, ui(new Ui::SettingsWidget)
{
    ui->setupUi(this);
}