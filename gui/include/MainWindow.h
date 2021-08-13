#pragma once

#include <QMainWindow>

class Controller;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);

private:
    Ui::MainWindow* ui;
};