//
// Created by leandro on 01/06/16.
//

#include "Casa.h"

Casa::Casa(int ambientes, int dormitorios, int banios, bool garage, string direccion, float m2Edificados,
           float m2Totales, float m2Verdes) {
    this->setAmbientes(ambientes);
    this->setDormitorios(dormitorios);
    this->setBanios(banios);
    this->setGarage(garage);
    this->setDireccion(direccion);
    this->setM2Edificados(m2Edificados);
    this->setM2Totales(m2Totales);
    this->setMetrosCuadradosVerdes(m2Verdes);
}

float Casa::getMetrosCuadradosVerdes() {
    return this->metrosCuadradosVerdes;
}

void Casa::setMetrosCuadradosVerdes(float m2verdes) {
    this->metrosCuadradosVerdes = m2verdes;
}

Casa::~Casa() {

}
