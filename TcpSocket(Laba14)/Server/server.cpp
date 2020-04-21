#include "server.h"
#include <QDebug>
#include <QTime>
/**
 * @brief Реализация Сервера
 * @author Maxim Gordienko
 */
server::server(QWidget *parent): QWidget(parent)
{
    tcpServer = new QTcpServer(this);

    connect(tcpServer, &QTcpServer::newConnection,
            this, &server::connectUser);

    if (tcpServer->listen(QHostAddress::Any, 33333)) {
        qDebug() <<  QObject::tr("Unable to start the server: %1.").arg(tcpServer->errorString());
    }
    else {
        qDebug() << QString::fromUtf8("Сервер запущен!");
    }
    connect(this, &server::serverClose,
                this, &QCoreApplication::quit);
    clients.clear();
    list.clear();
}
/**
 * @brief Закрытие сервера
 * @author Maxim Gordienko
 */
server::~server()
{
    emit serverClose();
}
/**
 * @brief Подключение пользователя
 * @author Maxim Gordienko
 */
void server::connectUser()
{
    qInfo() << QString::fromUtf8("У нас новое соединение!");
    foreach (client, clients) {
            QTcpSocket* clientSock = (QTcpSocket*) client;
            QTextStream str (clientSock);
            str << QString::fromUtf8(" Один новый пользователь");
        }

    client = tcpServer->nextPendingConnection();
    clients.push_back(client);
    this->Message();

    connect(client, &QTcpSocket::readyRead,this, &server::ClientAction);
    connect(client, &QTcpSocket::disconnected,this, &server::disconnectUser);
}
/**
 * @brief Работа с Клиентом
 * @author Maxim Gordienko
 */
void server::ClientAction()
{
    setlocale(LC_ALL,"Russian");
    k++;
    QTcpSocket* clientSocket = (QTcpSocket*) sender();
    QTextStream stream (clientSocket);
    QString nickname;
    QString message;
    for (int i = 0;i < 2;i++){
        if (i == 0) stream >> nickname;
        else if (i == 1) stream >> message;
    }
    qInfo() << QString::fromUtf8( "Получить сообщение от ") << nickname << "- " << message;

    foreach (client, clients){
        QTcpSocket* clSock = (QTcpSocket*) client;
        QTextStream str (clSock);
        str << nickname + " - " + message;
    }

    file.setFileName("Client.txt");
    list.push_back(nickname + " " + message);

    if(!file.open(QIODevice::WriteOnly)){
        qInfo() << QString::fromUtf8("Файл не открывается...");
    }

    if (k > 10){
        list.removeFirst();
    }

    QTextStream _stream_(&file);
    foreach(QString str, list){
        if (str != ""){
           _stream_ << str << endl;
       }
    }
    file.close();
}
/**
 * @brief Закрытие сервера по условию
 * @author Maxim Gordienko
 */
void server::disconnectUser() {
    setlocale(LC_ALL,"Russian");
    qInfo() << QString::fromUtf8( "Пользователь покинул чат");

    foreach (client, clients) {
        QTcpSocket* clientSock = (QTcpSocket*) client;
        QTextStream str (clientSock);
        str << QString::fromUtf8( "    Осталься один пользователь");
    }
    clients.removeOne(client);
    client->disconnect();
    if(clients.size() == 0)
        emit serverClose();
}
/**
 * @brief Работа с сообщениями
 * @author Maxim Gordienko
 */
void server::Message() {
    setlocale(LC_ALL,"Russian");
    file.setFileName("Client.txt");
    if(!file.open(QIODevice::ReadOnly)){
        qInfo() << QString::fromUtf8("Файл не открывается...");
    }

    QTcpSocket* clSock = (QTcpSocket*) client;
    QTextStream str (clSock);
    QTextStream stream(&file);
    int i = 0;
    while(!stream.atEnd()){
        QString st;
        i++;
        stream >> st;
        if (((i % 2) == 1)&&(st != ""))
        {
            str << st + " - ";
        }
        else {
            str << st;
            if(!stream.atEnd())
                str<<endl;
        }
    }
    if(k == 0)
        k += i/2;
    file.close();
}

