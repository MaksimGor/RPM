#include "mainwindow.h"

#include <QApplication>

/**
 * @file main.cpp
 * @author Гордиенко максим
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
