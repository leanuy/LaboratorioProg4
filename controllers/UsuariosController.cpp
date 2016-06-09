//
// Created by leandro on 31/05/16.
//

#include "UsuariosController.h"
#include "../Database.h"
#include "../model/Interesado.h"

UsuariosController::UsuariosController(){}

void UsuariosController::IngresarInmobiliaria(string nombre, string mail, string direccion){
    Inmobiliaria* Inmob = new Inmobiliaria(nombre, mail, direccion);
    Database* b = Database::getInstance();
    try{
        b->AddUsuario(Inmob);
    }catch(invalid_argument e){
        delete Inmob;
        throw std::invalid_argument("El usuario con ese email ya existe en el sistema");
    }
}

map<string,DataInmobiliaria> UsuariosController::ReportesInmobiliaria(){
    map<string,DataInmobiliaria> hola;
    return hola;
}
void UsuariosController::CheckEmail(string mail){// para ver si ya existe el mail
	
}
void UsuariosController::DarAltaInteresado(string nombre, string apellido, string email, int edad){
	Interesado* inter = new Interesado(nombre, apellido, email, edad);
    Database* b = Database::getInstance();
    try{
        b->AddUsuario(inter);
    }catch(invalid_argument e){
        delete inter;
        throw std::invalid_argument("El usuario con ese email ya existe en el sistema");
    }
}

UsuariosController::~UsuariosController(){}