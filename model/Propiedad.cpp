//
// Created by leandro on 31/05/16.
//

#include <iostream>
#include "Propiedad.h"
#include "Interesado.h"

Propiedad::Propiedad() {

}

void Propiedad::LinkConversacion(Conversacion *c) {

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


void Propiedad::AddConversacion(string idInteresado, Conversacion* conversacion){
    this->conversaciones.insert(this->conversaciones.begin(),pair<string, Conversacion*>(idInteresado, conversacion));
}
list<DataConversacion> Propiedad::ListarConversaciones(list<DataConversacion> & l){
    map<string,Conversacion*>::iterator it = this->conversaciones.begin();
    list<DataConversacion>::iterator iter;
    while(it != this->conversaciones.end()){
        iter = l.begin();
        while(iter != l.end() && iter->getLastUpdate()< it->second->getLastUpdate()){
            iter++;
        }
        l.insert(iter, it->second->CrearDataConversacion(it->first));
        it++;
    }
    return l;
}
Conversacion* Propiedad::SeleccionarConversacion(string idConversacion){
    map<string,Conversacion*>::iterator it = this->conversaciones.find(idConversacion);
    if(it == this->conversaciones.end()){
        return NULL;
    }
    return it->second;
}

void Propiedad::DesvincularConversaciones(){
    Database* db = Database::getInstance();
    map<string, Usuario*> usuarios = db->getUsuarios();
    map<string, Conversacion*>::iterator it;
    map<string, Usuario*>::iterator iter;
    string idInteresado;
    while(this->conversaciones.begin() != this->conversaciones.end()){
        it = this->conversaciones.begin();
        idInteresado = it->first.substr(it->first.find("-")+1,it->first.length());
        iter = usuarios.find(idInteresado);
        if(iter != usuarios.end()){
            Interesado* interesado = dynamic_cast<Interesado*>(iter->second);
            interesado->DesvincularConversacion(codigo);
            it->second = NULL;
            this->conversaciones.erase(it);
        }
    }
}