#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QDebug>
#include <QtCore/QThread>
#include <QtCore/QMutex>
#include <QtGui/QMainWindow>
#include <QtGui/QFileDialog>
#include <sstream>
#include "ui_DebugWindow.h"
#include "SerialPortListener.h"
#include "PreferencesDialog.h"
#include "SettingsManager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QString m_WindowTitle;
    SerialPortListener *m_SerialPortListener;
    QMutex *m_DebugTextMutex;
    unsigned long m_DebugTextLines;
    SettingsManager *m_Settings;

    Ui::DebugMonitorMainWindow m_UserInterface;

    void setupUi();

protected:
    virtual void closeEvent( QCloseEvent *event ); // from QWidget
    void setWindowTitle();

public:
    MainWindow();
    ~MainWindow();

public slots:
    void appendMessage( const QString &message );    
    void shutdown();
    void saveDebugText();
    void showPreferences();
};

#endif // MAINWINDOW_H
