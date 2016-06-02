#include "Zona.h"
#include "Casa.h"

Zona::Zona(string codigo,string nombre) {
    this->nombre = nombre;
    this->codigo = codigo;
}

Zona::~Zona() {

}

void Zona::setNombre(string name) {
    this->nombre = name;
}

string Zona::getNombre() {
    return this->nombre;
}

void Zona::setCodigo(string code) {
    this->codigo = code;
}

string Zona::getCodigo() {
    return this->codigo;
}

DataZona Zona::CrearDataZona() {
    return DataZona(this->codigo,this->nombre);
}

list <DataPropiedad>* Zona::ListarPropiedadExtendidas() {
    list* l = new list();
    map::iterator it = propiedades.begin();
    while(it != propiedades.end()){
        if(dynamic_cast<Casa*>(*it)){
            l->insert(                      // problema
        }else{

        }
        l->insert(it->)
        it++;
    }

    return ;
}

DataPropiedad Zona::SeleccionarPropiedad(string idPropiedad) {
    Propiedad* p = this->BuscarPropiedad(idPropiedad);
    return p->CrearDataPropiedad();
}

list <DataEdificio>* Zona::DevolverEdificios(string nombreEdificio) {
    list<DataEdificio>* l = new list();
    list<DataEdificio>::iterator ite = l->begin();
    map<string,Edificio*>::iterator it = edificios.begin();
    while(it != edificios.end()){
        l->insert(ite,(*it->second).CrearDataEdificio());
        it++;
    }
    return l;
}

DataEdificio Zona::DevolverEdificio(string nombreEdificio) {
    Edificio* edi = edificios[nombreEdificio];
    return DataEdificio(edi->getNombre(),edi->getPisos(),edi->getGastoComunes());
}

Departamento *Zona::ObtenerDepartamento() {
    return nullptr;
}

void Zona::AsignarEdificio(Edificio *e) {
    map<string,Edificio*>::iterator iter = edificios.find(e->getNombre());
    if(iter == edificios.end()){
        edificios[e->getNombre()] = e;
    }
}

Propiedad* Zona::BuscarPropiedad(string idPropiedad) {
    map<string,Propiedad*>::iterator iter = propiedades.find(idPropiedad);
    if(iter == propiedades.end()){
        return NULL;
    }
    Propiedad* p = iter->second;
    return p;
}
