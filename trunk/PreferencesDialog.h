#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QtGui/QDialog>
#include "ui_PreferencesDialog.h"
#include "SettingsManager.h"
#include "SerialPort.h"

class PreferencesDialog : public QDialog
{
    Q_OBJECT

private:
    Ui::PreferencesDialog m_UserInterface;
    SettingsManager *m_Settings;
    bool m_Modified;
    QFont m_Font;

public:
    PreferencesDialog( QWidget *parent = 0 );
    ~PreferencesDialog();

    bool isModified();

public slots:
    void closeDialog();
    void saveDialog();

    void fontFamilyChanged( const QFont &font );
    void fontSizeChanged( int size );
};

#endif // PREFERENCESDIALOG_H
