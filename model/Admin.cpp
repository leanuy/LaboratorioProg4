//
// Created by Santi on 01/06/2016.
//
#include "../model/Admin.h"

Admin::Admin(){}
bool Admin::esTipo(string tipo){
    return (tipo == "admin");
}