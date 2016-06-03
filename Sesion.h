//
// Created by Santiago Serantes on 6/3/16.
//

#ifndef LAB6_SESION_H
#define LAB6_SESION_H
#include "model/Usuario.h"
#include "controllers/LogController.h"

class Sesion {
private:
    static Usuario* user;
    Sesion(); // Lo necesito??
public:
    static Usuario* getUsuario();
    void LogIn(Usuario* usr);
    void LogOut();
};


#endif //LAB6_SESION_H
