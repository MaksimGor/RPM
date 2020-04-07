#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QUrl>
#include <QString>
#include <QUrlQuery>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QEventLoop>
#include <QLabel>
#include <QLineEdit>
namespace Ui {
class VKauf;
}

class VKauf: public QWidget
{
    Q_OBJECT

public:
    explicit VKauf(QWidget *parent = 0);
    ~VKauf();
signals:
    void auth_success();

private:
    Ui::VKauf *ui;
    QString token;
    QString user_id;
    QString userName;
    QNetworkAccessManager *networkManagerFr;
    QNetworkAccessManager *networkManagerUS;
private slots:
    void on_Poisk_clicked();
    void onResult(QNetworkReply *reply);
    void onResultUser(QNetworkReply *replyUs);


public slots:
    QByteArray GET(QUrl r);
    void check_url(QUrl url); //принимает урл текущей страницы
    void get_user();
    void get_friends();
};

#endif // WIDGET_H
