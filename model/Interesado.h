//
// Created by Santi on 01/06/2016.
//

#ifndef LAB6_INTERESADO_H
#define LAB6_INTERESADO_H

#include <string>

#include "Conversacion"

class Interesado: public Usuario{
private:
    String nombre;
    String apellido;
    int edad;
public:
    Interesado(String nombre, String apellido);
    void NuevaProp(String codigo);
    void LinkConversacion(Conversacion c);
};
#endif //LAB6_INTERESADO_H
