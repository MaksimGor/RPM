#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ActiveQt/qaxobject.h>
#include <ActiveQt/qaxbase.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)

{
    widjet = new QWidget(this);
    this->setCentralWidget(widjet);

    vLayout = new QVBoxLayout(widjet);
    tableWidget = new QTableWidget(widjet);
    tableWidget->setRowCount(rowCount);
    tableWidget->setColumnCount(columnCount);
    QPushButton* addCulumnBut = new QPushButton("addColumn",widjet);
    QPushButton* addRowBut = new QPushButton("addRow",widjet);
    QPushButton* saveTable = new QPushButton("saveTable",widjet);
    QHBoxLayout* hButLayout = new QHBoxLayout(widjet);
    hButLayout->addWidget(addRowBut);
    hButLayout->addWidget(addCulumnBut);
    connect(addCulumnBut,&QPushButton::clicked,this,&MainWindow::addColumn);
    connect(addRowBut,&QPushButton::clicked,this,&MainWindow::addRow);
    connect(saveTable,&QPushButton::clicked,this,&MainWindow::save);
    tableWidget->setItem(0,0,new QTableWidgetItem("text"));
    vLayout->addLayout(hButLayout);
    vLayout->addWidget(tableWidget);
    vLayout->addWidget(saveTable);



    widjet->setLayout(vLayout);
}

MainWindow::~MainWindow()
{

}

void MainWindow::addColumn()
{
    columnCount+=1;
    tableWidget->setColumnCount(columnCount);
}

void MainWindow::addRow()
{
    rowCount+=1;
    tableWidget->setRowCount(rowCount);

}

void MainWindow::save()
{
    QAxObject *mExcel = new QAxObject("Excel.Application",this);
    QAxObject *workbooks = mExcel->querySubObject("Workbooks");
    QAxObject *workbook = workbooks->querySubObject( "Open(const QString&)", QFileDialog::getOpenFileNames() );
    QAxObject *mSheets = workbook->querySubObject( "Sheets" );
    QAxObject *StatSheet = mSheets->querySubObject( "Item(const QVariant&)", QVariant("Лист1") );
    for(int i=0;i<rowCount;i++){
        for(int j=0;j<columnCount;j++){
            QAxObject* cell = StatSheet->querySubObject("Cells(QVariant,QVariant)", i+1, j+1);
            cell->setProperty("Value", tableWidget->item(i,j)->text());
            delete cell;
        }
    }

    delete StatSheet;
    delete mSheets;
    workbook->dynamicCall("Save()");
    delete workbook;
    delete workbooks;
    mExcel->dynamicCall("Quit()");
    delete mExcel;

}

