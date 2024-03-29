CONFIG += qt \
    console \
    thread \
    debug_and_release
SOURCES += main.cpp \
    MainWindow.cpp \
    SerialPortListener.cpp \
    PreferencesDialog.cpp \
    SettingsManager.cpp \
    SerialPort.cpp \
    NXTDecoder.cpp
FORMS += DebugWindow.ui \
    PreferencesDialog.ui
HEADERS += MainWindow.h \
    SerialPortListener.h \
    PreferencesDialog.h \
    SettingsManager.h \
    SerialPort.h \
    NXTDecoder.h
QMAKE_CFLAGS_DEBUG += -DDEBUG
QMAKE_CXXFLAGS_DEBUG += -DDEBUG
RESOURCES += resources.qrc
RC_FILE = debugmonitor.rc
OTHER_FILES += debugmonitor.rc

