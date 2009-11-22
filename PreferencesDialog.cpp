#include "PreferencesDialog.h"

// PUBLIC
PreferencesDialog::PreferencesDialog( QWidget *parent ) : QDialog( parent, Qt::Dialog )
{
    m_UserInterface.setupUi( this );
    QObject::connect( m_UserInterface.saveButton, SIGNAL( clicked() ), this, SLOT( saveDialog() ));
    QObject::connect( m_UserInterface.cancelButton, SIGNAL( clicked() ), this, SLOT( closeDialog() ));
    QObject::connect( m_UserInterface.settingsWindowFontName, SIGNAL( currentFontChanged(QFont)), this, SLOT(fontFamilyChanged(QFont)) );
    QObject::connect( m_UserInterface.settingsWindowFontSize, SIGNAL( valueChanged( int )), this, SLOT(fontSizeChanged(int)));

    // Fill with settings from File or defaults
    m_Modified = false;
    m_Settings = new SettingsManager();

    // Font defaults
    m_Font = m_Settings->getFont();
    int fontSize = m_Font.pointSize();

    m_UserInterface.settingsWindowFontName->setCurrentFont( m_Font );
    m_UserInterface.settingsWindowFontName->currentFont().setPointSize( 10 );
    m_UserInterface.settingsWindowFontSize->setValue( fontSize );

    // Serial Port
    SerialPort *serPort = SerialPort::getInstance();
    QList<QString> portNames = serPort->getAvailablePortNames();

    for( int index = 0; index < portNames.length(); index ++ )
    {
        m_UserInterface.settingsSerialPort->addItem( portNames[index], QVariant( portNames[index] ));
        if( m_Settings->getSerialPortName().compare( portNames[index] ) == 0 )
            m_UserInterface.settingsSerialPort->setCurrentIndex( index );        
    }  

    // Serial speed
    for( int index = 0; index < m_UserInterface.settingsSerialSpeed->count(); index ++ )
    {
        int dropDownSpeed = QVariant( m_UserInterface.settingsSerialSpeed->itemText( index )).toInt();
        if( m_Settings->getSerialPortSpeed() == dropDownSpeed )
            m_UserInterface.settingsSerialSpeed->setCurrentIndex( index );
    }

    // Serial stopbits
    for( int index = 0; index < m_UserInterface.settingsSerialStopBits->count(); index ++ )
    {
        int dropDownStop = QVariant( m_UserInterface.settingsSerialStopBits->itemText( index )).toInt();
        if( m_Settings->getSerialPortStopbits() == dropDownStop )
            m_UserInterface.settingsSerialStopBits->setCurrentIndex( index );
    }

    // Serial databits
    for( int index = 0; index < m_UserInterface.settingsSerialDataBits->count(); index ++ )
    {
        int dropDownData = QVariant( m_UserInterface.settingsSerialDataBits->itemText( index )).toInt();
        if( m_Settings->getSerialPortDatabits() == dropDownData )
            m_UserInterface.settingsSerialDataBits->setCurrentIndex( index );
    }

    // Serial Parity
    for( int index = 0; index < m_UserInterface.settingsSerialParity->count(); index ++ )
    {
        QString dropDownParity = QVariant( m_UserInterface.settingsSerialParity->itemText( index )).toString();
        if( m_Settings->getSerialPortParity().compare( dropDownParity ) == 0 )
            m_UserInterface.settingsSerialParity->setCurrentIndex( index );
    }
}

PreferencesDialog::~PreferencesDialog()
{
    delete m_Settings;
}

bool PreferencesDialog::isModified()
{
    return m_Modified;
}

// SLOTS
void PreferencesDialog::closeDialog()
{
    this->close();
}

void PreferencesDialog::saveDialog()
{
    m_Settings->setFont( m_Font );

    // Port name
    QString portName = m_UserInterface.settingsSerialPort->itemText( m_UserInterface.settingsSerialPort->currentIndex() );
    m_Settings->setSerialPortName( portName );

    // Port speed
    QVariant speed( m_UserInterface.settingsSerialSpeed->itemText( m_UserInterface.settingsSerialSpeed->currentIndex() ));
    m_Settings->setSerialPortSpeed( speed.toInt());

    // Port Databits
    QVariant databits( m_UserInterface.settingsSerialDataBits->itemText( m_UserInterface.settingsSerialDataBits->currentIndex() ));
    m_Settings->setSerialPortDatabits( databits.toInt());

    // Port Stopbits
    QVariant stopbits( m_UserInterface.settingsSerialStopBits->itemText( m_UserInterface.settingsSerialStopBits->currentIndex() ));
    m_Settings->setSerialPortStopbits( stopbits.toInt());

    // Port Parity
    QString portParity = m_UserInterface.settingsSerialParity->itemText( m_UserInterface.settingsSerialParity->currentIndex() );
    m_Settings->setSerialPortParity( portParity );

    m_Settings->save();

    delete m_Settings;

    m_Modified = true;
    this->close();
}

void PreferencesDialog::fontFamilyChanged( const QFont &font )
{
    qDebug() << "Fontfamily changed";

    m_Font = font;
    if( m_UserInterface.settingsWindowFontSize > 0 )
        m_Font.setPointSize( m_UserInterface.settingsWindowFontSize->value() );
}

void PreferencesDialog::fontSizeChanged( int size )
{
    qDebug() << "fontsize changed " << size;

    if( size > 0 )
        m_Font.setPointSize( size );
}
