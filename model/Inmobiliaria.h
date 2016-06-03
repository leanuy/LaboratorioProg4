//
// Created by Santi on 01/06/2016.
//

#ifndef LAB6_INMOBILIARIA_H
#define LAB6_INMOBILIARIA_H

#include <string>

#include "../datatypes/DataMensaje.h"
#include "../model/Conversacion.h"
#include "../model/Propiedad.h"
#include "../model/Usuario.h"
#include "../datatypes/DataConversacion.h"

#include <list>
#include <map>

using namespace std;
class Propiedad;
class Inmobiliaria: public Usuario {
private:
    string nombre;
    string direccion;
    map<string, Conversacion*> conversaciones;
public:
    Inmobiliaria(string nombre, string direccion);
    int CantidadMensajes();
    bool ExisteConversacion();
    string getNombre();
    void setNombre(string name);
    string getDireccion();
    void setDireccion(string dir);
    void LinkConversacion(Conversacion c);
    //Set DataMensaje ListarMensajes()
    list<DataConversacion> ListarConversaciones();
    void InsertarNuevoMensaje(string mensaje);
    void Alquilar(float precio, Propiedad &p);
    void Vender(float precio, Propiedad &p);
    ~Inmobiliaria();
};

#endif //LAB6_INMOBILIARIA_H
