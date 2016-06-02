//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_DATAEDIFICIO_H
#define LAB6_DATAEDIFICIO_H

#include <string>

using namespace std;

class DataEdificio {
private:
    string nombre;
    int pisos;
    float gastosComunes;
public:
    DataEdificio(string name,int piso,float gastos);
    ~DataEdificio();
    string getNombre();
    int getPisos();
    float getGastoComunes();
};


#endif //LAB6_DATAEDIFICIO_H
