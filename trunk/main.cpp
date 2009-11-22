#include <QtGui/QApplication>
#include "MainWindow.h"
#include "SerialPort.h"

using namespace std;

int main( int argc, char **argv )
{
    QApplication app( argc, argv );

    // Before doing anything else, enumerate Serial ports
    SerialPort::getInstance();

    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();

    int rc = app.exec();

    SerialPort::removeInstance();
    delete mainWindow;
    return rc;
}
