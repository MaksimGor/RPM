#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <canvas.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Save_clicked();
    void on_Open_clicked();
    void color();
    void on_Brow_clicked();

    void on_Blue_clicked();

    void on_Black_clicked();

    void on_Yellow_clicked();

    void on_Red_clicked();

    void on_White_clicked();

    void on_Green_clicked();

    void on_Orange_clicked();

    void setSize();
    void on_Close_clicked();

private:
    Ui::MainWindow *ui;
    Canvas* canvas;
    QString Color = "White";
    QString ColorP = "White";
    QString Size = "1";
};
#endif // MAINWINDOW_H
