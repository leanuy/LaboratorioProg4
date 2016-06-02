#include "Departamento.h"


Departamento::Departamento(string nombre,string id){
    this->nombre = nombre;
    this->id = id;
}

DataDepartamento Departamento::CrearDataDepartamento(){
    return DataDepartamento(this->nombre,this->id);
}

list<DataZona>* Departamento::ListarZonas(){
    list<DataZona>* data = new list<DataZona>;
    list<DataZona>::iterator iter = data->begin();
    map<string,Zona*>::iterator it = zonas->begin();
    while(it != zonas->end()){
        data->insert(iter,it->second->CrearDataZona());
        iter = data->begin();
        it++;
    }
    return data;
}

Zona* Departamento::SeleccionarZona(string idZona){
    map<string,Zona*>::iterator it = zonas->find(idZona);
    if(it == zonas->end()){
        return NULL;
    }
    return it->second;
}

Propiedad* Departamento::BuscarPropiedad(string idPropiedad){
    //iterar en todas las zonas y parar si encuentra el departamento.. pending
    map<string,Zona*>::iterator it = zonas->begin();
    Propiedad* ret = NULL;
    while((it != zonas->end())&&(ret == NULL)){
        ret = (*it->second).BuscarPropiedad(idPropiedad);
        it++;
    }
    return ret;
}

Departamento::~Departamento(){

}