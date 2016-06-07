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
        instance->inicializarDataBaseConAdmin();
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

void Sesion::inicializarDataBaseConAdmin() {
    Database* db = Database::getInstance();
    Usuario* admin = new Admin();
    admin->setEmail("admin");
    admin->setContrasenia("admin");
    db->AddUsuario(admin);
}
