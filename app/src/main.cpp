#include <QApplication>

#include "MainWindow.h"

#include "version.h"
#include "Parser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);


    MainWindow* mainWindow = new MainWindow();
    mainWindow->show();
    Parser parser("F:/collation.csv");
    app.exec();

    return 0;
}