/********************************************************************************
** Form generated from reading UI file 'DebugWindow.ui'
**
** Created: Tue 24. Nov 19:40:49 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWINDOW_H
#define UI_DEBUGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DebugMonitorMainWindow
{
public:
    QAction *actionEditPreferences;
    QAction *actionFileSave;
    QAction *actionFileExit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *debugText;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DebugMonitorMainWindow)
    {
        if (DebugMonitorMainWindow->objectName().isEmpty())
            DebugMonitorMainWindow->setObjectName(QString::fromUtf8("DebugMonitorMainWindow"));
        DebugMonitorMainWindow->resize(640, 480);
        actionEditPreferences = new QAction(DebugMonitorMainWindow);
        actionEditPreferences->setObjectName(QString::fromUtf8("actionEditPreferences"));
        actionFileSave = new QAction(DebugMonitorMainWindow);
        actionFileSave->setObjectName(QString::fromUtf8("actionFileSave"));
        actionFileExit = new QAction(DebugMonitorMainWindow);
        actionFileExit->setObjectName(QString::fromUtf8("actionFileExit"));
        centralwidget = new QWidget(DebugMonitorMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        debugText = new QTextEdit(centralwidget);
        debugText->setObjectName(QString::fromUtf8("debugText"));
        debugText->setReadOnly(true);
        debugText->setAcceptRichText(false);

        gridLayout->addWidget(debugText, 0, 0, 1, 1);

        DebugMonitorMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DebugMonitorMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 19));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        DebugMonitorMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(DebugMonitorMainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DebugMonitorMainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuFile->addAction(actionFileSave);
        menuFile->addAction(actionFileExit);
        menuEdit->addAction(actionEditPreferences);

        retranslateUi(DebugMonitorMainWindow);

        QMetaObject::connectSlotsByName(DebugMonitorMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *DebugMonitorMainWindow)
    {
        DebugMonitorMainWindow->setWindowTitle(QApplication::translate("DebugMonitorMainWindow", "NXT Debug Monitor", 0, QApplication::UnicodeUTF8));
        actionEditPreferences->setText(QApplication::translate("DebugMonitorMainWindow", "Preferences", 0, QApplication::UnicodeUTF8));
        actionFileSave->setText(QApplication::translate("DebugMonitorMainWindow", "Save", 0, QApplication::UnicodeUTF8));
        actionFileExit->setText(QApplication::translate("DebugMonitorMainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("DebugMonitorMainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("DebugMonitorMainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DebugMonitorMainWindow: public Ui_DebugMonitorMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWINDOW_H
