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

time_t DataConversacion::getLastUpdate(){
    return this->lastUpdate;
}
string DataConversacion::getLastUpdateStr(){
    char buff[20];
    time_t now = this->lastUpdate;
    strftime(buff, 20, "%d/%m/%Y %H:%M", localtime(&now));
    return string (buff);
}





