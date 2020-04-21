#include "server.h"

#include <QApplication>
/**
 * @author Maxim Gordienko
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    server w;
    w.show();
    return a.exec();
}
