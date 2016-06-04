//
// Created by Santi on 01/06/2016.
//

#ifndef LAB6_INTERESADO_H
#define LAB6_INTERESADO_H

#include <string>
#include <map>
#include "../model/Conversacion.h"
#include "../model/Usuario.h"

using namespace std;


class Interesado: public Usuario{
private:
    string nombre;
    string apellido;
    int edad;
    map<string, Conversacion*> conversaciones;
public:
    Interesado(string nombre, string apellido,int edad);
    void AddConversacion(string idInmobiliaria, Conversacion* conversacion);
    ~Interesado();
    string getNombre();
    void setNombre(string name);
    string getApellido();
    void setApellido(string apell);
    int getEdad();
    void setEdad(int age);

    bool esTipo(string tipo);
};
#endif //LAB6_INTERESADO_H
