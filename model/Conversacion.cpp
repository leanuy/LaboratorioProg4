
#include "Conversacion.h"
Conversacion::Conversacion(){
    this->mensajes = new queue<Mensaje*>;
}
int Conversacion::CantidadMensajes(){
    this->mensajes->size();
}
queue<DataMensaje> Conversacion::ListarMensajes(){}
void Conversacion::AgregarMensaje(string mensaje){
    this->mensajes->push(new Mensaje(mensaje));
}
Conversacion::~Conversacion(){}

DataConversacion Conversacion::CrearDataConversacion(string interesado) {
    DataConversacion data = DataConversacion(interesado);

}

