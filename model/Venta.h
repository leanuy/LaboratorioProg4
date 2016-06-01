//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_VENTA_H
#define LAB6_VENTA_H

#include "Propiedad.h"

class Venta {
private:
    float precio;
    Propiedad* prop;
public:
    Venta(float precio,Propiedad* p);
    ~Venta();
    float getPrecio();
    void setPrecio(string preci);
    Propiedad* getPropiedad();
    void setPropiedad(Propiedad* p);
};


#endif //LAB6_VENTA_H
