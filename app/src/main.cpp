#include <QApplication>

#include "MainWindow.h"

#include "version.h"
#include "CollationParser.h"
#include "ProtocolParser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);


    MainWindow* mainWindow = new MainWindow();
    mainWindow->show();
    CollationParser collationParser;
    ProtocolParser protocolParser;

    collationParser.parse("F:/collation.csv");
    protocolParser.parse("F:/protocol.csv");

    auto num = collationParser.getEntries();

    app.exec();

    return 0;
}