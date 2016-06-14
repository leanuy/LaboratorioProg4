#include <map>
#include "Conversacion.h"
Conversacion::Conversacion(){
    this->lastUpdate = time(NULL);
}
int Conversacion::CantidadMensajes(){
    return this->mensajes.size();
}
list<DataMensaje> Conversacion::ListarMensajes() {
    list<DataMensaje> q;
    list<Mensaje *>::iterator it = this->mensajes.begin();
    int cnt = 0;
    while (it != this->mensajes.end() && cnt < 5){
        q.push_back((*it)->CrearDataMensaje());
        it++;
        cnt++;
    }
    return q;
}
void Conversacion::AgregarMensaje(bool esInteresado, string mensaje, string date){
    this->mensajes.push_front(new Mensaje(esInteresado, mensaje, date));
    this->lastUpdate = this->mensajes.front()->getTOA();
}

DataConversacion Conversacion::CrearDataConversacion(string interesado) {
    DataConversacion data = DataConversacion(interesado, this->lastUpdate, this->mensajes.size());
    return data;
}

void Conversacion::setLastUpdate() {
    this->lastUpdate = time(NULL);
}

time_t Conversacion::getLastUpdate() {
    return this->lastUpdate;
}

Conversacion::~Conversacion(){
    if(this->mensajes.size() > 0)
        this->mensajes.clear();
}