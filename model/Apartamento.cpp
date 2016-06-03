//
// Created by leandro on 01/06/16.
//

#include "Apartamento.h"

Apartamento::Apartamento(int ambientes, int dormitorios, int banios, bool garage,string direccion,
                         float m2Edificados, float m2Totales) {
    this->setAmbientes(ambientes);
    this->setDormitorios(dormitorios);
    this->setBanios(banios);
    this->setGarage(garage);
    this->setDireccion(direccion);
    this->setMetrosCuadradosEdificados(m2Edificados);
    this->setMetrosCuadradosTotales(m2Totales);
}

void Apartamento::setEdificio(Edificio *e) {
    this->edif = e;
}

Edificio *Apartamento::getEdificio() {
    return this->edif;
}

DataApartamento Apartamento::CrearDataApartamento() {

}

Apartamento::~Apartamento() {

}
