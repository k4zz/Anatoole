#include "MainWindow.h"

#include "ui_MainWindow.h"

#include "PathsWidget.h"
#include "LogConsoleWidget.h"
#include "SettingsWidget.h"

#include <QPushButton>

MainWindow::MainWindow(std::shared_ptr<Controller> _controller, QWidget* _parent)
        : QMainWindow(_parent)
        , ui(new Ui::MainWindow)
        , UIInterface(_controller)
{
    ui->setupUi(this);
    auto windowTitle = QString(QCoreApplication::applicationName() + " v" + QCoreApplication::applicationVersion());
    setWindowTitle(windowTitle);

    auto* pathsWidget = new PathsWidget(this);
    auto* settingsWidget = new SettingsWidget(this);
    auto btnAnalyze = new QPushButton("Analizuj", this);
    auto* logConsoleWidget = new LogConsoleWidget(this);

    connect(btnAnalyze, &QPushButton::clicked, [=]() {
        auto paths = pathsWidget->getPath();
        mController->setPaths(paths.first, paths.second);
        auto settings = settingsWidget->getSettings();
        mController->setSettings(settings.protocolKeyColumn,
                                 settings.protocolValueColumn,
                                 settings.collationKeyColumn,
                                 settings.collationValueColumn);
        mController->execute();
    });

    ui->leftPanel->addWidget(pathsWidget);
    ui->leftPanel->addWidget(btnAnalyze);
    ui->leftPanel->addWidget(settingsWidget);
    ui->leftPanel->addStretch();
    ui->rightPanel->addWidget(logConsoleWidget);
}