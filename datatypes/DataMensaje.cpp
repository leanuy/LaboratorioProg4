//
// Created by agus on 02/06/16.
//

#include "DataMensaje.h"
#include "../Sesion.h"

DataMensaje::DataMensaje(bool isOwner, string mensaje) {
    this->isOwner = isOwner;
    this->texto = mensaje;
}

DataMensaje::~DataMensaje() {

}