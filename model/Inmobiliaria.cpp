//
// Created by Santi on 01/06/2016.
//

#include "Inmobiliaria.h"
#include "../Database.h"

Inmobiliaria::Inmobiliaria(string nombre, string direccion){}
void Inmobiliaria::LinkConversacion(Conversacion c){}
//Set DataMensaje Inmobiliaria::ListarMensajes(){}
list<DataConversacion> Inmobiliaria::ListarConversaciones(){
    list<DataConversacion> l;
    map<string,Conversacion*>::iterator it = this->conversaciones.begin();
    while(it != this->conversaciones.end()){
        l.push_back(it->second->CrearDataConversacion(it->first));
        it++;
    }
    return l;
}
void Inmobiliaria::InsertarNuevoMensaje(string mensaje){}
void Inmobiliaria::Alquilar(float precio, Propiedad &p){}
void Inmobiliaria::Vender(float precio, Propiedad &p){}
Inmobiliaria::~Inmobiliaria(){}

int Inmobiliaria::CantidadMensajes() {
    return 0;
}

bool Inmobiliaria::ExisteConversacion() {
    return false;
}

string Inmobiliaria::getNombre() {
    return this->nombre;
}

void Inmobiliaria::setNombre(string name) {
    this->nombre = name;
}

string Inmobiliaria::getDireccion() {
    return this->direccion;
}

void Inmobiliaria::setDireccion(string dir) {
    this->direccion = dir;
}
