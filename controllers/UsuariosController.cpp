//
// Created by leandro on 31/05/16.
//

#include "UsuariosController.h"
#include "../Database.h"
#include "../model/Interesado.h"

void UsuariosController::IngresarInmobiliaria(string nombre, string mail, string direccion){
    Inmobiliaria* Inmob = new Inmobiliaria(nombre, mail, direccion);
    Database* b = Database::getInstance();
    b->AddUsuario(Inmob);
}

map<string,DataInmobiliaria> UsuariosController::ReportesInmobiliaria(){
	
}
void UsuariosController::CheckEmail(string mail){// para ver si ya existe el mail
	
}
void UsuariosController::DarAltaInteresado(string nombre, string apellido, string email, int edad){
	Interesado* inter = new Interesado(nombre, apellido, email, edad);
    Database* b = Database::getInstance();
    b->AddUsuario(inter);
}