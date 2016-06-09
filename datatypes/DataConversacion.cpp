#include "DataConversacion.h"

DataConversacion::DataConversacion(string interesado, time_t lastUpdate, int cantidadMensajes) {
    this->interesado = interesado;
    this->lastUpdate = lastUpdate;
    this->cantidadMensajes = cantidadMensajes;
}

string DataConversacion::getInteresado() {
    return this->interesado;
}

int DataConversacion::getCantidadMensajes() {
    return this->cantidadMensajes;
}

DataConversacion::~DataConversacion() {

}

time_t DataConversacion::getLastUpdate() {
    return this->lastUpdate;
}





