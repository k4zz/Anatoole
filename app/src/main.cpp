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

    auto* mainWindow = new MainWindow();
    mainWindow->show();

    QApplication::exec();

    return 0;
}