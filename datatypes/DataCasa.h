//
// Created by agus on 02/06/16.
//

#ifndef LAB6_DATACASA_H
#define LAB6_DATACASA_H


#include "DataPropiedad.h"

class DataCasa: public DataPropiedad {
private:
    float metrosCuadradosVerdes;
public:
    DataCasa(int ambientes,int dormitorios,int banios,bool garage,
             string direccion,float m2Edificados,float m2Totales,
             float m2Verdes);
    ~DataCasa();
    float getM2Verdes();
};


#endif //LAB6_DATACASA_H
