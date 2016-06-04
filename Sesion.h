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
    Usuario* getUsuario();
public:
    static Sesion* getInstance();
    void LogIn(Usuario* usr);
    bool isLogged();
    bool esTipo(string tipo);
    void LogOut();

    friend class ConversacionesController;
};


#endif //LAB6_SESION_H
