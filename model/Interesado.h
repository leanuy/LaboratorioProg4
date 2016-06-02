//
// Created by Santi on 01/06/2016.
//

#ifndef LAB6_INTERESADO_H
#define LAB6_INTERESADO_H

#include <string>
#include "../model/Conversacion.h"
#include "../model/Usuario.h"

using namespace std;

class Interesado: public Usuario{
private:
    string nombre;
    string apellido;
    int edad;
public:
    Interesado(string nombre, string apellido);
    void NuevaProp(string codigo);
    void LinkConversacion(Conversacion c);
};
#endif //LAB6_INTERESADO_H
