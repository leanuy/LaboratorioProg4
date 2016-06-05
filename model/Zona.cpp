#include "Zona.h"
#include "Casa.h"
#include "Apartamento.h"

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

void Zona::setDepartamento(Departamento *departamento) {
    this->departamento = departamento;
}

Departamento* Zona::getDepartamento() {
    return this->departamento;
}

DataZona Zona::CrearDataZona() {
    return DataZona(this->codigo,this->nombre);
}

list<DataPropiedad> Zona::ListarPropiedadExtendidas() {
    list<DataPropiedad> l;
    map<string,Propiedad*>::iterator it = this->propiedades.begin();
    while(it != propiedades.end()){
        if(dynamic_cast<Casa*>(it->second)){
            l.push_back(dynamic_cast<Casa*>(it->second)->CrearDataCasa());
        }else{
            l.push_back(dynamic_cast<Apartamento*>(it->second)->CrearDataApartamento());
        }
        it++;
    }

    return l;
}

list <DataEdificio>* Zona::DevolverEdificios(string nombreEdificio) {
    list<DataEdificio>* l = new list<DataEdificio>;
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
    return this->departamento;
}

void Zona::AsignarEdificio(Edificio *e) {
    map<string,Edificio*>::iterator iter = edificios.find(e->getNombre());
    if(iter == edificios.end()){
        edificios[e->getNombre()] = e;
    }
}

Propiedad* Zona::SeleccionarPropiedad(string idPropiedad) {
    map<string,Propiedad*>::iterator it = propiedades.find(idPropiedad);
    if(it == propiedades.end()){
        return NULL;
        //todo: thow exeption no se encontro la propiedad que se intento seleccionar
        //nota leandro: si tiras excepcion aca no sigue buscando en otra zona. se debe tirar en el bucle principal
    }
    return it->second;
}

Edificio *Zona::BuscarEdificio(string idEdificio) {
    map<string,Edificio*>::iterator it = edificios.find(idEdificio);
    if(it == edificios.end()){
        return NULL;
    }
    return it->second;
}

void Zona::AgregarPropiedad(Propiedad *p) {
    map<string,Propiedad*>::iterator iter = propiedades.find(p->getCodigo());
    if(iter == propiedades.end()){
        propiedades[p->getCodigo()] = p;
    }
}

void Zona::eliminarPropiedad(string codigo) {
    map<string,Propiedad*>::iterator iter = propiedades.find(codigo);
    if(iter == propiedades.end()){
        //una vez que tenga la propiedad debo ir a su inmobiliaria y sacarle el alquiler o venta.. luego
        //sacarla de la inmobiliaria por ultimo eliminarla de la zona y dejar el puntero a null;
        //ver tambien las conversaciones que onda. y si es un edificio quitarle el apartamento.
        delete propiedades[codigo];
        propiedades[codigo] = NULL;
    }
}
