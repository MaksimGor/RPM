#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtNetwork>
#include <iostream>
#include "menu.h"
namespace Ui {
class Client;
}

class Client : public QDialog
{
    Q_OBJECT


public:
    Client(QWidget *parent = nullptr);
    ~Client();

private:
    Ui::Client *ui;
    QTcpSocket *sockCl;
    QString Name;
    int chat = 0;
private slots:
    void ButtonAction();
    void readSocket();
    void serverDisconnect();
};

#endif // DIALOG_H
