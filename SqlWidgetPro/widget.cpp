#include "widget.h"
#include "ui_widget.h"
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QFile>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QStringList>
#include <QMessageBox>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, SIGNAL(DeleteNote_clicked()),this,SLOT(on_DeleteNote_clicked()));
    connect(this,SIGNAL(ConnectDatabase_clicked()),this,SLOT(on_ConnectDatabase_clicked()));
     connect(this,SIGNAL(createBD_clicked()),this,SLOT(on_CreateTable_clicked()));
    connect(this,SIGNAL(Update_clicked()),this,SLOT(on_Update_clicked()));
    connect(this,SIGNAL(CreateTable_clicked()),this,SLOT(on_CreateTable_clicked()));
    connect(this,SIGNAL(AddNote_clicked()),this,SLOT(on_AddNote_clicked()));
    connect(this,SIGNAL(DeleteNote_clicked()),this,SLOT(on_DeleteNote_clicked()));
    connect(this,SIGNAL(DropColumn_clicked()),this,SLOT(on_DropColumn_clicked()));
    connect(this,SIGNAL(DropTable_clicked()),this,SLOT(on_DropTable_clicked()));
    connect(this,SIGNAL(CreateColums_clicked()),this,SLOT(on_CreateColums_clicked()));
}

Widget::~Widget()
{
    delete ui;
}

//Подключение к базе данных
void Widget::on_ConnectDatabase_clicked()
{
   ui->comboBox->clear();
   QStringList starNamecombox = {"Таблица"};
   ui->comboBox->addItems(starNamecombox);
   QSqlQuery query;
   QString path = QCoreApplication::applicationDirPath();
   DBpath = ui->DBpath->text();
   if(!QFile(path + "/"+DBpath+".db").exists()){
       QFile mFile(path+".db");
       mFile.open(QIODevice::WriteOnly);
       mFile.close();
       BDtemplate();
       }
   else{
       db = QSqlDatabase::addDatabase("QSQLITE");
       db.setHostName("localhost");
       db.setDatabaseName(DBpath);
       if(!db.open()){ui->connectError->setText(db.lastError().text());}
       else{ui->DBpath->setText("Вы подключились!");}
       QStringList tables = db.tables();
       countTable = tables.count();
       for(int i=0; i < countTable; i++){
       ui->comboBox->addItem(tables.value(i));
       }
      }
}
void Widget::BDtemplate()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName(DBpath);
    if(!db.open()){ui->connectError->setText(db.lastError().text());}
    else{ui->DBpath->setText("Вы подключились!");}
    QSqlQuery query;
    QString table = "CREATE TABLE Employee (id_employee INT(11) NOT NULL,Name Text NOT NULL, Sex Text,PRIMARY KEY (id_employee));";
    query.exec(table);
    query.exec("INSERT INTO Employee VALUES (1, 'Gordienko','Male'), (2, 'Serov','Male') ,(3, 'Bereza','Male');");
    QStringList tables = db.tables();
    countTable = tables.count();
    for(int i=0; i < countTable; i++){
    ui->comboBox->addItem(tables.value(i));
    }
}


void Widget::on_AddNote_clicked()
{
    QSqlQuery query;
    QString tableName = ui->tableName_2->text();
    QString table = "INSERT INTO " +ui->tableName_2->text() +
            "("+ui->nameColumn_2->text()+") VALUES ("+ ui->DataLine->text() +");";
    bool b_table = query.exec(table);
        if(!b_table)
        {
           ui->ErrorDate->setText("Cтрока не создан");
        }
        else
        {
            ui->connectError->clear();
            Model(tableName);
        }
}

void Widget::on_DeleteNote_clicked()
{
    QSqlQuery query;
    QString tableName = ui->tableName_2->text();
    QString table = "DELETE FROM " +tableName +
            " WHERE "+ui->nameColumn_2->text()+" == "+ ui->DataLine->text()  +";";
    bool b_table = query.exec(table);
        if(!b_table)
        {
           ui->ErrorCreate->setText("Не удалить строку!");
        }
        else
        {
            ui->connectError->clear();
            Model(tableName);
        }
}

void Widget::on_DropColumn_clicked()
{
  QMessageBox::information(this,"lol","Удаление не доступно, используйте запрос создания новой таблицы с переносом нужных столбцов: "
                                      "insert into новая_таблицы (colums_1,...,colums_n) select (colums_1,...,colums_n)"
                                      " from исходная_таблица;");
}

void Widget::on_ZaprosButton_clicked()
{
    QSqlQuery query;
    QString tableZapros = ui->Zapros->text();
    QSqlQueryModel *setquery = new QSqlQueryModel;
    setquery->setQuery(tableZapros);
    QTableView *tv = new QTableView(this);
    tv->setModel(setquery);
    ui->tableView->setModel(setquery);
    bool b_table = query.exec(tableZapros);
        if(!b_table){
           ui->ErrorDate_2->setText("Запрос не выполнен");
        }
}

void Widget::on_CreateTable_clicked()
{
    QSqlQuery query;
    QString tableName = ui->tableName->text();
    QString table = "CREATE TABLE " + tableName +" (id_" + tableName + " INTEGER NOT NULL, "+ "PRIMARY KEY(id_" + tableName +"));";
    bool b_table = query.exec(table);
        if(!b_table)
        {
           ui->connectError->setText("Не удается создать таблицу!");
        }
        else
        {
          ui->connectError->clear();
          Model(tableName);
        }
}

void Widget::on_Update_clicked()
{
    db.close();
    ui->DBpath->setText(DBpath);
    ui->comboBox->clear();
    QStringList starNamecombox = {"Таблица"};
    ui->comboBox->addItems(starNamecombox);
    on_ConnectDatabase_clicked();
}

void Widget::on_DropTable_clicked()
{
    QSqlQuery query;
    QString tableName = ui->tableName->text();
    QString table = "DROP TABLE " + tableName;
    bool b_table = query.exec(table);
        if(!b_table)
        {
           ui->connectError->setText("Не удалить таблицу!");
        }
        else
        {
          ui->connectError->setText("Успешно удалена, обновите страницу!");
        }
}

void Widget::on_CreateColums_clicked()
{
    QSqlQuery query;
    QString tableName = ui->tableName->text();
    QString table = "ALTER TABLE " + ui->tableName->text() + " ADD "+ui->nameColumn->text()+" "+
    type+" "+ui->NotNull->text()+" "+ui->PrimaryKey->text()+" "+ui->AutoIn->text()+" "+ui->UNIQUE->text()+" " +" ;";

    bool b_table = query.exec(table);
        if(!b_table)
        {
           ui->ErrorCreate->setText("Столбец не создан");
        }
        else
        {
          ui->connectError->clear();
          Model(tableName);
        }
}

void Widget::Model(const QString &arg1)
{
       model = new QSqlTableModel(this, db);
       model->setTable(arg1);
       model->select();
       ui->tableView->setModel(model);
}
// Получения названия таблицы из combox
void Widget::on_comboBox_activated(const QString &arg1)
{
     Model(arg1);
}
void Widget::on_Type_activated(const QString &arg1)
{
    type = arg1;
}
