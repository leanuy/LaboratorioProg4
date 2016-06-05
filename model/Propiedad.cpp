//
// Created by leandro on 31/05/16.
//

#include "Propiedad.h"

Propiedad::Propiedad() {

}

void Propiedad::LinkConversacion(Conversacion *c) {

}

DataPropiedad Propiedad::CrearDataPropiedad() {
    DataPropiedad * data = new DataPropiedad();
    data->setCodigo(this->codigo);
    data->setAmbientes(this->ambientes);
    data->setDormitorios(this->dormitorios);
    data->setBanios(this->banios);
    data->setGarage(this->garage);
    data->setDireccion(this->direccion);
    data->setDireccion(this->direccion);
    data->setMetrosCuadradosEdificados(this->metrosCuadradosEdificados);
    data->setMetrosCuadradosTotales(this->metrosCuadradosTotales);
    data->setCantidadMensajes(0); //agus: calcular cantidad de mensajes
}

bool Propiedad::ExisteConversacion() {
    return false;
}

void Propiedad::InsertarNuevoMensaje(string mensaje) {

}

DataDepartamento Propiedad::ObtenerDepartamento() {
    return this->getZona()->getDepartamento()->CrearDataDepartamento();
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

float Propiedad::getMetrosCuadradosEdificados() {
    return this->metrosCuadradosEdificados;
}

void Propiedad::setMetrosCuadradosEdificados(float m2) {
    this->metrosCuadradosEdificados = m2;
}

float Propiedad::getMetrosCuadradosTotales() {
    return this->metrosCuadradosTotales;
}

void Propiedad::setMetrosCuadradosTotales(float m2) {
    this->metrosCuadradosTotales = m2;
}

Zona* Propiedad::getZona(){
    return this->zona;
}

void Propiedad::setZona(Zona* zona){
    this->zona = zona;
}
Inmobiliaria* Propiedad::getInmobiliaria(){
    return this->inmobiliaria;
}
void Propiedad::setInmobiliaria(Inmobiliaria * inmobiliaria){
    this->inmobiliaria = inmobiliaria;
}

Alquiler *Propiedad::getAlquiler() {
    return this->alquiler;
}

void Propiedad::setAlquiler(Alquiler *a) {
    this->alquiler = a;
}

Venta *Propiedad::getVenta() {
    return this->venta;
}

void Propiedad::setVenta(Venta *v) {
    this->venta = v;
}
