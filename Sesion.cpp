//
// Created by Santiago Serantes on 6/3/16.
//

#include "Sesion.h"

Sesion* Sesion::user = NULL;
Sesion::Sesion{};

Usuario* Sesion::getUsuario(){
    return user;
}
void Sesion::LogIn(Usuario* usr){
    user = usr;
}
void Sesion::LogOut(){
    user = NULL;
}