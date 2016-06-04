//
// Created by Santiago Serantes on 6/3/16.
//

#include "Sesion.h"

Sesion* Sesion::instance = NULL;
Sesion::Sesion(){}
Sesion* Sesion::getInstance(){
    if(instance == NULL){
        instance = new Sesion();
    }
    return instance;
}

Usuario* Sesion::getUsuario(){
    return user;
}
void Sesion::LogIn(Usuario* usr){
    user = usr;
}
void Sesion::LogOut(){
    user = NULL;
}

bool Sesion::esTipo(string tipo){
    return user->esTipo(tipo);
}

bool Sesion::isLogged() {
    return this->user != NULL;
}

