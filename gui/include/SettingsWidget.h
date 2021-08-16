#pragma once

#include <QWidget>

namespace Ui
{
    class SettingsWidget;
}

struct Settings
{
    int protocolKeyColumn;
    int protocolValueColumn;
    int collationKeyColumn;
    int collationValueColumn;
};

class SettingsWidget : public QWidget
{
Q_OBJECT

public:
    explicit SettingsWidget(QWidget* _parent = nullptr);
    Settings getSettings() const;

private:
    Ui::SettingsWidget* ui;
};
