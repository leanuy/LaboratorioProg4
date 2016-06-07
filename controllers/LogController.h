//
// Created by Santiago Serantes on 6/1/16.
//

#ifndef LAB3_LOGCONTROLLER_H
#define LAB3_LOGCONTROLLER_H
#include "../interfaces/ILog.h"
#include "../model/Usuario.h"
#include "../Sesion.h"

class LogController:public ILog {
private:
    Usuario* usr;
public:
    LogController();
    bool IngresarEmail(string email);
    bool SetearPassword(string psw1, string psw2);
    bool IngresarPassword(string psw);
    void CerrarSesion();
    ~LogController();
};


#endif //LAB3_LOGCONTROLLER_H
