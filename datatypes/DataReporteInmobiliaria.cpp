//
// Created by leandro on 10/06/16.
//

#include "DataReporteInmobiliaria.h"

DataReporteInmobiliaria::DataReporteInmobiliaria(string name, string mail, string dir) {
    this->nombre = name;
    this->mail = mail;
    this->direccion = dir;
    this->propsPorZona.clear();
}

DataReporteInmobiliaria::~DataReporteInmobiliaria() {

}

list <DataPropPorZona> DataReporteInmobiliaria::getPropsPorZona() {
 return this->propsPorZona;
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

void DataReporteInmobiliaria::setPropsPorZona(list<DataPropPorZona> l) {
    this->propsPorZona = l;
}
