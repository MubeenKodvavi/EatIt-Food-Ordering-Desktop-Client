#include "restaurantlogin.h"
#include "ui_restaurantlogin.h"
#include "restaurant.h"
#include <QFile>
#include <QDebug>
#include <QMessageBox>

RestaurantLogin::RestaurantLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RestaurantLogin)
{
    ui->setupUi(this);
    QPixmap pix (":/resources/img/FULL LOGO.png");
    ui -> label_logo -> setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

int RestaurantLogin::wcount = 0;

RestaurantLogin::~RestaurantLogin()
{
    delete ui;
}

void RestaurantLogin::on_pushButton_login_clicked()
{
    QString uname = ui -> lineEdit_rid -> text();
    QString pass = ui -> lineEdit_password -> text();

    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurantdata.txt");
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
            QMessageBox::information(this, "Logged in!", "You are logged in");
            restaurant r(record[0], record[1], record[2]);
            menu = new Menu(this, r);
            menu -> show();
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
