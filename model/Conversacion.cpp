#include <map>
#include "Conversacion.h"
Conversacion::Conversacion(){
    this->lastUpdate = time(NULL);
}
int Conversacion::CantidadMensajes(){
    return int(this->mensajes.size());
}
list<DataMensaje> Conversacion::ListarMensajes() {
    list<DataMensaje> q;
    q.clear();
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
    this->setLastUpdate();
}

DataConversacion Conversacion::CrearDataConversacion(string interesado) {
    DataConversacion data = DataConversacion(interesado, this->lastUpdate, int(this->mensajes.size()));
    return data;
}

void Conversacion::setLastUpdate() {
    this->lastUpdate = this->mensajes.front()->getTOA();
}

time_t Conversacion::getLastUpdate() {
    return this->lastUpdate;
}

Conversacion::~Conversacion(){
        Mensaje* mensaje;
        while(!this->mensajes.empty()){
            mensaje = this->mensajes.front();
            this->mensajes.pop_front();
            delete mensaje;
        }
}