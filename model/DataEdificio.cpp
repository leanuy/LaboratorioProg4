//
// Created by leandro on 01/06/16.
//

#include "DataEdificio.h"

DataEdificio::DataEdificio(string name, int piso, float gastos) {
    this->pisos = piso;
    this->nombre = name;
    this->gastosComunes = gastos;
}

DataEdificio::~DataEdificio() {

}

string DataEdificio::getNombre() {
    return this->nombre;
}

int DataEdificio::getPisos() {
    return this->pisos;
}

float DataEdificio::getGastoComunes() {
    return this->gastosComunes;
}
