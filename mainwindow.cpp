#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customerlogin.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix (":/resources/img/FULL LOGO.png");
    ui -> label_logo -> setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_customer_clicked()
{
    clogin = new CustomerLogin(this);
    clogin -> show();
    hide();
}

void MainWindow::on_pushButton_restaurant_clicked()
{
    rlogin = new RestaurantLogin(this);
    rlogin -> show();
    hide();
}

void MainWindow::on_pushButton_exit_clicked()
{
    QApplication::quit();
}
