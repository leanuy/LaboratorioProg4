//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_EDIFICIO_H
#define LAB6_EDIFICIO_H

#include "Apartamento.h"
#include <string>
#include "Zona.h"

using namespace std;

class Edificio {
private:
    string nombre;
    int pisos;
    float gastosComunes;
    //coleccion apartamentos...
    Zona* zonaDelEdificio;
public:
    Edificio(string nombre,int pisos,float gastos);
    ~Edificio();
    void setNombre(string name);
    string getNombre();
    void setPisos(int pisos);
    int getPisos();
    void setGastosComunes(float gastos);
    float getGastoComunes();
    void setZona(Zona* z);
    Zona* getZona();


    void addApartamento(Apartamento* apto);  // agregar al dcd
};


#endif //LAB6_EDIFICIO_H
