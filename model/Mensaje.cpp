#include "Mensaje.h"
#include "../Sesion.h"

Mensaje::Mensaje(bool esInteresado, string mensaje, string date){
    if (date != ""){
        struct tm tm_aux;
        strptime(date.c_str(), "%Y-%m-%d %H:%M", &tm_aux);
        this->TOA = mktime(&tm_aux);
    }else{
        this->TOA = time(NULL);
    }
    this->esInteresado = esInteresado;
    this->texto = mensaje;
}
time_t Mensaje::getTOA(){
    return this->TOA;
}
DataMensaje Mensaje::CrearDataMensaje(){
    Sesion* sesion = Sesion::getInstance();
    return DataMensaje(this->esInteresado, this->texto, this->TOA, this->codigoPropiedad);
}
Mensaje::~Mensaje(){}