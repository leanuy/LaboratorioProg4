#include "Departamento.h"


Departamento::Departamento(string nombre,string id){
    this->nombre = nombre;
    this->id = id;
}

DataDepartamento Departamento::CrearDataDepartamento(){
    return DataDepartamento(this->nombre,this->id);
}

list<DataZona> Departamento::ListarZonas(){
    list data = new list();
    DataZona current;
    zonas::iterator it = zonas->begin();
    while(it != zonas->end()){
        current(it->get)  // cargar los data zona con los getter de zona
    }
}

Zona* Departamento::SeleccionarZona(string idZona){

}

Propiedad* Departamento::BuscarPropiedad(string idPropiedad){

}

Departamento::~Departamento(){

}