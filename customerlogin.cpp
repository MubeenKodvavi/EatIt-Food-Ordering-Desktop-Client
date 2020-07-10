#include "customerlogin.h"
#include "ui_customerlogin.h"
#include <QString>
#include <QStringList>
#include <QFile>
#include <QDebug>
#include <QMessageBox>
#include <QTextStream>

CustomerLogin::CustomerLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerLogin)
{
    ui->setupUi(this);
    QPixmap pix (":/resources/img/FULL LOGO.png");
    ui -> label_logo -> setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

CustomerLogin::~CustomerLogin()
{
    delete ui;
}

void CustomerLogin::on_pushButton_register_clicked()
{
    cregister = new CustomerRegister(this);
    cregister -> show();
    hide();
}

int CustomerLogin::wcount = 0; // static variable initialised

void CustomerLogin::on_pushButton_clicked()
{
    QFile bill("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\cart.txt");
    if(!bill.open(QFile::WriteOnly | QFile::Truncate)){
        qDebug() << "Error opening cart file";
    }
    QTextStream t(&bill);
    t << "";
    bill.close();

    QString uname = ui -> lineEdit_uname -> text();
    QString pass = ui -> lineEdit_pass -> text();

    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\userdata.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error opening file";
    }
    QTextStream r(&file);
    bool login = false;
    while(!r.atEnd()){
        QString text = r.readLine();
        QStringList record = text.split("_");
//        qDebug() << record[0] << " " << record[1];
        if(record[0] == uname && record[1] == pass){
            login = true;
            QMessageBox::information(this, "Logged in!", "You are logged in. Order quick and get your hands on the deals waiting for you.");
            filterr = new FilterRestaurants(this);
            filterr -> show();
            hide();
        }
    }
    file.close();
    if(login == false){
        wcount++;
        if(wcount == 3){
            QMessageBox::warning(this, "Exiting", "You have entered wrong password too many times. System will quit now");
            QApplication::quit();
        }
        QMessageBox::critical(this, "Invalid Credintials", "Wrong username or password.Please try again!");
    }
}
