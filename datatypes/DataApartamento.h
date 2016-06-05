//
// Created by agus on 02/06/16.
//

#ifndef LAB6_DATAAPARTAMENTO_H
#define LAB6_DATAAPARTAMENTO_H


#include "DataPropiedad.h"

class DataApartamento: public DataPropiedad {
public:
    DataApartamento(int ambientes,int dormitorios,int banios,bool garage,
                string direccion,float m2Edificados,float m2Totales);
    ~DataApartamento();
};


#endif //LAB6_DATAAPARTAMENTO_H
