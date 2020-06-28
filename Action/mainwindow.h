#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QHBoxLayout"
#include "QVBoxLayout"
#include "QWidget"
#include "QTableWidget"
#include "QPushButton"
#include "QString"
#include "QFileDialog"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTableWidget* tableWidget;
    QVBoxLayout* vLayout;
    QWidget* widjet;
    int rowCount=1;
    int columnCount=1;
    QString link;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void addColumn();
    void addRow();
    void save();

private:

};
#endif // MAINWINDOW_H
