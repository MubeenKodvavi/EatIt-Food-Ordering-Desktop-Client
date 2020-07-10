#include "filterrestaurants.h"
#include "ui_filterrestaurants.h"
#include "restaurant.h"
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QString>

FilterRestaurants::FilterRestaurants(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FilterRestaurants)
{
    ui->setupUi(this);
    ui -> textBrowser_restaurants -> hide();
    ui -> pushButton_2 -> hide();
    ui -> label_3 -> hide();
    ui -> lineEdit -> hide();
    ui -> comboBox_filter -> addItem(QIcon(":/resources/icons/fast food.png"),"Fast Food");
    ui -> comboBox_filter -> addItem(QIcon(":/resources/icons/chinese.png"),"Chinese");
    ui -> comboBox_filter -> addItem(QIcon(":/resources/icons/pizza.png"),"Pizza");
    ui -> comboBox_filter -> addItem(QIcon(":/resources/icons/desi.png"),"Desi");
    ui -> comboBox_filter -> addItem(QIcon(":/resources/icons/japanese.png"),"Japanese");
}

FilterRestaurants::~FilterRestaurants()
{
    delete ui;
}

void FilterRestaurants::on_pushButton_clicked()
{
    ui -> textBrowser_restaurants -> setPlainText("");
    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurantdata.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error opening file!";
    }
    ui -> label_3 -> show();
    ui -> textBrowser_restaurants-> show();
    ui -> pushButton_2 -> show();
    ui -> lineEdit -> show();
    QTextStream r(&file);
    int count = 0;
    while (!file.atEnd()){
        QString line = file.readLine();
        QStringList record = line.split("_");
        record[2] = record[2].simplified();
        if(record[2] == ui->comboBox_filter->currentText()){
            count++;
            ui->textBrowser_restaurants->append(QString::number(count)+". " + record[0]);
        }
    }

}

void FilterRestaurants::on_pushButton_2_clicked()
{
    QString combo = ui -> comboBox_filter -> currentText();
    QString choice = ui -> lineEdit -> text();
    QFile file("C:\\Users\\mubee\\Documents\\FoodOrderingSystem\\files\\restaurantdata.txt");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << "Error opening file!";
    }
    QTextStream r(&file);
    int count = 0;
    while (!file.atEnd()){
        QString line = file.readLine();
        QStringList record = line.split("_");
        record[2] = record[2].simplified();
        if(record[2] == combo){
            count++;
            if(count == choice.toInt()){
                restaurant r(record[0], record[1], record[2]);
                rmenu = new RestaurantMenu(this, r);
                rmenu -> show();
                hide();
            }
        }
    }
}
