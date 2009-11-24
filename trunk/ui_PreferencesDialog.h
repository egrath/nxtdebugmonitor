/********************************************************************************
** Form generated from reading UI file 'PreferencesDialog.ui'
**
** Created: Tue 24. Nov 19:40:49 2009
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREFERENCESDIALOG_H
#define UI_PREFERENCESDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFontComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_PreferencesDialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *saveButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QComboBox *settingsSerialSpeed;
    QComboBox *settingsSerialPort;
    QComboBox *settingsSerialDataBits;
    QComboBox *settingsSerialParity;
    QComboBox *settingsSerialStopBits;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QSpacerItem *verticalSpacer;
    QLabel *label_6;
    QSpinBox *settingsScrollbackLines;
    QFontComboBox *settingsWindowFontName;
    QLabel *label_7;
    QSpinBox *settingsWindowFontSize;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PreferencesDialog)
    {
        if (PreferencesDialog->objectName().isEmpty())
            PreferencesDialog->setObjectName(QString::fromUtf8("PreferencesDialog"));
        PreferencesDialog->setWindowModality(Qt::WindowModal);
        PreferencesDialog->resize(369, 303);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/icons/accessories-text-editor.png"), QSize(), QIcon::Normal, QIcon::Off);
        PreferencesDialog->setWindowIcon(icon);
        PreferencesDialog->setSizeGripEnabled(false);
        PreferencesDialog->setModal(true);
        gridLayout_2 = new QGridLayout(PreferencesDialog);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        saveButton = new QPushButton(PreferencesDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout->addWidget(saveButton, 3, 4, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 0, 1, 3);

        cancelButton = new QPushButton(PreferencesDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        gridLayout->addWidget(cancelButton, 3, 3, 1, 1);

        groupBox = new QGroupBox(PreferencesDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 4, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 5, 1, 1, 1);

        settingsSerialSpeed = new QComboBox(groupBox);
        settingsSerialSpeed->setObjectName(QString::fromUtf8("settingsSerialSpeed"));

        gridLayout_3->addWidget(settingsSerialSpeed, 1, 2, 1, 1);

        settingsSerialPort = new QComboBox(groupBox);
        settingsSerialPort->setObjectName(QString::fromUtf8("settingsSerialPort"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(settingsSerialPort->sizePolicy().hasHeightForWidth());
        settingsSerialPort->setSizePolicy(sizePolicy1);
        settingsSerialPort->setSizeIncrement(QSize(0, 0));
        settingsSerialPort->setBaseSize(QSize(0, 0));

        gridLayout_3->addWidget(settingsSerialPort, 0, 2, 1, 1);

        settingsSerialDataBits = new QComboBox(groupBox);
        settingsSerialDataBits->setObjectName(QString::fromUtf8("settingsSerialDataBits"));

        gridLayout_3->addWidget(settingsSerialDataBits, 3, 2, 1, 1);

        settingsSerialParity = new QComboBox(groupBox);
        settingsSerialParity->setObjectName(QString::fromUtf8("settingsSerialParity"));

        gridLayout_3->addWidget(settingsSerialParity, 4, 2, 1, 1);

        settingsSerialStopBits = new QComboBox(groupBox);
        settingsSerialStopBits->setObjectName(QString::fromUtf8("settingsSerialStopBits"));

        gridLayout_3->addWidget(settingsSerialStopBits, 5, 2, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 1, 5);

        groupBox_2 = new QGroupBox(PreferencesDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalSpacer = new QSpacerItem(68, 2, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 3, 0, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);

        gridLayout_4->addWidget(label_6, 0, 0, 1, 1);

        settingsScrollbackLines = new QSpinBox(groupBox_2);
        settingsScrollbackLines->setObjectName(QString::fromUtf8("settingsScrollbackLines"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(settingsScrollbackLines->sizePolicy().hasHeightForWidth());
        settingsScrollbackLines->setSizePolicy(sizePolicy2);
        settingsScrollbackLines->setMinimumSize(QSize(80, 0));

        gridLayout_4->addWidget(settingsScrollbackLines, 0, 1, 1, 1);

        settingsWindowFontName = new QFontComboBox(groupBox_2);
        settingsWindowFontName->setObjectName(QString::fromUtf8("settingsWindowFontName"));
        settingsWindowFontName->setFontFilters(QFontComboBox::MonospacedFonts);

        gridLayout_4->addWidget(settingsWindowFontName, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        settingsWindowFontSize = new QSpinBox(groupBox_2);
        settingsWindowFontSize->setObjectName(QString::fromUtf8("settingsWindowFontSize"));
        settingsWindowFontSize->setMaximum(100);

        gridLayout_4->addWidget(settingsWindowFontSize, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 1, 3, 1, 1);


        gridLayout->addWidget(groupBox_2, 2, 0, 1, 5);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(PreferencesDialog);

        QMetaObject::connectSlotsByName(PreferencesDialog);
    } // setupUi

    void retranslateUi(QDialog *PreferencesDialog)
    {
        PreferencesDialog->setWindowTitle(QApplication::translate("PreferencesDialog", "Preferences", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("PreferencesDialog", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("PreferencesDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("PreferencesDialog", "Serial port settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("PreferencesDialog", "Port", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("PreferencesDialog", "Speed", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("PreferencesDialog", "Data bits", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("PreferencesDialog", "Parity", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("PreferencesDialog", "Stop bits", 0, QApplication::UnicodeUTF8));
        settingsSerialSpeed->clear();
        settingsSerialSpeed->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "19200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "38400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "57600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "230400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "460800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "921600", 0, QApplication::UnicodeUTF8)
        );
        settingsSerialDataBits->clear();
        settingsSerialDataBits->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "8", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "7", 0, QApplication::UnicodeUTF8)
        );
        settingsSerialParity->clear();
        settingsSerialParity->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "N", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "E", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "O", 0, QApplication::UnicodeUTF8)
        );
        settingsSerialStopBits->clear();
        settingsSerialStopBits->insertItems(0, QStringList()
         << QApplication::translate("PreferencesDialog", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("PreferencesDialog", "2", 0, QApplication::UnicodeUTF8)
        );
        groupBox_2->setTitle(QApplication::translate("PreferencesDialog", "Debug window settings", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("PreferencesDialog", "Scrollback lines", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("PreferencesDialog", "Font", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class PreferencesDialog: public Ui_PreferencesDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREFERENCESDIALOG_H
