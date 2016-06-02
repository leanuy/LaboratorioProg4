//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_EDIFICIO_H
#define LAB6_EDIFICIO_H

#include <string>
#include <map>
#include "../datatypes/DataEdificio.h"
//#include "../model/Apartamento.h"
//#include "../model/Zona.h"

using namespace std;

class Edificio {
private:
    string nombre;
    int pisos;
    float gastosComunes;
//    map<string,Apartamento*> apartamentos;
public:
    Edificio(string nombre,int pisos,float gastos);
    ~Edificio();
    void setNombre(string name);
    string getNombre();
    void setPisos(int pisos);
    int getPisos();
    void setGastosComunes(float gastos);
    float getGastoComunes();
//    void setZona(Zona* z);
//    Zona* getZona();
    DataEdificio CrearDataEdificio();


//    void addApartamento(Apartamento* apto);  // agregar al dcd
};


#endif //LAB6_EDIFICIO_H
