#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QTextStream"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    color();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::color()
{
    ui->Black->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
    ui->White->setStyleSheet(QString::fromUtf8("background-color: rgb(250,250,250);"));
    ui->Red->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 50, 50);"));
    ui->Blue->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 250);"));
    ui->Green->setStyleSheet(QString::fromUtf8("background-color: rgb(102, 250, 100);"));
    ui->Orange->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 100, 50);"));
    ui->Red->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 50, 50);"));
    ui->Yellow->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 50);"));
    ui->Brow->setStyleSheet(QString::fromUtf8("background-color: rgb(150, 75, 0);"));
    ui->Save->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
    ui->Open->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
    ui->Close->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 50, 50);"));
    ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(250, 250, 250);"));
}
void MainWindow::on_Save_clicked()
{
    QString fileName = QFileDialog::getSaveFileName
                         (this, tr("Сохранить файл"),"",
                          tr("Images(* .png * .jpg)"));
        QImage image(ui->graphicsView->scene()->width(),
                     ui->graphicsView->scene()->height(),
                     QImage::Format_RGB32);
        image.fill(QColor(Qt::white).rgb());
        QPainter painter(&image);
        ui->graphicsView->scene()->render(&painter);
        painter.end();
        if(fileName.indexOf(".png") != -1 || fileName.indexOf(".jpg") != -1)
            image.save(fileName);
        else
            image.save(fileName.append(".png"));
}

void MainWindow::on_Open_clicked()
{
    QString fileName;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Открыть", "Создать новый файл?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        QString path = QCoreApplication::applicationDirPath();
        fileName = path+"NewCanvas.jpg";
        QFile mFile(path+"NewCanvas.jpg");
        mFile.open(QIODevice::WriteOnly);
    }
    else
    {
        fileName = QFileDialog::getOpenFileName
                    (this, tr("Открыть файл"),"",
                     tr("Images(* .png * .jpg)"));
    }
    Canvas* sceneImage = new Canvas;
    sceneImage->addPixmap(QPixmap(fileName));
    ui->graphicsView->setScene(sceneImage);
    sceneImage->setSize(ui->Size->text());
    sceneImage->setColor(ui->ColorPen->text());
    connect(ui->Size, &QLineEdit::textChanged,
                sceneImage, &Canvas::setSize);
    connect(ui->ColorPen, &QLineEdit::textChanged,
                sceneImage, &Canvas::setColor);
}

void MainWindow::on_Brow_clicked()
{
   ui->ColorPen->setText("brown");
   ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(120,50,20);"));
}

void MainWindow::on_Blue_clicked()
{
  ui->ColorPen->setText("blue");
  ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(50,50,250);"));
}

void MainWindow::on_Black_clicked()
{
  ui->ColorPen->setText("black");
  ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
}

void MainWindow::on_Yellow_clicked()
{
  ui->ColorPen->setText("yellow");
  ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(250,250,50);"));
}

void MainWindow::on_Red_clicked()
{
  ui->ColorPen->setText("red");
  ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(250,50,50);"));
}

void MainWindow::on_White_clicked()
{
 ui->ColorPen->setText("white");
 ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(250,250,250);"));
}

void MainWindow::on_Green_clicked()
{
 ui->ColorPen->setText("green");
 ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(102,250,50);"));
}

void MainWindow::on_Orange_clicked()
{
  ui->ColorPen->setText("orange");
  ui->Pen->setStyleSheet(QString::fromUtf8("background-color: rgb(250,100,50);"));
}

void MainWindow::setSize(){
    canvas->setSize(ui->Size->text());
}

void MainWindow::on_Close_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Закрыть", "Закрыть без сохранение?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes)
    {
        ui->graphicsView->setScene(this->canvas);
    }


}
