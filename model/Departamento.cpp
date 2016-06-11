#include "Departamento.h"


Departamento::Departamento(string nombre,string id){
    this->nombre = nombre;
    this->id = id;
}

DataDepartamento Departamento::CrearDataDepartamento(){
    return DataDepartamento(this->nombre,this->id);
}
void Departamento::AddZona(Zona* zona){
    this->zonas[zona->getCodigo()] = zona;
}

list<DataZona> Departamento::ListarZonas(){
    list<DataZona> data;
    map<string,Zona*>::iterator it = zonas.begin();
    if(it == zonas.end()){
        throw std::invalid_argument("El departamento no tiene zonas asignadas");
    }
    while(it != zonas.end()){
        data.push_back(it->second->CrearDataZona());
        it++;
    }
    return data;
}

Zona* Departamento::SeleccionarZona(string idZona){
    map<string,Zona*>::iterator it = zonas.find(idZona);
    if(it == zonas.end()){
        throw std::invalid_argument("La zona que intentas seleccionar no pertenece al departamento actual o no se encuentra en el sistema");
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
