#pragma once

#include "Logger.h"

#include <QWidget>

namespace Ui
{
    class LogConsoleWidget;
}

class LogConsoleWidget : public QWidget, ILoggerObserver
{
Q_OBJECT

public:
    explicit LogConsoleWidget(QWidget* _parent = nullptr);
    void log(const std::string& _msg, LogLevel _level) override;

private:
    Ui::LogConsoleWidget* ui;

private slots:
    void onClearButtonClicked();
};
