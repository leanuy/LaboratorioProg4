//
// Created by Santi on 01/06/2016.
//


#include "../model/Interesado.h"

Interesado::Interesado(string nombre, string apellido,int edad){

}

void Interesado::AddConversacion(string idInmobiliaria, Conversacion* conversacion){
    this->conversaciones.insert(pair<string, Conversacion*>(idInmobiliaria, conversacion));
}

Interesado::~Interesado(){

}

string Interesado::getNombre(){

}

void Interesado::setNombre(string name){

}

string Interesado::getApellido(){

}

void Interesado::setApellido(string apell){

}

int Interesado::getEdad(){

}

void Interesado::setEdad(int age){

}
bool Interesado::esTipo(string tipo){
    return tipo == "interesado";
}

