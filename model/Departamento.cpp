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
    zonas::iterator it = zonas->begin();
    while(it != zonas->end()){
        data.insert(it->CrearDataZona());// cargar los data zona con los getter de zona
        it++;
    }
    return data;
}

Zona* Departamento::SeleccionarZona(string idZona){

}

Propiedad* Departamento::BuscarPropiedad(string idPropiedad){

}

Departamento::~Departamento(){

}