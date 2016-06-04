#include "Inmobiliaria.h"
#include "../Database.h"

Inmobiliaria::Inmobiliaria(string nombre, string direccion){}

void Inmobiliaria::AddConversacion(string idInteresado, Conversacion* conversacion){
    this->conversaciones.insert(pair<string, Conversacion*>(idInteresado, conversacion));
}
list<DataConversacion> Inmobiliaria::ListarConversaciones(){
    list<DataConversacion> l;
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
Conversacion* Inmobiliaria::SeleccionarConversacion(string idConversacion){
    map<string,Conversacion*>::iterator it = this->conversaciones.find(idConversacion);
    if(it == this->conversaciones.end()){
        return NULL;
    }
    return it->second;
}
void Inmobiliaria::Alquilar(float precio, Propiedad &p){}
void Inmobiliaria::Vender(float precio, Propiedad &p){}
Inmobiliaria::~Inmobiliaria(){}


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

bool Inmobiliaria::esTipo(string tipo){
    return tipo == "inmobiliaria";
}