/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QComboBox *comboBox;
    QPushButton *CreateTable;
    QPushButton *DropTable;
    QLabel *Create;
    QLabel *View;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *DBpath;
    QPushButton *ConnectDatabase;
    QTableView *tableView;
    QLabel *ConnectandInquiry;
    QCheckBox *NotNull;
    QCheckBox *PrimaryKey;
    QCheckBox *AutoIn;
    QCheckBox *UNIQUE;
    QPushButton *CreateColums;
    QLineEdit *tableName;
    QLabel *connectError;
    QLineEdit *nameColumn;
    QComboBox *Type;
    QLabel *FillingOut;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *tableName_2;
    QLineEdit *nameColumn_2;
    QLineEdit *DataLine;
    QPushButton *AddNote;
    QPushButton *DeleteNote;
    QLabel *ErrorDate;
    QLabel *ErrorCreate;
    QPushButton *DropColumn;
    QLabel *ErrorDate_2;
    QLabel *ConnectandInquiry_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *Zapros;
    QPushButton *ZaprosButton;
    QPushButton *Update;
    QComboBox *SaveZP;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(747, 597);
        comboBox = new QComboBox(Widget);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 0, 111, 31));
        CreateTable = new QPushButton(Widget);
        CreateTable->setObjectName(QString::fromUtf8("CreateTable"));
        CreateTable->setGeometry(QRect(220, 0, 131, 30));
        DropTable = new QPushButton(Widget);
        DropTable->setObjectName(QString::fromUtf8("DropTable"));
        DropTable->setGeometry(QRect(340, 0, 131, 32));
        Create = new QLabel(Widget);
        Create->setObjectName(QString::fromUtf8("Create"));
        Create->setGeometry(QRect(30, 40, 111, 31));
        View = new QLabel(Widget);
        View->setObjectName(QString::fromUtf8("View"));
        View->setGeometry(QRect(30, 320, 111, 31));
        horizontalLayoutWidget_2 = new QWidget(Widget);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 200, 681, 47));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        DBpath = new QLineEdit(horizontalLayoutWidget_2);
        DBpath->setObjectName(QString::fromUtf8("DBpath"));

        horizontalLayout_2->addWidget(DBpath);

        ConnectDatabase = new QPushButton(horizontalLayoutWidget_2);
        ConnectDatabase->setObjectName(QString::fromUtf8("ConnectDatabase"));

        horizontalLayout_2->addWidget(ConnectDatabase);

        tableView = new QTableView(Widget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 360, 681, 231));
        ConnectandInquiry = new QLabel(Widget);
        ConnectandInquiry->setObjectName(QString::fromUtf8("ConnectandInquiry"));
        ConnectandInquiry->setGeometry(QRect(30, 170, 161, 31));
        NotNull = new QCheckBox(Widget);
        NotNull->setObjectName(QString::fromUtf8("NotNull"));
        NotNull->setGeometry(QRect(510, 80, 86, 20));
        PrimaryKey = new QCheckBox(Widget);
        PrimaryKey->setObjectName(QString::fromUtf8("PrimaryKey"));
        PrimaryKey->setGeometry(QRect(560, 80, 86, 20));
        AutoIn = new QCheckBox(Widget);
        AutoIn->setObjectName(QString::fromUtf8("AutoIn"));
        AutoIn->setGeometry(QRect(610, 80, 86, 20));
        UNIQUE = new QCheckBox(Widget);
        UNIQUE->setObjectName(QString::fromUtf8("UNIQUE"));
        UNIQUE->setGeometry(QRect(660, 80, 86, 20));
        CreateColums = new QPushButton(Widget);
        CreateColums->setObjectName(QString::fromUtf8("CreateColums"));
        CreateColums->setGeometry(QRect(460, 0, 141, 31));
        tableName = new QLineEdit(Widget);
        tableName->setObjectName(QString::fromUtf8("tableName"));
        tableName->setGeometry(QRect(30, 80, 181, 21));
        connectError = new QLabel(Widget);
        connectError->setObjectName(QString::fromUtf8("connectError"));
        connectError->setGeometry(QRect(310, 180, 391, 16));
        nameColumn = new QLineEdit(Widget);
        nameColumn->setObjectName(QString::fromUtf8("nameColumn"));
        nameColumn->setGeometry(QRect(220, 80, 181, 21));
        Type = new QComboBox(Widget);
        Type->addItem(QString());
        Type->addItem(QString());
        Type->addItem(QString());
        Type->setObjectName(QString::fromUtf8("Type"));
        Type->setGeometry(QRect(400, 80, 111, 21));
        FillingOut = new QLabel(Widget);
        FillingOut->setObjectName(QString::fromUtf8("FillingOut"));
        FillingOut->setGeometry(QRect(30, 100, 191, 31));
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 130, 681, 33));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        tableName_2 = new QLineEdit(horizontalLayoutWidget);
        tableName_2->setObjectName(QString::fromUtf8("tableName_2"));

        horizontalLayout->addWidget(tableName_2);

        nameColumn_2 = new QLineEdit(horizontalLayoutWidget);
        nameColumn_2->setObjectName(QString::fromUtf8("nameColumn_2"));

        horizontalLayout->addWidget(nameColumn_2);

        DataLine = new QLineEdit(horizontalLayoutWidget);
        DataLine->setObjectName(QString::fromUtf8("DataLine"));

        horizontalLayout->addWidget(DataLine);

        AddNote = new QPushButton(horizontalLayoutWidget);
        AddNote->setObjectName(QString::fromUtf8("AddNote"));

        horizontalLayout->addWidget(AddNote);

        DeleteNote = new QPushButton(horizontalLayoutWidget);
        DeleteNote->setObjectName(QString::fromUtf8("DeleteNote"));

        horizontalLayout->addWidget(DeleteNote);

        ErrorDate = new QLabel(Widget);
        ErrorDate->setObjectName(QString::fromUtf8("ErrorDate"));
        ErrorDate->setGeometry(QRect(210, 110, 491, 16));
        ErrorCreate = new QLabel(Widget);
        ErrorCreate->setObjectName(QString::fromUtf8("ErrorCreate"));
        ErrorCreate->setGeometry(QRect(150, 50, 541, 20));
        DropColumn = new QPushButton(Widget);
        DropColumn->setObjectName(QString::fromUtf8("DropColumn"));
        DropColumn->setGeometry(QRect(590, 0, 141, 31));
        ErrorDate_2 = new QLabel(Widget);
        ErrorDate_2->setObjectName(QString::fromUtf8("ErrorDate_2"));
        ErrorDate_2->setGeometry(QRect(150, 330, 491, 16));
        ConnectandInquiry_2 = new QLabel(Widget);
        ConnectandInquiry_2->setObjectName(QString::fromUtf8("ConnectandInquiry_2"));
        ConnectandInquiry_2->setGeometry(QRect(30, 250, 91, 31));
        horizontalLayoutWidget_3 = new QWidget(Widget);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(30, 280, 681, 38));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Zapros = new QLineEdit(horizontalLayoutWidget_3);
        Zapros->setObjectName(QString::fromUtf8("Zapros"));
        Zapros->setTabletTracking(true);

        horizontalLayout_3->addWidget(Zapros);

        ZaprosButton = new QPushButton(horizontalLayoutWidget_3);
        ZaprosButton->setObjectName(QString::fromUtf8("ZaprosButton"));

        horizontalLayout_3->addWidget(ZaprosButton);

        Update = new QPushButton(Widget);
        Update->setObjectName(QString::fromUtf8("Update"));
        Update->setGeometry(QRect(190, 0, 41, 31));
        SaveZP = new QComboBox(Widget);
        SaveZP->addItem(QString());
        SaveZP->setObjectName(QString::fromUtf8("SaveZP"));
        SaveZP->setGeometry(QRect(100, 0, 101, 32));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Sqlite MVersion", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("Widget", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));

        CreateTable->setText(QCoreApplication::translate("Widget", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        DropTable->setText(QCoreApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\242\320\260\320\261\320\273\320\270\321\206\321\203", nullptr));
        Create->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:24pt;\">\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\213</span></p><p><span style=\" font-size:24pt;\"><br/></span></p></body></html>", nullptr));
        View->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:24pt;\">\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200</span></p></body></html>", nullptr));
        DBpath->setText(QCoreApplication::translate("Widget", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \320\261\320\260\320\267\321\213 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        ConnectDatabase->setText(QCoreApplication::translate("Widget", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        ConnectandInquiry->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:24pt;\">\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\320\265 </span></p></body></html>", nullptr));
        NotNull->setText(QCoreApplication::translate("Widget", "\320\235\320\237", nullptr));
        PrimaryKey->setText(QCoreApplication::translate("Widget", "\320\237\320\232", nullptr));
        AutoIn->setText(QCoreApplication::translate("Widget", "\320\220\320\230", nullptr));
        UNIQUE->setText(QCoreApplication::translate("Widget", "\320\243", nullptr));
        CreateColums->setText(QCoreApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        tableName->setText(QCoreApplication::translate("Widget", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        connectError->setText(QString());
        nameColumn->setText(QCoreApplication::translate("Widget", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\321\202\320\276\320\273\320\261\321\206\320\260", nullptr));
        Type->setItemText(0, QCoreApplication::translate("Widget", "INTEGER", nullptr));
        Type->setItemText(1, QCoreApplication::translate("Widget", "TEXT", nullptr));
        Type->setItemText(2, QCoreApplication::translate("Widget", "DATE", nullptr));

        FillingOut->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:24pt;\">\320\227\320\260\320\277\320\276\320\273\320\275\320\265\320\275\320\270\320\265</span></p></body></html>", nullptr));
        tableName_2->setText(QCoreApplication::translate("Widget", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", nullptr));
        nameColumn_2->setText(QCoreApplication::translate("Widget", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\321\202\320\276\320\273\320\261\321\206\320\260", nullptr));
        DataLine->setText(QCoreApplication::translate("Widget", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        AddNote->setText(QCoreApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        DeleteNote->setText(QCoreApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        ErrorDate->setText(QString());
        ErrorCreate->setText(QString());
        DropColumn->setText(QCoreApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\202\320\276\320\273\320\261\320\265\321\206", nullptr));
        ErrorDate_2->setText(QString());
        ConnectandInquiry_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:24pt;\">\320\227\320\260\320\277\321\200\320\276\321\201</span></p></body></html>", nullptr));
        ZaprosButton->setText(QCoreApplication::translate("Widget", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\321\202\321\214", nullptr));
        Update->setText(QCoreApplication::translate("Widget", "\342\206\272", nullptr));
        SaveZP->setItemText(0, QCoreApplication::translate("Widget", "\320\227\320\260\320\277\321\200\320\276\321\201\321\213", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
