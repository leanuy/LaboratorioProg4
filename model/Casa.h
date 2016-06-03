//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_CASA_H
#define LAB6_CASA_H
#include "../model/Propiedad.h"
#include "../datatypes/DataCasa.h"
#include <string>

using namespace std;
class Casa : public Propiedad {
private:
    float metrosCuadradosVerdes;
public:
    Casa(int ambientes,int dormitorios,int banios,bool garage,
         string direccion,float m2Edificados,float m2Totales,
         float m2Verdes);
    float getMetrosCuadradosVerdes();
    void setMetrosCuadradosVerdes(float m2verdes);
    DataCasa CrearDataCasa();
    ~Casa();
};


#endif //LAB6_CASA_H
