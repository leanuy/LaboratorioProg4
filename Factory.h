//
// Created by Santiago Serantes on 6/1/16.
//

#ifndef LAB3_FACTORY_H
#define LAB3_FACTORY_H


#include "interfaces/IConversaciones.h"
#include "interfaces/IPropiedades.h"
#include "interfaces/ILog.h"
#include "interfaces/IUsuarios.h"
#include "interfaces/ISesion.h"

class Factory {
private:
    static Factory * instance;
    Factory();
public:
    static Factory * getInstance();
    ILog* getILog();
    IPropiedades* getIPropiedades();
    IConversaciones* getIConversaciones();
    IUsuarios* getIUsuarios();
    ISesion* getISesion();
};


#endif //LAB3_FACTORY_H
