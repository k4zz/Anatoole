#pragma once

#include <QWidget>

namespace Ui
{
    class SettingsWidget;
}

class SettingsWidget : public QWidget
{
Q_OBJECT

public:
    explicit SettingsWidget(QWidget* _parent = nullptr);

private:
    Ui::SettingsWidget* ui;
};
