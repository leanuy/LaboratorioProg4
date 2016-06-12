//
// Created by leandro on 10/06/16.
//

#ifndef LAB6_DATAREPORTEINMOBILIARIA_H
#define LAB6_DATAREPORTEINMOBILIARIA_H

#include <string>
#include "../datatypes/DataPropPorZona.h"
#include "../datatypes/DataPropPorDepro.h"
#include <list>

using namespace std;
class DataReporteInmobiliaria {
private:
    string nombre;
    string mail;
    string direccion;
    list<DataPropPorDepro> propsPorDepto;
public:
    DataReporteInmobiliaria(string name,string mail,string dir);
    ~DataReporteInmobiliaria();
    list<DataPropPorDepro> getPropsPorDepto();
    string getNombre();
    string getMail();
    string getDireccion();
    void setPropsPorDepto(list<DataPropPorDepro> l);
};


#endif //LAB6_DATAREPORTEINMOBILIARIA_H
