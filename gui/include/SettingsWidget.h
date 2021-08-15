#pragma once

#include <QWidget>

namespace Ui
{
    class SettingsWidget;
}

struct Settings
{
    int _protocolKeyColumn;
    int _protocolValueColumn;
    int _collationKeyColumn;
    int _collationValueColumn;
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
