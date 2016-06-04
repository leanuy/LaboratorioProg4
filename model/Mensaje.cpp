#include "Mensaje.h"
#include "../Sesion.h"

Mensaje::Mensaje(bool esInteresado, string mensaje){
    this->esInteresado = esInteresado;
    this->texto = mensaje;
}
DataMensaje Mensaje::CrearDataMensaje(){
    Sesion* sesion = Sesion::getInstance();
    return DataMensaje(this->esInteresado, this->texto);
}
Mensaje::~Mensaje(){}