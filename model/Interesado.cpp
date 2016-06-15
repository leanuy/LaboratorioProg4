//
// Created by Santi on 01/06/2016.
//


#include "../model/Interesado.h"

Interesado::Interesado(string nombre, string apellido, string email, int edad){
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->setEmail(email);
    this->setFirstTime(true);
}
Interesado::Interesado(string nombre, string apellido, string email, int edad, string password){
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->setEmail(email);
    this->setContrasenia(password);
    this->setFirstTime(true);
}

void Interesado::AddConversacion(string idPropiedad, Conversacion* conversacion){
    this->conversaciones.insert(this->conversaciones.begin(), pair<string, Conversacion*>(idPropiedad, conversacion));
}

Interesado::~Interesado(){
    if(this->conversaciones.size() >0)
        this->conversaciones.clear();
}

string Interesado::getNombre(){
    return this->nombre;
}

void Interesado::setNombre(string name){
    this->nombre = name;
}

string Interesado::getApellido(){
    return this->apellido;
}

void Interesado::setApellido(string apell){
    this->apellido = apell;
}

int Interesado::getEdad(){
    return this->edad;
}

void Interesado::setEdad(int age){
    this->edad = age;
}
int Interesado::getCantidadMensajes(string idPropiedad){
    int cnt = 0;
    map<string, Conversacion*>::iterator it = this->conversaciones.find(idPropiedad);
    if(it != this->conversaciones.end()){
        Conversacion* conversacion = it->second;
        return conversacion->CantidadMensajes();
    }
    return cnt;
}
bool Interesado::esTipo(string tipo){
    return (tipo == "interesado");
}

void Interesado::DesvincularConversacion(string idPropiedad) {
    map<string, Conversacion*>::iterator it = this->conversaciones.find(idPropiedad);
    if(it == this->conversaciones.end()){
        throw std::invalid_argument("La conversacion que intentas desvincular no existe");
    }else{
        delete it->second;
        this->conversaciones.erase(it);
    }
}



