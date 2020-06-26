#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chart = new QChart();
    createMassiv();
    series = new QBarSeries();
    series->append(getDiagram());
    chart->addSeries(series);
    chart->setTitle("Среднее значение по сортировке");
    sett();
}
void MainWindow::sett()
{
    createX();
    createY();
    chartView = new QChartView(ui->widget);
    chartView->setRenderHint(QPainter::Antialiasing);
    chart->legend()->setVisible(0);
    chartView->setChart(chart);
    chartView->resize(ui->widget->size());
    sett2();
}
void MainWindow::sett2()
{
    thread=new QThread();
    Sort=new sort(nullptr,massiv,n);
    Sort->moveToThread(thread);
    timer=new QTimer();
    sortMassiv();
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createX()
{

    QStringList categories;
    for(int i=1;i<=n/size;i++){
        categories.append(QString::number(i));
    }
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    delete axisX;
}

void MainWindow::createY()
{
    QValueAxis *axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
}

void MainWindow::createMassiv()
{
    massiv=new int[n];
    QRandomGenerator generator;

    for(int i=0;i<n;i++){
        massiv[i]=generator.bounded(1,938302);
    }
}

bool MainWindow::event(QEvent *event)
{
    if(event->type()==QEvent::Resize)
        chartView->resize(ui->widget->size());
    return QMainWindow::event(event);
}

void MainWindow::sortMassiv()
{
    connect(ui->start,&QPushButton::clicked,this,&MainWindow::beginSort);
    connect(ui->exit,&QPushButton::clicked,this,&MainWindow::endSort);
    connect(thread, &QThread::started, Sort,&sort::run);
    connect(timer,&QTimer::timeout,Sort,&sort::getMassiv, Qt::DirectConnection);
    connect(Sort,&sort::nowMassiv,this,&MainWindow::getMassiv, Qt::DirectConnection);
    connect(Sort,&sort::finished,this,&MainWindow::stopTimer);
    connect(Sort,&sort::finished,Sort,&sort::getMassiv, Qt::DirectConnection);
    connect(Sort,&sort::finished,this,&MainWindow::resultSort);
}

void MainWindow::beginSort()
{
    Sort->setRunning(true);
    thread->start();
    timer->start(3000);
    ui->start->deleteLater();
}

void MainWindow::endSort()
{
    if(end==0){
    timer->stop();
    Sort->setRunning(false);
    thread->exit();
    thread->wait(4000);
    qInfo()<<thread->isRunning();
    }
    this->close();
}

void MainWindow::getMassiv(int *mass)
{
    massiv=mass;
    series->remove(set);
    series->insert(0,getDiagram());
}

QBarSet* MainWindow::getDiagram()
{
    set = new QBarSet("This");
    int k=0,p=1000,iter=0;
    avgForValues(k,p,iter);
    QColor col;
    col.setRgb(0,0,0);
    set->setColor(col);
    return set;
}

void MainWindow::avgForValues(int k,int p,int iter)
{
    while(p<=n){
        int buf=0;
        for (int i=k;i<p;i++)
            buf+=massiv[i];
        buf=buf/1000;
        set->insert(iter,buf);
        iter++;
        k=p;
        p+=1000;
    }
}

void MainWindow::stopTimer()
{
    timer->stop();
    qInfo()<<"Timer is:"+QString::number(timer->isActive());
}

void MainWindow::resultSort()
{
    thread->exit();
    thread->wait(4000);
    qInfo()<<thread->isRunning();
    end=1;
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    QString s = arg1;
    bool success= false;
    size = s.toInt(&success);
    createX();
}
