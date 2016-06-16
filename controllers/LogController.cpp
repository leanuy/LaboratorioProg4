//
// Created by Santiago Serantes on 6/1/16.
//
#include <iostream>
#include <string>
#include "../controllers/LogController.h"
#include "../model/Usuario.h"
#include "../Database.h"

// tengo que poner que el usuario es privado?

LogController::LogController(){

}

bool LogController::IngresarEmail(string email) {
    Database* db = Database::getInstance();
    map<string,Usuario*> usuarios = db->getUsuarios();
    map<string,Usuario*>::iterator it = usuarios.find(email);
    if(it == usuarios.end()){
        throw invalid_argument("El email no esta registrado en el sistema");
    }
    usr = it->second;
    return it->second->getFirstTime();
};

bool LogController::SetearPassword(string psw1, string psw2){
    bool exito;
    exito = usr->AsignarPassword(psw1, psw2);
    usr->setFirstTime(false);
    if (exito){
        Sesion* s = Sesion::getInstance();
        s->LogIn(usr);
        usr = NULL;
        return (true);
    }
    else{
        return (false);
    }
};

bool LogController::IngresarPassword(string psw) {
    bool correcta;
    correcta = usr->CheckPassword(psw);
    if (correcta){
        Sesion* s = Sesion::getInstance();
        s->LogIn(usr);
        usr = NULL;
    };
    return correcta;
};

void LogController::CerrarSesion()
{
    Sesion* s = Sesion::getInstance();
    s->LogOut();
};

LogController::~LogController(){

}

void LogController::Salir() {
    Database* db = Database::getInstance();
    delete db;
}

