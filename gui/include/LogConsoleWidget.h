#pragma once

#include <QWidget>

namespace Ui
{
    class LogConsoleWidget;
}

class LogConsoleWidget : public QWidget
{
Q_OBJECT

public:
    explicit LogConsoleWidget(QWidget* _parent = nullptr);

private:
    Ui::LogConsoleWidget* ui;
};
