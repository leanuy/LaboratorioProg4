//
// Created by leandro on 01/06/16.
//

#include "DataZona.h"

DataZona::DataZona(string code,string name) {
    this->codigo = code;
    this->nombre = name;
}

DataZona::~DataZona() {

}

string DataZona::getCodigo() {
    return this->codigo;
}

string DataZona::getNombre() {
    return this->nombre;
}
