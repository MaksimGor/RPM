#include "menu.h"
#include "ui_menu.h"
#include "client.h"
#include <QFile>
/**
 * @brief Создание окна, подключение к чату
 * @author Maxim Gordienko
 */
menu::menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
}

menu::~menu()
{
    delete ui;
}
/**
 * @brief Создание окна чата
 * @author Maxim Gordienko
 */
void menu::on_connect_clicked()
{
    QString path = QCoreApplication::applicationDirPath();
    Name = ui->name->text();
    QFile file(path+"/Name.txt");
    file.open(QIODevice::WriteOnly);
    file.write(Name.toUtf8());
    file.close();
    Client window;
    window.setModal(true);
    window.exec();
}


