//
// Created by leandro on 01/06/16.
//

#include "Venta.h"

Venta::Venta(float precio, Propiedad* p) {
    this->precio = precio;
    this->prop = p;
}

Venta::~Venta() {

}

float Venta::getPrecio() {
    return this->precio;
}

void Venta::setPrecio(string preci) {
    this->precio = stof(preci);
}

Propiedad *Venta::getPropiedad() {
    return this->prop;
}

void Venta::setPropiedad(Propiedad *p) {
    this->prop = p;
}