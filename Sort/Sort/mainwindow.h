#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCharts/QtCharts>
#include<QDebug>
#include<QRandomGenerator>
#include"sort.h"

QT_CHARTS_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**
     * @brief event Обработка событий
     * @return Событие
     */
    bool event(QEvent *event) override;
    /**
     * @brief sortMassiv Connect для выполнения сортировки
     */
    void sortMassiv();
    /**
     * @brief getDiagram Определение множества значений для диаграммы
     * @return Множество
     */
    QBarSet* getDiagram();
    /**
     * @brief avgForValues Вычисление среднего значения
     */
    void avgForValues(int,int,int);
    /**
     * @brief createX Создание оси X
     */
    void createX();
    /**
     * @brief createY Создание оси Y
     */
    void createY();
    /**
     * @brief createMassiv Создание массива
     */
    void createMassiv();
public slots:
    /**
     * @brief beginSort Начало сортировки
     */
    void beginSort();
    /**
     * @brief endSort Прерывание сортировки
     */
    void endSort();
    /**
     * @brief resultSort Окончание сортировки
     */
    void resultSort();
    /**
     * @brief getMassiv Получение массива
     * @param mass Массив
     */
    void getMassiv(int* mass);
    /**
     * @brief stopTimer Остановка таймера
     */
    void stopTimer();
    void sett();
    void sett2();
private slots:
    void on_comboBox_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QChart *chart;
    QChartView *chartView;
    int *massiv;
    int n=500000;
    QThread *thread;
    sort *Sort;
    QTimer *timer;
    QBarSeries *series;
    QBarSet *set;
    int size=4000;
    bool end=0;

};
#endif // MAINWINDOW_H
