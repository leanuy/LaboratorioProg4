#ifndef LAB3_CONVERSACION_H
#define LAB3_CONVERSACION_H

#include <queue>
#include <string>
#include "../model/Mensaje.h"
#include "../datatypes/DataMensaje.h"
#include "../datatypes/DataConversacion.h"

class Conversacion {
private:
    queue<Mensaje*>* mensajes;
public:
    Conversacion();
    DataConversacion CrearDataConversacion(string interesado);
    int CantidadMensajes();
    queue<DataMensaje> ListarMensajes();
    void AgregarMensaje(string mensaje);
    ~Conversacion();
};


#endif //LAB3_CONVERSACION_H
