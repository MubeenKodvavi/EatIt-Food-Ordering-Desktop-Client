#include "customerregister.h"
#include "ui_customerregister.h"
#include <QString>
#include <QStringList>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

CustomerRegister::CustomerRegister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomerRegister)
{
    ui->setupUi(this);
    QPixmap pix (":/resources/img/FULL LOGO.png");
    ui -> label_logo -> setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

CustomerRegister::~CustomerRegister()
{
    delete ui;
}

void CustomerRegister::on_pushButton_register_clicked()
{
    QString uname = ui -> lineEdit_uname -> text();
    QString pass = ui -> lineEdit_pass -> text();
    QString address = ui -> lineEdit_address -> text();

    if(pass.length() < 8){
        QMessageBox::warning(this,"Password too short", "Please enter a password with length of 8 characters or more.");
    }
    else{
        QFile file1("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\userdata.txt");
        if(!file1.open(QFile::ReadOnly | QFile::Text)){
            qDebug() << "Error opening file";
        }

        QTextStream r(&file1);
        bool userpresent = false;
        while(!r.atEnd()){
            QString text = r.readLine();
            QStringList record = text.split("_");
            if (record[0] == uname){
                userpresent = true;
                QMessageBox::critical(this,"Username already exists","Username is already taken. Please enter a different username");
                break;
            }
        }
        file1.close();
        if (userpresent == false){
            QFile file2("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\userdata.txt");
            if(!file2.open(QFile::Append )){
                qDebug() << "Error opening file";
            }
            QTextStream w(&file2);
            w << uname << "_" << pass << "_" << address << endl;
            file2.close();
            QMessageBox::information(this,"Account created", "Registration successfull! You can login using the details now.");
            parentWidget() -> show();
            hide();
        }
    }
}
