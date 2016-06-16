//
// Created by Santiago Serantes on 6/1/16.
//

#ifndef LAB3_ILOG_H
#define LAB3_ILOG_H

#include <string>
using namespace std;


class ILog {
public:
    virtual bool IngresarEmail(string email)=0;
    virtual bool SetearPassword(string psw1, string psw2)=0;
    virtual bool IngresarPassword(string psw)=0;
    virtual void CerrarSesion()=0;
    virtual void Salir()=0;
    virtual ~ILog();
};


#endif //LAB3_ILOG_H
