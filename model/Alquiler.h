//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_ALQUILER_H
#define LAB6_ALQUILER_H

#include "Propiedad.h"
#include "Inmobiliaria.h"

class Propiedad;
class Inmobiliaria;

class Alquiler {
private:
    float precio;
    Propiedad* prop;
public:
    Alquiler(float precio,Propiedad* p);
    ~Alquiler();
    float getPrecio();
    void setPrecio(string preci);
    Propiedad* getPropiedad();
    void setPropiedad(Propiedad* p);

};


#endif //LAB6_ALQUILER_H
