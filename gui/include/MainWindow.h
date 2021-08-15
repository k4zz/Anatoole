#pragma once

#include <QMainWindow>
#include "Controller.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow, public UIInterface
{
Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<Controller> _controller,QWidget* parent = nullptr);

private:
    Ui::MainWindow* ui;
};