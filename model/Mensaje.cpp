#include "Mensaje.h"

Mensaje::Mensaje(string mensaje){
    this->esInteresado = false;
//    this->esInteresado = sesion->tipo("interesado"); todo: usar variable de sesion global
    this->fecha = "";
    this->texto = mensaje;
}
DataMensaje* Mensaje::CrearDataMensaje(){
    DataMensaje *data = new DataMensaje();
    return data;
}
Mensaje::~Mensaje(){}