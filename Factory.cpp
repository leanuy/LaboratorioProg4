//
// Created by Santiago Serantes on 6/1/16.
//

#include "Factory.h"
#include "interfaces/ILog.h"

Factory * Factory::instance = NULL;
Factory * Factory::getInstance(){

};
ILog Factory::getILog(){
    return LogController.getInstance();
};
IPropiedades Factory::getIPropiedades(){
    return PropiedadesController.getInstance();
};
IConversaciones Factory::getIConversaciones(){
    return ConversacionesController.getInstance();
};
IUsuarios Factory::getIUsuarios(){
    return UsuariosController.getInstance();
};