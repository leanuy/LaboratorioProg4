//
// Created by Santiago Serantes on 6/3/16.
//

#ifndef LAB6_SESION_H
#define LAB6_SESION_H
#include "model/Usuario.h"
#include "controllers/LogController.h"

class Sesion {
private:
    static Sesion* instance;
    Usuario* user;
    Sesion(); // Lo necesito??
public:
    static Sesion* getInstance();
    void LogIn(Usuario* usr);
    Usuario* getUsuario();
    void LogOut();
};


#endif //LAB6_SESION_H
