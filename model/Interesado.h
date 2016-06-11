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
    Interesado(string nombre, string apellido, string email, int edad, string password);
public:
    Interesado(string nombre, string apellido, string email, int edad);
    void AddConversacion(string idInmobiliaria, Conversacion* conversacion);
    ~Interesado();
    string getNombre();
    void setNombre(string name);
    string getApellido();
    void setApellido(string apell);
    int getEdad();
    void setEdad(int age);
    int getCantidadMensajes(string idInmobiliaria, string idPropiedad);
    bool esTipo(string tipo);

    friend class Database;
};
#endif //LAB6_INTERESADO_H
