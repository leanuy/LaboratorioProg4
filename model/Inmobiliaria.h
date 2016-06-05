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
#include "../model/Venta.h"
#include "../model/Alquiler.h"

using namespace std;
class Propiedad;
class Inmobiliaria: public Usuario {
private:
    string nombre;
    string direccion;
    map<string, Conversacion*> conversaciones;
    map<string,Alquiler*> alquileres;
    map<string,Venta*> ventas;
    map<string,Propiedad*> propiedades;

public:
    Inmobiliaria(string nombre, string mail, string direccion);
    bool ExisteConversacion();
    string getNombre();
    void setNombre(string name);
    string getDireccion();
    void setDireccion(string dir);
    void AddConversacion(string idInteresado, Conversacion* conversacion);
    list<DataConversacion> ListarConversaciones();
    Conversacion* SeleccionarConversacion(string idConversacion);
    void Alquilar(float precio, Propiedad* p);
    void Vender(float precio, Propiedad* p);
    bool esTipo(string tipo);
    void DesvincularPropiedad(string code);
    void AddPropiedad(Propiedad* p);
    ~Inmobiliaria();
};

#endif //LAB6_INMOBILIARIA_H
