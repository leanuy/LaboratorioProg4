//
// Created by leandro on 01/06/16.
//

#include "Edificio.h"

Edificio::Edificio(string nombre, int pisos, float gastos,Zona* zone) {
    this->nombre = nombre;
    this->pisos = pisos;
    this->gastosComunes = gastos;
    this->zonaDelEdificio = zone;
    // la coleccion de apartamentos no se inicializa. se agrega al edificio cuando se agrega un apto.
}

Edificio::~Edificio() {

}

void Edificio::setNombre(string name) {
    this->nombre = name;
}

string Edificio::getNombre() {
    return this->nombre;
}

void Edificio::setPisos(int pisos) {
    this->pisos = pisos;
}

int Edificio::getPisos() {
    return this->pisos;
}

void Edificio::setGastosComunes(float gastos) {
    this->gastosComunes = gastos;
}

float Edificio::getGastoComunes() {
    return this->gastosComunes;
}

void Edificio::addApartamento(Apartamento *apto) {
    //Agregar apto a la coleccion.
}

void Edificio::setZona(Zona *z) {
    this->zonaDelEdificio = z;
}

Zona* Edificio::getZona() {
    return this->zonaDelEdificio;
}

DataEdificio Edificio::CrearDataEdificio() {
    return DataEdificio(this->nombre,this->pisos,this->gastosComunes);
}
