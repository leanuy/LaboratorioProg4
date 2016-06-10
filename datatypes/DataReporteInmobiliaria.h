//
// Created by leandro on 10/06/16.
//

#ifndef LAB6_DATAREPORTEINMOBILIARIA_H
#define LAB6_DATAREPORTEINMOBILIARIA_H

#include <string>

using namespace std;
class DataReporteInmobiliaria {
private:
    string nombre;
    string mail;
    string direccion;

public:
    DataReporteInmobiliaria(string name,string mail,string dir);
    ~DataReporteInmobiliaria();


};


#endif //LAB6_DATAREPORTEINMOBILIARIA_H
