#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    double nb1, nb2;

    bool multi = false;
    bool equal = false;
    bool add = false;
    bool sub = false;
    bool comma = false;
    bool div = false;
    bool factorial = false;
    bool abs = false;
    bool x_times_y = false;
    bool reverse = false;
    bool squared = false;
    bool root = false;

private slots:
    void number_pressed();

    void multiplication();

    void equal_pressed();

    void plus_pressed();

    void minus_pressed();

    void comma_pressed();

    void div_pressed();

    void change_sign();

    void clear();

    void abs_pressed();

    void factorial_pressed();

    void xtimesy_pressed();

    void reverse_pressed();

    void squared_pressed();

    void root_pressed();

};
#endif // MAINWINDOW_H
