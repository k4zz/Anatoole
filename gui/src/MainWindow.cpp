#include "MainWindow.h"

#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget* _parent)
        : QMainWindow(_parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
