#include "menu.h"

#include <QApplication>
/**
 * @author Maxim Gordienko
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    menu w;
    w.show();
    return a.exec();
}
