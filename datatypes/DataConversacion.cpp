#include "DataConversacion.h"

DataConversacion::DataConversacion(string interesado, time_t lastUpdate) {
    this->interesado = interesado;
    this->lastUpdate = lastUpdate;
}

string DataConversacion::getInteresado() {
    return this->interesado;
}

DataConversacion::~DataConversacion() {

}

time_t DataConversacion::getLastUpdate() {
    return this->lastUpdate;
}





