//
// Created by Santi on 01/06/2016.
//
#include "../model/Admin.h"

Admin::Admin(){
    this->setEmail("adm1@sis.com");
    this->setFirstTime(false);
    this->setContrasenia("pass1");
}
bool Admin::esTipo(string tipo){
    return (tipo == "admin");
}