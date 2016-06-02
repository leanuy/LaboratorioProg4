//
// Created by Santiago Serantes on 6/1/16.
//

#include "Factory.h"
#include "controllers/ConversacionesController.h"
#include "controllers/LogController.h"
#include "controllers/PropiedadesController.h"
#include "controllers/UsuariosController.h"

Factory * Factory::instance = NULL;
Factory * Factory::getInstance(){
    if(this->instance == NULL){
        this->instance = new Factory;
    }
    return *this->instance;
}

ILog Factory::getILog(){
    return *new LogController();
}
IPropiedades Factory::getIPropiedades(){
    return *new PropiedadesController;
}
IConversaciones Factory::getIConversaciones(){
    return *new ConversacionesController;
}
IUsuarios Factory::getIUsuarios(){
    return *new UsuariosController;
}