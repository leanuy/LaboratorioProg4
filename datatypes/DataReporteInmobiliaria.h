//
// Created by leandro on 10/06/16.
//

#ifndef LAB6_DATAREPORTEINMOBILIARIA_H
#define LAB6_DATAREPORTEINMOBILIARIA_H

#include <string>
#include "../datatypes/DataPropPorZona.h"
#include <list>

using namespace std;
class DataReporteInmobiliaria {
private:
    string nombre;
    string mail;
    string direccion;
    list<DataPropPorZona> propsPorZona;
public:
    DataReporteInmobiliaria(string name,string mail,string dir);
    ~DataReporteInmobiliaria();
    list<DataPropPorZona> getPropsPorZona();
    string getNombre();
    string getMail();
    string getDireccion();
    void setPropsPorZona(list<DataPropPorZona> l);
};


#endif //LAB6_DATAREPORTEINMOBILIARIA_H
