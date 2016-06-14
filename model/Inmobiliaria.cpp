#include "Inmobiliaria.h"
#include "../Database.h"


Inmobiliaria::Inmobiliaria(string nombre, string mail, string direccion){
    this->setNombre(nombre);
    this->setEmail(mail);
    this->setDireccion(direccion);
    this->setFirstTime(true);
}
Inmobiliaria::Inmobiliaria(string nombre, string mail, string direccion, string password){
    this->setNombre(nombre);
    this->setEmail(mail);
    this->setDireccion(direccion);
    this->setContrasenia(password);
    this->setFirstTime(true);
}


void Inmobiliaria::Alquilar(float precio, Propiedad* p){
    Alquiler* a = new Alquiler(precio,p);
    p->setAlquiler(a);
    //add a la coleccion de alquileres
    map<string,Alquiler*>::iterator it = alquileres.find(p->getCodigo());
    if(it != alquileres.end()){
        delete a;  // en teoria no deberia suceder y deberia quedar en end el iterador
        throw std::invalid_argument("Ya existe el alquiler");
    }
    alquileres[p->getCodigo()] = a;
}

void Inmobiliaria::Vender(float precio, Propiedad* p){
    Venta* v = new Venta(precio,p);
    p->setVenta(v);
    //add a la collecion de venta
    map<string,Venta*>::iterator it = ventas.find(p->getCodigo());
    if(it != ventas.end()){
        delete v;  // en teoria no deberia suceder y deberia quedar en end el iterador
        throw std::invalid_argument("Ya existe la venta");
    }
    ventas[p->getCodigo()] = v;
}

Inmobiliaria::~Inmobiliaria(){


}


bool Inmobiliaria::ExisteConversacion() {
    return false;
}

string Inmobiliaria::getNombre() {
    return this->nombre;
}

void Inmobiliaria::setNombre(string name) {
    this->nombre = name;
}

string Inmobiliaria::getDireccion() {
    return this->direccion;
}

void Inmobiliaria::setDireccion(string dir) {
    this->direccion = dir;
}

bool Inmobiliaria::esTipo(string tipo){
    //return (tipo == "inmobiliaria"); //fixme
     return (tipo.compare("inmobiliaria") == 0);
}

void Inmobiliaria::DesvincularPropiedad(string code) {
    map<string,Propiedad*>::iterator it = propiedades.find(code);
    if(it != propiedades.end()){
        propiedades.erase(code);   //investigar si elimina de la coleccion nomas o tmb borra la instancia.
    }
    map<string,Alquiler*>::iterator it2 = alquileres.find(code);
    if(it2 != alquileres.end()){
        delete alquileres[code];
        alquileres.erase(code);
    }
    map<string,Venta*>::iterator it3 = ventas.find(code);
    if(it3 != ventas.end()){
        delete ventas[code];
        ventas.erase(code);
    }
}

void Inmobiliaria::AddPropiedad(Propiedad *p) {
    map<string,Propiedad*>::iterator it = propiedades.find(p->getCodigo());
    if(it == propiedades.end()){
        propiedades[p->getCodigo()] = p;
    }else{
        throw std::invalid_argument("La propiedad ya existe en la imnmobiliaria");
    }

}

list <DataConversacion> Inmobiliaria::ListarConversaciones() {
    list<DataConversacion> l;
    map<string, Propiedad*>::iterator it = this->propiedades.begin();
    while(it != this->propiedades.end()){
        it->second->ListarConversaciones(l);
        it++;
    }
    return l;
}

Conversacion *Inmobiliaria::SeleccionarConversacion(string codigoConversacion) {
    Conversacion* conversacion = NULL;
    Propiedad* propiedad = NULL;
    map<string, Propiedad*>::iterator it = this->propiedades.begin();
    while(it != this->propiedades.end() && conversacion == NULL){
        propiedad = it->second;
        conversacion = propiedad->SeleccionarConversacion(codigoConversacion);
        it++;
    }
    if(conversacion == NULL){
        throw std::invalid_argument("No existe la conversacion que intentas seleccionar");
    }
    return conversacion;
}

Propiedad* Inmobiliaria::SeleccionarPropiedad(string idPropiedad) {
    map<string, Propiedad*>::iterator it = this->propiedades.find(idPropiedad);
    if(it == this->propiedades.end()){
        throw std::invalid_argument(idPropiedad+" - La propiedad que intentas acceder no se encuentra entre las propiedades de la inmobiliaria con sesion iniciada");
    }
    return it->second;
}





