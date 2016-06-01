//
// Created by leandro on 01/06/16.
//

#include "Alquiler.h"

Alquiler::Alquiler(float precio, Propiedad* p) {
    this->precio = precio;
    this->prop = p;
}

Alquiler::~Alquiler() {

}

float Alquiler::getPrecio() {
    return this->precio;
}

void Alquiler::setPrecio(string preci) {
    this->precio = preci;
}

Propiedad *Alquiler::getPropiedad() {
    return this->prop;
}

void Alquiler::setPropiedad(Propiedad *p) {
    this->prop = p;
}
