#include <QUrl>
#include <QDebug>
#include <QString>
#include "ui_widget.h"
#include "widget.h"
#include <QUrlQuery>
#include <QLabel>
#include <QLibrary>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkReply>

 VKauf::VKauf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VKauf)
{
    ui->setupUi(this);
    connect(this, SIGNAL(auth_success()),this,SLOT(on_Poisk_clicked()));
 }

VKauf::~VKauf()
{
    delete ui;
}
void VKauf::on_Poisk_clicked()
{
  userName = ui->ID_users->text();
  get_user();
  get_friends();
}
void VKauf::onResult(QNetworkReply *reply)
{
    ui->textEdit->clear();
    if(!reply->error()){
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        QJsonObject root = document.object();
        QJsonObject jv = root["response"].toObject();
        QJsonArray ja = jv["items"].toArray();
            for(int i = 0; i < ja.count(); i++){
                QJsonObject subtree = ja.at(i).toObject();
                QString q = QString::number(subtree.value("id").toInt());
                ui->textEdit->append("id: "+ q);
                ui->textEdit->append(subtree.value("first_name").toString()+" "+subtree.value("last_name").toString());
        }
    }
    reply->deleteLater();
}

void VKauf::onResultUser(QNetworkReply *replyUs)
{
    if(!replyUs->error()){
        QJsonDocument document = QJsonDocument::fromJson(replyUs->readAll());
        QJsonObject root = document.object();
        QJsonArray ja = root["response"].toArray();
            for(int i = 0; i < ja.count(); i++){
                QJsonObject subtree = ja.at(i).toObject();
                ui->label_2->setText(subtree.value("first_name").toString());
                ui->label_5->setText(subtree.value("last_name").toString());
                ui->label_7->setText(subtree.value("bdate").toString());
                if(subtree.value("sex").toInt() == 2){ui->label_9->setText("Мужской");}
                else{ui->label_9->setText("Женсий");}
                if(subtree.value("online").toInt() == 0){ui->label->setText("online");}
                else{ui->label->setText("offline");}
                ui->Photo->load(QUrl(subtree.value("photo_max_orig").toString()));
        }
    }
    replyUs->deleteLater();
}

void VKauf::get_user()
{
    QUrl current("https://api.vk.com/method/users.get");
        QUrlQuery Param;
        Param.addQueryItem("user_id", userName);
        Param.addQueryItem("access_token",token);
        Param.addQueryItem("v","5.2");
        Param.addQueryItem("fields","photo_max_orig,bdate, sex, online");
        current.setQuery(Param);
        networkManagerUS = new QNetworkAccessManager();
        connect(networkManagerUS, &QNetworkAccessManager::finished, this, &VKauf::onResultUser);
        networkManagerUS->get(QNetworkRequest(current));
}


void VKauf::get_friends()
{
    QUrl current("https://api.vk.com/method/friends.get");
    QUrlQuery Param;
    Param.addQueryItem("user_id", userName);
    Param.addQueryItem("access_token",token);
    Param.addQueryItem("v","5.2");
    Param.addQueryItem("fields","1");
    current.setQuery(Param);
    networkManagerFr = new QNetworkAccessManager();
    connect(networkManagerFr, &QNetworkAccessManager::finished, this, &VKauf::onResult);
    networkManagerFr->get(QNetworkRequest(current));
}


