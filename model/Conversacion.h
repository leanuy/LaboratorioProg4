#ifndef LAB3_CONVERSACION_H
#define LAB3_CONVERSACION_H

#include <queue>
#include <string>
#include <ctime>
#include "../model/Mensaje.h"
#include "../datatypes/DataMensaje.h"
#include "../datatypes/DataConversacion.h"

class Conversacion {
private:
    queue<Mensaje*>* mensajes;
    time_t lastUpdate;
public:
    Conversacion();
    DataConversacion CrearDataConversacion(string interesado);
    int CantidadMensajes();
    queue<DataMensaje> ListarMensajes();
    void AgregarMensaje(bool esInteresado, string mensaje);
    void setLastUpdate();
    time_t getLastUpdate();
    ~Conversacion();
};


#endif //LAB3_CONVERSACION_H
