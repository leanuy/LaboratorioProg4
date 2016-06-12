//
// Created by leandro on 11/06/16.
//

#include "DataPropPorZona.h"

DataPropPorZona::DataPropPorZona() {
    this->idZona = "";
    this->cantidadAptos = 0;
    this->cantidadCasas = 0;
}

DataPropPorZona::DataPropPorZona(string idZ, int casas, int aptos) {
    this->idZona = idZ;
    this->cantidadAptos = casas;
    this->cantidadCasas = aptos;
}

DataPropPorZona::~DataPropPorZona() {

}

void DataPropPorZona::incrementCasas() {
    this->cantidadCasas++;
}

void DataPropPorZona::incrementAptos() {
    this->cantidadAptos++;
}

string DataPropPorZona::getIdZona() {
    return this->idZona;
}

int DataPropPorZona::getCantCasas() {
    return this->cantidadCasas;
}

int DataPropPorZona::getCantAptos() {
    return this->cantidadAptos;
}
