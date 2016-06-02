#ifndef LAB3_CONVERSACION_H
#define LAB3_CONVERSACION_H

#include <stack>

class Conversacion {
private:
    stack<Mensaje> mensajes;
public:
    Conversacion();
    int CantidadMensajes();
    stack<DataMensaje> ListarMensajes();
    void AgregarMensaje(string mensaje);
    ~Conversacion();
};


#endif //LAB3_CONVERSACION_H
