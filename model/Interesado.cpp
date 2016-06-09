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

void Interesado::AddConversacion(string idInmobiliaria, Conversacion* conversacion){
    this->conversaciones.insert(pair<string, Conversacion*>(idInmobiliaria, conversacion));
}

Interesado::~Interesado(){

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
bool Interesado::esTipo(string tipo){
    return (tipo == "interesado");
}

