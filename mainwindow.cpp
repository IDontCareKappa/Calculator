#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cmath>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Connecting singals with number buttons

    connect(ui->number_0, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_1, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_2, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_3, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_4, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_5, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_6, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_7, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_8, SIGNAL(released()), this, SLOT(number_pressed()));
    connect(ui->number_9, SIGNAL(released()), this, SLOT(number_pressed()));

    //Connecting signals with function buttons

    connect(ui->button_multi, SIGNAL(released()), this, SLOT(multiplication()));
    connect(ui->button_equal, SIGNAL(released()), this, SLOT(equal_pressed()));
    connect(ui->button_plus, SIGNAL(released()), this, SLOT(plus_pressed()));
    connect(ui->button_minus, SIGNAL(released()), this, SLOT(minus_pressed()));
    connect(ui->button_div, SIGNAL(released()), this, SLOT(div_pressed()));
    connect(ui->button_comma, SIGNAL(released()), this, SLOT(comma_pressed()));
    connect(ui->change_sign, SIGNAL(released()), this, SLOT(change_sign()));
    connect(ui->clear, SIGNAL(released()), this, SLOT(clear()));
    connect(ui->button_abs, SIGNAL(released()), this, SLOT(abs_pressed()));
    connect(ui->button_factorial, SIGNAL(released()), this, SLOT(factorial_pressed()));
    connect(ui->button_xtimesy, SIGNAL(released()), this, SLOT(xtimesy_pressed()));
    connect(ui->button_reverse, SIGNAL(released()), this, SLOT(reverse_pressed()));
    connect(ui->button_squared, SIGNAL(released()), this, SLOT(squared_pressed()));
    connect(ui->button_root, SIGNAL(released()), this, SLOT(root_pressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::number_pressed()
{
    QPushButton *button = (QPushButton*)sender();

    QString numberString;

    nb2 = (ui->label->text() + button->text()).toDouble();

    numberString = QString::number(nb2, 'g', 15);

    ui->label->setText(numberString);
}

void MainWindow::multiplication()
{
    nb1 = ui->label->text().toDouble();
    ui->label_2->setText(QString::number(nb1));
    ui->label->setText("");
    multi = true;
    comma = false;
}

void MainWindow::plus_pressed()
{
    nb1 = ui->label->text().toDouble();
    ui->label_2->setText(QString::number(nb1));
    ui->label->setText("");
    add = true;
    comma = false;
}

void MainWindow::minus_pressed()
{
    nb1 = ui->label->text().toDouble();
    ui->label_2->setText(QString::number(nb1));
    ui->label->setText("");
    sub = true;
    comma = false;
}

void MainWindow::div_pressed()
{
    nb1 = ui->label->text().toDouble();
    ui->label_2->setText(QString::number(nb1));
    ui->label->setText("");
    div = true;
    comma = false;
}

void MainWindow::comma_pressed()
{
    if( !comma ){
        ui->label->setText(ui->label->text() + ".");
        comma = true;
    }
}

void MainWindow::abs_pressed()
{
    nb1 = ui->label->text().toDouble();

    if( nb1 < 0 ){
        nb1 *= -1;
        ui->label->setText(QString::number(nb1, 'g', 15));
    }
}

void MainWindow::factorial_pressed()
{
    nb1 = ui->label->text().toDouble();
    int i = 1, n = 1;
    while( i <= nb1 ){
        n *= i;
        i++;
    }
    ui->label->setText(QString::number(n, 'g', 15));
    comma = false;
}

void MainWindow::xtimesy_pressed()
{
    nb1 = ui->label->text().toDouble();
    ui->label_2->setText(QString::number(nb1));
    ui->label->setText("");
    x_times_y = true;
    comma = false;
}

void MainWindow::reverse_pressed()
{
    nb1 = ui->label->text().toDouble();
    nb1 = 1 / nb1;
    ui->label->setText(QString::number(nb1, 'g', 15));
}

void MainWindow::squared_pressed()
{
    nb1 = ui->label->text().toDouble();
    nb1 *= nb1;
    ui->label->setText(QString::number(nb1, 'g', 15));
}

void MainWindow::root_pressed()
{
    nb1 = ui->label->text().toDouble();
    nb1 = sqrt(nb1);
    ui->label->setText(QString::number(nb1, 'g', 15));
}

void MainWindow::equal_pressed()
{
    if( multi ){
        ui->label_2->setText("");
        ui->label->setText(QString::number(nb1 * nb2, 'g', 15));
        multi = false;
    } else if ( add ) {
        ui->label_2->setText("");
        ui->label->setText(QString::number(nb1 + nb2, 'g', 15));
        add = false;
    } else if ( sub ){
        ui->label_2->setText("");
        ui->label->setText(QString::number(nb1 - nb2, 'g', 15));
        sub = false;
    } else if ( div ){
        ui->label_2->setText("");
        ui->label->setText(QString::number(nb1 / nb2, 'g', 15));
        div = false;
    } else if ( x_times_y ){
        ui->label_2->setText("");
        int i = 1, n = nb1;
        while( i < nb2 ){
            nb1 *= n;
            i++;
        }
        ui->label->setText(QString::number(nb1, 'g', 15));
        x_times_y = false;
    }
}

void MainWindow::change_sign()
{
    double number = ui->label->text().toDouble();
    number *= -1;
    ui->label->setText(QString::number(number, 'g', 15));
}

void MainWindow::clear()
{
    ui->label->setText("");
}
