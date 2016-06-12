//
// Created by leandro on 10/06/16.
//

#include "DataReporteInmobiliaria.h"

DataReporteInmobiliaria::DataReporteInmobiliaria(string name, string mail, string dir) {
    this->nombre = name;
    this->mail = mail;
    this->direccion = dir;
    this->propsPorDepto.clear();
}

DataReporteInmobiliaria::~DataReporteInmobiliaria() {

}

list <DataPropPorDepro> DataReporteInmobiliaria::getPropsPorZona() {
 return this->propsPorDepto;
}

string DataReporteInmobiliaria::getNombre() {
 return this->nombre;
}

string DataReporteInmobiliaria::getMail() {
 return this->mail;
}

string DataReporteInmobiliaria::getDireccion() {
 return this->direccion;
}

void DataReporteInmobiliaria::setPropsPorZona(list<DataPropPorDepro> l) {
    this->propsPorDepto = l;
}
