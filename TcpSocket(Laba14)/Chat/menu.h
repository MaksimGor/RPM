#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
/**
 * @brief класс menu
 * @author Maxim Gordienko
 */
namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_connect_clicked();
private:
    Ui::menu *ui;
    QString Name;
};

#endif // MENU_H
