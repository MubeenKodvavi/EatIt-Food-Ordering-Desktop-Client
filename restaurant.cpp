#include "restaurant.h"

restaurant::restaurant()
{

}

restaurant::restaurant(QString name, QString pass, QString type){
    this -> name = name;
    this -> pass = pass;
    this -> type = type;
}
void restaurant::setname(QString name){
    this -> name = name;
}
void restaurant::setpass(QString pass){
    this -> pass = pass;
}
void restaurant::settype(QString type){
    this -> type = type;
}
QString restaurant::getname(){
    return name;
}
QString restaurant::getpass(){
    return pass;
}
QString restaurant::gettype(){
    return type;
}
