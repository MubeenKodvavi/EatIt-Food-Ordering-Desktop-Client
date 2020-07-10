#include "checkout.h"
#include "ui_checkout.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

Checkout::Checkout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Checkout)
{
    ui->setupUi(this);
    ui -> pushButton -> hide();
    ui -> label -> hide();
    ui -> lineEdit -> hide();
}

int Checkout::count = 0;

Checkout::~Checkout()
{
    delete ui;
}

void Checkout::on_pushButton_clicked()
{
    QString credit = ui -> lineEdit -> text();
    bool iscredit;
    credit.toLongLong(&iscredit);
    if(credit.length() == 14 && iscredit){
        QMessageBox::information(this,"Order placed","Your order will be delivered in 45 minutes. Get your cash ready.");
        QApplication::quit();
    }
    else{
        count++;
        if(count==3){
            QMessageBox::warning(this,"SPAM","Too many wrong credit card numbers attempted. You cant order now.");
            QApplication::quit();
        }
        QMessageBox::critical(this,"Incorrect","Incorrect, please enter a valid credit card number");
    }
}

void Checkout::on_pushButton_2_clicked()
{
    if(ui ->radioButton_2 -> isChecked() == true){
        ui -> pushButton -> show();
        ui -> label -> show();
        ui -> lineEdit -> show();
    }
    else if(ui ->radioButton -> isChecked() == true){
        QMessageBox::information(this,"Order placed","Your order will be delivered in 45 minutes. Get your cash ready.");
        QApplication::quit();
    }
}

void Checkout::on_pushButton_3_clicked()
{
    parentWidget() -> show();
    hide();
}

void Checkout::on_radioButton_toggled(bool checked)
{
    if(checked == true){
        ui -> pushButton -> hide();
        ui -> label -> hide();
        ui -> lineEdit -> hide();
    }
}
