//
// Created by leandro on 31/05/16.
//

#include "Propiedad.h"

Propiedad::Propiedad() {

}

void Propiedad::linkConversacion(Conversacion *c) {

}

DataPropiedad Propiedad::crearDataPropiedadExtendida() {
    return NULL;
}

bool Propiedad::existeConversacion() {
    return false;
}

void Propiedad::InsertarNuevoMensaje(string mensaje) {

}

DataDepartamento Propiedad::ObtenerDepartamento() {
    return nullptr;
}

void Propiedad::Actualizar(DataPropiedad p) {

}

Propiedad::~Propiedad() {

}

string Propiedad::getCodigo() {
    return this->codigo;
}

void Propiedad::setCodigo(string code) {
    this->codigo = code;
}

int Propiedad::getAmbientes() {
    return this->ambientes;
}

void Propiedad::setAmbientes(int amb) {
    this->ambientes = amb;
}

int Propiedad::getDormitorios() {
    return this->dormitorios;
}

void Propiedad::setDormitorios(int dor) {
    this->dormitorios = dor;
}

int Propiedad::getBanios() {
    return this->banios;
}

void Propiedad::setBanios(int ban) {
    this->banios = ban;
}

bool Propiedad::tieneGarage() {
    return this->garage;
}

void Propiedad::setGarage(bool garage) {
    this->garage = garage;
}

string Propiedad::getDireccion() {
    return this->direccion;
}

void Propiedad::setDireccion(string dir) {
    this->direccion = dir;
}

float Propiedad::getM2Edificados() {
    return this->metrosCuadradosEdificados;
}

void Propiedad::setM2Edificados(float m2) {
    this->metrosCuadradosEdificados = m2;
}

float Propiedad::getM2Totales() {
    return this->metrosCuadradosTotales;
}

void Propiedad::getM2Totales(float m2) {
    this->metrosCuadradosTotales = m2;
}
