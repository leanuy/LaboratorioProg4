//
// Created by Santiago Serantes on 6/1/16.
//

#ifndef LAB3_LOGCONTROLLER_H
#define LAB3_LOGCONTROLLER_H
#include "../interfaces/ILog.h"

class LogController:public ILog {
private:
    Usuario * BuscarUsuario(string email);
public:
    bool IngresarEmail(string email);
    bool SetearPassword(string psw1; string psw2);
    void IngresarPassword(string psw);
    void CerrarSesion();

};


#endif //LAB3_LOGCONTROLLER_H
