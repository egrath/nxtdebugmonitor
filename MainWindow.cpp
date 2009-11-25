#include "MainWindow.h"

// Private
void MainWindow::setupUi()
{
    m_UserInterface.setupUi( this );

    /*
     * Connecting all Signals/Slots
     */
    // File->Exit
    QObject::connect( m_UserInterface.actionFileExit, SIGNAL( triggered() ), this, SLOT( shutdown() ));

    // File->Save
    QObject::connect( m_UserInterface.actionFileSave, SIGNAL( triggered() ), this, SLOT( saveDebugText() ));

    // Edit->Preferences
    QObject::connect( m_UserInterface.actionEditPreferences, SIGNAL( triggered() ), this, SLOT( showPreferences() ));

    // Edit->Select all
    QObject::connect( m_UserInterface.actionEditSelectAll, SIGNAL( triggered() ), this, SLOT( selectAll() ));

    // Edit->Copy
    QObject::connect( m_UserInterface.actionEditCopy, SIGNAL( triggered() ), this, SLOT( copyToClipboard()));

    QObject::connect( m_UserInterface.debugText, SIGNAL(copyAvailable(bool)), this, SLOT(selectionChanged(bool)));

    // Window Icon
    this->setWindowIcon( QIcon( ":/icons/icons/network-wireless.png" ));
}

// Protected
void MainWindow::closeEvent( QCloseEvent *event )
{
    qDebug() << "MainWindow::closeEvent";

    QWidget::closeEvent( event );
}

void MainWindow::setWindowTitle()
{
    QString windowTitle;

    windowTitle.append( m_WindowTitle );
    windowTitle.append( " [" + m_Settings->getSerialPortName() + ", " +
                        QVariant( m_Settings->getSerialPortSpeed() ).toString() + "/" +
                        QVariant( m_Settings->getSerialPortDatabits() ).toString() + "/" +
                        QVariant( m_Settings->getSerialPortParity() ).toString() + "/" +
                        QVariant( m_Settings->getSerialPortStopbits() ).toString() + "]" );

    QMainWindow::setWindowTitle( windowTitle );
}

// Public
MainWindow::MainWindow() : QMainWindow( 0, Qt::Window )
{
    setupUi();

    m_Settings = new SettingsManager();
    m_UserInterface.debugText->setFont( m_Settings->getFont() );

    // Window Title
    m_WindowTitle = this->windowTitle();
    setWindowTitle();

    // Start serial port listener
    m_DebugTextLines = 0;
    m_DebugTextMutex = new QMutex( QMutex::NonRecursive );
    m_SerialPortListener = new SerialPortListener();
    QObject::connect( m_SerialPortListener, SIGNAL( messageReceived( const QString & )),
                      this, SLOT( appendMessage( const QString & )));
    m_SerialPortListener->openSerialPort();
    m_SerialPortListener->start();
}

MainWindow::~MainWindow()
{
    qDebug() << "MainWindow::dtor";

    m_SerialPortListener->terminate();
    m_SerialPortListener->wait( 0 );

    delete m_DebugTextMutex;
    delete m_SerialPortListener;
}

// Public slots
void MainWindow::appendMessage( const QString &message )
{
    qDebug() << "Appending to Debug Window: " << message;

    // We need to lock before accessing a GUI element from within
    // another thread
    m_DebugTextMutex->lock();    

    m_UserInterface.debugText->moveCursor( QTextCursor::End, QTextCursor::MoveAnchor );
    m_UserInterface.debugText->insertPlainText( message + '\n');

    m_DebugTextMutex->unlock();
}

void MainWindow::shutdown()
{
    this->close();
}

void MainWindow::saveDebugText()
{
    QString fileName = QFileDialog::getSaveFileName( this, "Save as", QDir::currentPath(), "*.*" );
    if( ! fileName.isEmpty() )
    {
        qDebug() << "Saving file to " << fileName;

        QFile saveFile( fileName );
        if( ! saveFile.open( QIODevice::WriteOnly ))                    
            return;
        saveFile.write( m_UserInterface.debugText->toPlainText().toStdString().data() );
        saveFile.close();
    }
}

void MainWindow::showPreferences()
{
    PreferencesDialog *dialog = new PreferencesDialog();
    dialog->exec();

    if( dialog->isModified() )
    {
        // Reload settings
        delete m_Settings;
        m_Settings = new SettingsManager();

        qDebug() << "set!";

        // Text settings
        m_UserInterface.debugText->moveCursor( QTextCursor::Start, QTextCursor::MoveAnchor );
        m_UserInterface.debugText->moveCursor( QTextCursor::End, QTextCursor::KeepAnchor );
        m_UserInterface.debugText->setCurrentFont( m_Settings->getFont() );

        m_UserInterface.debugText->moveCursor( QTextCursor::End, QTextCursor::MoveAnchor );

        // Serial port settings
        qDebug() << "Trying to stop listener";
        m_SerialPortListener->stopListener();
        m_SerialPortListener->terminate();
        delete m_SerialPortListener;
        qDebug() << "Stopped listener";
        m_SerialPortListener = new SerialPortListener();
        QObject::connect( m_SerialPortListener, SIGNAL( messageReceived( const QString & )),
                          this, SLOT( appendMessage( const QString & )));
        m_SerialPortListener->openSerialPort();
        m_SerialPortListener->start();
        setWindowTitle();
    }
}

void MainWindow::selectAll()
{
    m_UserInterface.debugText->selectAll();
}

void MainWindow::copyToClipboard()
{
    m_UserInterface.debugText->copy();
    m_UserInterface.debugText->moveCursor( QTextCursor::End, QTextCursor::MoveAnchor );
}

void MainWindow::selectionChanged( bool yes )
{
    if( yes ) // something selected?
        m_UserInterface.actionEditCopy->setEnabled( true );
    else
        m_UserInterface.actionEditCopy->setEnabled( false );
}
