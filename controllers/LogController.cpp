//
// Created by Santiago Serantes on 6/1/16.
//
#include <iostream>
#include "LogController.h"

// tengo que poner que el usuario es privado?


Usuario * usr;
bool LogController::IngresarEmail(string email) {
    usr = find_usr(email);
    return usr->FirstTime();
};

bool LogController::SetearPassword(string psw1; string psw2){
    bool distintas;
    distintas = usr->AsignarPassword(psw1, psw2);
    if (distintas){
        LogIn(usr);
        usr = NULL;
        return (true);
    }
    else{
        return (false);
    }
};

void LogController::IngresarPassword(String psw) {
    bool correcta;
    correcta = usr->CheckPassword();
    if (correcta){
        LogIn(usr);
        usr = NULL;
    };
};

void LogController::CerrarSesion()
{
    LogOut();
};