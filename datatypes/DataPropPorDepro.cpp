//
// Created by leandro on 11/06/16.
//

#include "DataPropPorDepro.h"

DataPropPorDepro::DataPropPorDepro(string idDepto) {
    this->idDepto = idDepto;
    this->porDeptos.clear();
}

DataPropPorDepro::~DataPropPorDepro() {

}

void DataPropPorDepro::setPropsPorDeptos(list <DataPropPorZona> l) {
    this->porDeptos = l;
}

string DataPropPorDepro::getIdDepto() {
    return this->idDepto;
}

list <DataPropPorZona> DataPropPorDepro::getPorDeptos() {
    return this->porDeptos;
}
