//
// Created by agus on 02/06/16.
//

#include "DataInmobiliaria.h"

DataInmobiliaria::DataInmobiliaria(string email, string pass, string name, string dir) {
    this->setEmail(email);
    this->setPassword(pass);
    this->nombre = name;
    this->direccion = dir;
}

DataInmobiliaria::~DataInmobiliaria() {

}

string DataInmobiliaria::getNombre() {
 return this->nombre;
}

string DataInmobiliaria::getDireccion() {
 return this->direccion;
}
