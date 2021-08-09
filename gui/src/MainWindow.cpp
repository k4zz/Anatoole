#include "MainWindow.h"

#include "ui_MainWindow.h"

#include "PathsWidget.h"
#include "LogConsoleWidget.h"
#include "SettingsWidget.h"
#include "Settings.h"
#include "Controller.h"

#include <QPushButton>

MainWindow::MainWindow(QWidget* _parent)
        : QMainWindow(_parent)
        , ui(new Ui::MainWindow)
        , settings(new Settings)
{
    ui->setupUi(this);
    auto windowTitle = QString(QCoreApplication::applicationName() + " v" + QCoreApplication::applicationVersion());
    setWindowTitle(windowTitle);

    pathsWidget = new PathsWidget(this);
    settingsWidget = new SettingsWidget(this);
    auto btnAnalyze = new QPushButton("Analizuj", this);
    connect(btnAnalyze, &QPushButton::clicked, this, &MainWindow::onAnalyzeButtonClicked);
    auto* logConsoleWidget = new LogConsoleWidget(this);

    LOG_INFO(windowTitle.toStdString() + " " +
              getenv("USERNAME") + "@" + QSysInfo::machineHostName().toStdString() +
              "(" + QSysInfo::prettyProductName().toStdString() + ")");

    ui->leftPanel->addWidget(pathsWidget);
    ui->leftPanel->addWidget(btnAnalyze);
    ui->leftPanel->addWidget(settingsWidget);
    ui->leftPanel->addStretch();
    ui->rightPanel->addWidget(logConsoleWidget);
}

void MainWindow::onAnalyzeButtonClicked()
{
    if (this->mediator == nullptr)
    {
        LOG_ERROR("GUI has no connection with controller");
        return;
    }
    updateSettings();
    this->mediator->notify(this, Event::ANALYZE);
}

void MainWindow::updateSettings()
{
    Controller::instance().settings.protocolPath = pathsWidget->getProtocolPath();
    Controller::instance().settings.collationPath = pathsWidget->getCollationPath();
}
