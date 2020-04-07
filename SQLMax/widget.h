#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlTableModel>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
signals:
    void ConnectDatabase_clicked();

    void comboBox_activated(const QString &arg1);

    void createBD_clicked();

    void Type_activated(const QString &arg1);

    void AddNote_clicked();

    void DeleteNote_clicked();

    void DropColumn_clicked();

    void ZaprosButton_clicked();

    void CreateTable_clicked();

    void Update_clicked();

    void DropTable_clicked();

    void CreateColums_clicked();

private slots:

    void on_ConnectDatabase_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_CreateBD_clicked();

    void on_Type_activated(const QString &arg1);

    void on_AddNote_clicked();

    void on_DeleteNote_clicked();

    void on_DropColumn_clicked();

    void on_ZaprosButton_clicked();

    void on_CreateTable_clicked();

    void on_Update_clicked();

    void on_DropTable_clicked();

    void on_CreateColums_clicked();

    void Model(const QString &arg1);

private:
    Ui::Widget *ui;
    QSqlDatabase db;
    QString DBpath;
    QSqlTableModel* model;
    int countTable;
    QString type;
};
#endif // WIDGET_H
