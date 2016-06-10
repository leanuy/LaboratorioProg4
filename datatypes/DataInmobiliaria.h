//
// Created by agus on 02/06/16.
//

#ifndef LAB6_DATAINMOBILIARIA_H
#define LAB6_DATAINMOBILIARIA_H


#include "DataUsuario.h"

class DataInmobiliaria: public DataUsuario {
private:
    string nombre;
    string direccion;
public:
    DataInmobiliaria(string email,string pass,string name, string dir);
    ~DataInmobiliaria();
    string getNombre();
    string getDireccion();
};


#endif //LAB6_DATAINMOBILIARIA_H
