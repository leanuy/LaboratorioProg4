//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_APARTAMENTO_H
#define LAB6_APARTAMENTO_H

#include "Propiedad.h"
#include "Edificio.h"

class Apartamento: public Propiedad {
private:
    Edificio* edif;

public:
    Apartamento(int ambientes,int dormitorios,int banios,bool garage,
                string direccion,float m2Edificados,float m2Totales);
    void setEdificio(Edificio* e);
    Edificio* getEdificio();
    ~Apartamento();


};


#endif //LAB6_APARTAMENTO_H
