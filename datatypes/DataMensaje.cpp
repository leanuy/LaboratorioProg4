//
// Created by agus on 02/06/16.
//

#include "DataMensaje.h"
#include "../Sesion.h"
#include <sstream>

DataMensaje::DataMensaje(bool esInteresado, string mensaje, time_t TOA, string idPropiedad) {
    this->esInteresado = esInteresado;
    this->texto = mensaje;
    this->TOA = TOA;
    this->idPropiedad = idPropiedad;
}

bool DataMensaje::isInteresado(){
    return this->esInteresado;
}
string DataMensaje::getTexto(){
    return this->texto;
}
string DataMensaje::getIdPropiedad(){
    return this->idPropiedad;
}
string DataMensaje::getTOA(){
    char buff[20];
    time_t now = this->TOA;
    strftime(buff, 20, "%d/%m/%Y %H:%M", localtime(&now));
    return string (buff);
}

DataMensaje::~DataMensaje() {

}