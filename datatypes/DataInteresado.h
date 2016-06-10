//
// Created by leandro on 10/06/16.
//

#ifndef LAB6_DATAINTERESADO_H
#define LAB6_DATAINTERESADO_H


#include "DataUsuario.h"

class DataInteresado: public DataUsuario {
private:
    string nombre;
    string apellido;
    int edad;
public:
    DataInteresado(string email, string password, string name,string apellido,int edad);
    ~DataInteresado();
    string getNombre();
    string getApellido();
    int getEdad();
};


#endif //LAB6_DATAINTERESADO_H
