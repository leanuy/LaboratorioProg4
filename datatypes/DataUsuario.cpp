//
// Created by leandro on 10/06/16.
//

#include "DataUsuario.h"

DataUsuario::~DataUsuario() {

}

string DataUsuario::getEmail() {
    return this->email;
}

string DataUsuario::getPassword() {
    return this->contrasenia;
}

void DataUsuario::setEmail(string mail) {
    this->email = mail;
}

void DataUsuario::setPassword(string pass) {
    this->contrasenia = pass;
}
