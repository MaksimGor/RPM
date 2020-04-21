#include "client.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QMessageBox>
#include <QWidget>

Client::Client(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    sockCl = new QTcpSocket(this);
    sockCl->connectToHost("localhost", 33333, QTcpSocket::ReadWrite);
    if(sockCl->waitForConnected(30000)) {
        qInfo() << "Connected!";
        qInfo() << sockCl->peerAddress();
    } else{
         QMessageBox::information(NULL,QObject::tr("Информация"),tr("Нет подключения к серверу."));
    }

    connect(sockCl, &QTcpSocket::readyRead,this, &Client::readSocket);
    connect(ui->pushButton, &QPushButton::clicked,this, &Client::ButtonAction);
    connect(sockCl, &QTcpSocket::disconnected,this, &Client::serverDisconnect);
}

Client::~Client()
{
    delete ui;
}

void Client::ButtonAction()
{
    QFile file(QCoreApplication::applicationDirPath()+"/Name.txt");
    if(file.open(QIODevice::ReadOnly)){
            Name = file.readLine();
            file.close();
            chat = 1;
        }
    if (ui->message->text().toUtf8() == ""){
             QMessageBox::information(NULL,QObject::tr("Ошибка"),tr("Введите сообщение"));
             return;
        }
    else{
    sockCl->write( Name.toUtf8() + " " + ui->message->text().toUtf8());
    return;
    }

}

void Client::readSocket()
{
    QString data = QString(sockCl->readAll());
    if(chat == 0)
    {
        ui->textEdit->append(data);
    }
    else
    {
    QStringList myStringList = data.split(" ");
    QString name = myStringList.first();
    myStringList.first() = " ";
    QString str = myStringList.join(" ");
    str = "<div><font color=\"black\">"+str+"</font></div>";
    ui->textEdit->setTextColor(QColor(0,255,0));
    ui->textEdit->append(name);
    ui->textEdit->insertHtml(str);
    }
}

void Client::serverDisconnect()
{
    QMessageBox::information(NULL,QObject::tr("Информация"),tr("Вы покинули чат"));
}
