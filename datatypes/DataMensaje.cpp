//
// Created by agus on 02/06/16.
//

#include "DataMensaje.h"
#include "../Sesion.h"

DataMensaje::DataMensaje(bool esInteresado, string mensaje) {
    this->esInteresado = esInteresado;
    this->texto = mensaje;
}

DataMensaje::~DataMensaje() {

}