#include "Departamento.h"


Departamento::Departamento(string nombre,string id){
    this->nombre = nombre;
    this->id = id;
}

DataDepartamento Departamento::CrearDataDepartamento(){
    return DataDepartamento(this->nombre,this->id);
}

list<DataZona> Departamento::ListarZonas(){
    list<DataZona> data;
    map<string,Zona*>::iterator it = zonas.begin();
    while(it != zonas.end()){
        data.push_back(it->second->CrearDataZona());
        it++;
    }
    return data;
}

Zona* Departamento::SeleccionarZona(string idZona){
    map<string,Zona*>::iterator it = zonas.find(idZona);
    if(it == zonas.end()){
        return NULL;
        //todo: throw exeption no se encontro la zona que se intento seleccionar
    }
    return it->second;
}

Propiedad* Departamento::BuscarPropiedad(string idPropiedad){
    //iterar en todas las zonas y parar si encuentra el departamento.. pending
    map<string,Zona*>::iterator it = zonas.begin();
    Propiedad* ret = NULL;
    while((it != zonas.end())&&(ret == NULL)){
        ret = (*it->second).SeleccionarPropiedad(idPropiedad);
        it++;
    }
    return ret;
}

Departamento::~Departamento(){

}

string Departamento::getId() {
    return this->id;
}

string Departamento::getNombre() {
    return this->nombre;
}

void Departamento::setId(string id) {
    this->id = id;
}

void Departamento::setNombre(string nombre) {
    this->nombre = nombre;
}

Edificio *Departamento::BuscarEdificio(string idEdificio) {
    map<string,Zona*>::iterator it = zonas.begin();
    Edificio* ret = NULL;
    while((it != zonas.end())&&(ret == NULL)){
        ret = (*it->second).BuscarEdificio(idEdificio);
        it++;
    }
    return ret;
}
