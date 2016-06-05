//
// Created by leandro on 01/06/16.
//

#include "Usuario.h"


void Usuario::setEmail(string mail) {
    this->email = mail;
}

string Usuario::getEmail() {
    return this->email;
}

void Usuario::setContrasenia(string contra) {
    this->contrasenia = contra;
}

string Usuario::getContrasenia() {
    return this->contrasenia;
}

bool Usuario::FirstTime() {
    return this->firstLogin;
}

bool Usuario::AsignarPassword(string pass1, string pass2) {
    if(!pass1.compare(pass2)){
        this->contrasenia = pass1;
        return true;
    }else{
        return false;
    }
}

bool Usuario::CheckPassword(string pass) {
    return !pass.compare(this->contrasenia);
}

Usuario::~Usuario() { }