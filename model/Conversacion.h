#ifndef LAB3_CONVERSACION_H
#define LAB3_CONVERSACION_H

#include <list>
#include <string>
#include <ctime>
#include "../model/Mensaje.h"
#include "../datatypes/DataMensaje.h"
#include "../datatypes/DataConversacion.h"

class Conversacion {
private:
    list<Mensaje*> mensajes;
    time_t lastUpdate;
public:
    Conversacion();
    DataConversacion CrearDataConversacion(string interesado);
    int CantidadMensajes();
    list<DataMensaje> ListarMensajes();
    void AgregarMensaje(bool esInteresado, string mensaje, string codigoPropiedad = "", string date = "");
    void setLastUpdate();
    time_t getLastUpdate();
    ~Conversacion();
};


#endif //LAB3_CONVERSACION_H
