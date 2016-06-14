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
#include "../Database.h"


using namespace std;
class Alquiler;
class Venta;
class Propiedad;
class Inmobiliaria: public Usuario {
private:
    string nombre;
    string direccion;
    map<string,Alquiler*> alquileres;
    map<string,Venta*> ventas;
    map<string,Propiedad*> propiedades;
    Inmobiliaria(string nombre, string mail, string direccion, string password);
    Propiedad *SeleccionarPropiedad(string idPropiedad);
    Conversacion *SeleccionarConversacion(string basic_string);
public:
    Inmobiliaria(string nombre, string mail, string direccion);
    bool ExisteConversacion();
    string getNombre();
    void setNombre(string name);
    string getDireccion();
    void setDireccion(string dir);
    void Alquilar(float precio, Propiedad* p);
    void Vender(float precio, Propiedad* p);
    bool esTipo(string tipo);
    void DesvincularPropiedad(string code);
    void AddPropiedad(Propiedad* p);
    list <DataConversacion> ListarConversaciones();
    ~Inmobiliaria();

    friend class Database;
    friend class ConversacionesController;



};

#endif //LAB6_INMOBILIARIA_H
