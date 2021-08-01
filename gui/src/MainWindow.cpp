#include "MainWindow.h"

#include "ui_MainWindow.h"

#include "PathsWidget.h"
#include "LogConsoleWidget.h"
#include "SettingsWidget.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget* _parent)
        : QMainWindow(_parent)
        , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto windowTitle = QString(QCoreApplication::applicationName() + " v" + QCoreApplication::applicationVersion());
    setWindowTitle(windowTitle);

    auto* pathsWidget = new PathsWidget(this);
    auto* settingsWidget = new SettingsWidget(this);
    ui->leftPanel->addWidget(pathsWidget);
    ui->leftPanel->addWidget(new QPushButton("Analizuj", this));
    ui->leftPanel->addWidget(settingsWidget);
    ui->leftPanel->addStretch();

    auto* widget2 = new LogConsoleWidget(this);
    ui->rightPanel->addWidget(widget2);
}
