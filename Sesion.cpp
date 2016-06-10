//
// Created by Santiago Serantes on 6/3/16.
//

#include "Sesion.h"
#include "Database.h"
Sesion* Sesion::instance = NULL;
Sesion::Sesion(){}
Sesion* Sesion::getInstance(){
    if(instance == NULL){
        instance = new Sesion();
        Database* db = Database::getInstance();
        db->AddData();
        instance->LogOut();
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