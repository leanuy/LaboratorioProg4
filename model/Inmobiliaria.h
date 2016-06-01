//
// Created by Santi on 01/06/2016.
//

#ifndef LAB6_INMOBILIARIA_H
#define LAB6_INMOBILIARIA_H

#include <string>

#include "DataMensaje.h"
#include "Conversacion.h"
#include "Propiedad.h"
#include "IObserver.h"

using namespace std;

class Inmobiliaria: public Usuario {
private:
    string nombre;
    string direccion;
public:
    Inmobiliaria(string nombre, string direccion);
    int CantidadMensajes();
    bool ExisteConversacion();
    void LinkConversacion(Conversacion c);
    //Set DataMensaje ListarMensajes();
    void InsertarNuevoMensaje(string mensaje);
    void Alquilar(float precio, Propiedad p);
    void Vender(float precio, Propiedad p);
    void AddObserver(IObserver o);
    void RemoveObserver(IObserver o);
    void NotifyAll(String codigo);
    ~Inmobiliaria();
};

#endif //LAB6_INMOBILIARIA_H