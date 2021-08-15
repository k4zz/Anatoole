#include <QApplication>

#include "MainWindow.h"

#include "Controller.h"
#include "ConsoleLogger.h"

#include "version.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);

    //auto consoleLogger = ConsoleLogger();
    auto controller = std::make_shared<Controller>();
    auto mainWindow = new MainWindow(controller);
    mainWindow->show();

    LOG_INFO(std::string(PROJECT_NAME) + " v" + std::string(PROJECT_VERSION) + " " +
             getenv("USERNAME") + "@" + QSysInfo::machineHostName().toStdString() +
             "(" + QSysInfo::prettyProductName().toStdString() + ")");

    QApplication::exec();

    return 0;
}