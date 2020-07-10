#include "menu.h"
#include "ui_menu.h"
#include "restaurant.h"

Menu::Menu(QWidget *parent, restaurant &r) : //Constructor overloaded to receive class.
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    r1.setname(r.getname());
    r1.setpass(r.getpass());
    r1.settype(r.gettype());
    QPixmap pix (":/resources/logos/" + r1.getname() + ".png");
    ui -> label -> setPixmap(pix.scaled(200,200,Qt::KeepAspectRatio));
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    addm = new AddMenu(this, r1);
    addm -> show();
    hide();
}

void Menu::on_pushButton_3_clicked()
{
    addd = new AddDeals(this, r1);
    addd -> show();
    hide();
}
