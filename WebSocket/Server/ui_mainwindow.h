/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QLineEdit *host;
    QLineEdit *port;
    QLabel *host_label;
    QLabel *port_label;
    QPushButton *onoff;
    QPushButton *SaveSetting;
    QPushButton *callapse;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(442, 386);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 4, 0, 1, 5);

        host = new QLineEdit(centralwidget);
        host->setObjectName(QString::fromUtf8("host"));

        gridLayout->addWidget(host, 2, 3, 1, 1);

        port = new QLineEdit(centralwidget);
        port->setObjectName(QString::fromUtf8("port"));

        gridLayout->addWidget(port, 3, 3, 1, 1);

        host_label = new QLabel(centralwidget);
        host_label->setObjectName(QString::fromUtf8("host_label"));

        gridLayout->addWidget(host_label, 2, 2, 1, 1);

        port_label = new QLabel(centralwidget);
        port_label->setObjectName(QString::fromUtf8("port_label"));

        gridLayout->addWidget(port_label, 3, 2, 1, 1);

        onoff = new QPushButton(centralwidget);
        onoff->setObjectName(QString::fromUtf8("onoff"));

        gridLayout->addWidget(onoff, 2, 0, 1, 1);

        SaveSetting = new QPushButton(centralwidget);
        SaveSetting->setObjectName(QString::fromUtf8("SaveSetting"));

        gridLayout->addWidget(SaveSetting, 5, 3, 1, 1);

        callapse = new QPushButton(centralwidget);
        callapse->setObjectName(QString::fromUtf8("callapse"));

        gridLayout->addWidget(callapse, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        host_label->setText(QCoreApplication::translate("MainWindow", "Host", nullptr));
        port_label->setText(QCoreApplication::translate("MainWindow", "Port", nullptr));
        onoff->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", nullptr));
        SaveSetting->setText(QCoreApplication::translate("MainWindow", "     \320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\275\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270       ", nullptr));
        callapse->setText(QCoreApplication::translate("MainWindow", "\320\241\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
