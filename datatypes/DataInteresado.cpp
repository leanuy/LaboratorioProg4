//
// Created by leandro on 10/06/16.
//

#include "DataInteresado.h"

DataInteresado::DataInteresado(string email, string password, string name, string apellido, int edad) {
    this->setEmail(email);
    this->setPassword(password);
    this->nombre = name;
    this->apellido = apellido;
    this->edad = edad;
}

DataInteresado::~DataInteresado() {

}

string DataInteresado::getNombre() {
    return this->nombre;
}

string DataInteresado::getApellido() {
    return this->apellido;
}

int DataInteresado::getEdad() {
    return this->edad;
}
