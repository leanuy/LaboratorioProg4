//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_APARTAMENTO_H
#define LAB6_APARTAMENTO_H

#include "../model/Propiedad.h"
#include "../model/Edificio.h"

class Apartamento: public Propiedad {
private:
    Edificio* edif;

public:
    Apartamento(int ambientes,int dormitorios,int banios,bool garage,
                string direccion,float m2Edificados,float m2Totales);
    void setEdificio(Edificio* e);
    Edificio* getEdificio();
    DataApartamento CrearDataApartamento();
    ~Apartamento();


};


#endif //LAB6_APARTAMENTO_H
