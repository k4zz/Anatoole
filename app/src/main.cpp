#include <QApplication>

#include "version.h"

#include "Controller.h"
#include "Logger.h"
#include "ProtocolParser.h"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);

    Logger::instance();
    Controller::instance();

    MainWindow* mainWindow = new MainWindow();
    Controller::instance().setGUIComponent(mainWindow);

    ProtocolParser* protocolParser = new ProtocolParser();
    Controller::instance().setParserProtocolComponent(protocolParser);

    ProtocolParser* collationParser = new ProtocolParser();
    Controller::instance().setParserCollationComponent(collationParser);

    mainWindow->show();
    app.exec();

    return 0;
}