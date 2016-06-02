//
// Created by leandro on 01/06/16.
//

#include "DataDepartamento.h"

DataDepartamento::DataDepartamento(string id, string nombre) {
    this->id = id;
    this->nombre = nombre;
}

DataDepartamento::~DataDepartamento() {

}

string DataDepartamento::getId() {
    return this->id;
}

string DataDepartamento::getNombre() {
    return this->nombre;
}
