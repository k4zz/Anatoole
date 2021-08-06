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
    auto btnAnalyze = new QPushButton("Analizuj", this);
    auto* logConsoleWidget = new LogConsoleWidget(this);

    LOG_DEBUG(windowTitle.toStdString() + " " +
              getenv("USERNAME") + "@" + QSysInfo::machineHostName().toStdString() +
              "(" + QSysInfo::prettyProductName().toStdString() + ")");

    ui->leftPanel->addWidget(pathsWidget);
    ui->leftPanel->addWidget(btnAnalyze);
    ui->leftPanel->addWidget(settingsWidget);
    ui->leftPanel->addStretch();
    ui->rightPanel->addWidget(logConsoleWidget);
}
