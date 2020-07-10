#include "user.h"

user::user(QString uname, QString pass, QString address){
    this -> uname = uname;
    this -> pass = pass;
    this -> address = address;
}

void user::setuname(QString uname){
    this -> uname = uname;
}

void user::setpass(QString pass){
    this -> pass = pass;
}

QString user::getuname(){
    return uname;
}

QString user::getpass(){
    return pass;
}
