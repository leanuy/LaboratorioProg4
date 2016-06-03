
#include "Conversacion.h"
Conversacion::Conversacion(){
    this->mensajes = new queue<Mensaje*>;
    this->lastUpdate = time(NULL);
}
int Conversacion::CantidadMensajes(){
    this->mensajes->size();
}
queue<DataMensaje> Conversacion::ListarMensajes(){}
void Conversacion::AgregarMensaje(bool esInteresado, string mensaje){
    this->mensajes->push(new Mensaje(esInteresado, mensaje));
}
Conversacion::~Conversacion(){}

DataConversacion Conversacion::CrearDataConversacion(string interesado) {
    DataConversacion data = DataConversacion(interesado, this->lastUpdate);

}

void Conversacion::setLastUpdate() {
    this->lastUpdate = time(NULL);
}

time_t Conversacion::getLastUpdate() {
    return this->lastUpdate;
}

