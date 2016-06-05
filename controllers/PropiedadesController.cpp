//
// Created by leandro on 31/05/16.
//

#include "PropiedadesController.h"



void PropiedadesController::SeleccionarDepartamento(string idDepartamento) {
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.find(idDepartamento);
    if(it == deptos.end()){
        throw std::invalid_argument( "El departamento no existe en el sistema" );
    }
    this->dActual = it->second;
}

void PropiedadesController::SeleccionarZona(string idZona) {
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.begin();
    Zona* z = NULL;
    while((it != deptos.end())&&(z == NULL)){
        z = it->second->SeleccionarZona(idZona);
        it++;
    }
    if(it == deptos.end()){
        throw std::invalid_argument("La zona no existe en el sistema");
    }
    this->zActual = z;
}

void PropiedadesController::SeleccionarEdificio(string idEdificio) {
    this->eActual = SeleccionarEdificioPriv(idEdificio);
}

void PropiedadesController::ingresarApartamento(DataApartamento apartamento) {
    Apartamento* apto = new Apartamento(apartamento.getAmbientes(),apartamento.getDormitorios(),
                            apartamento.getBanios(),apartamento.getGarage(),apartamento.getDireccion(),
                            apartamento.getMetrosCuadradosEdificados(),apartamento.getMetrosCuadradosTotales());
    apto->setEdificio(eActual);
    apto->setCodigo(generarCodigo());
    Sesion* s = Sesion::getInstance();
    apto->setInmobiliaria((Inmobiliaria*)s->getUsuario());
    apto->setZona(this->zActual);
    this->zActual->AgregarPropiedad(apto);
    this->pActual = apto;
}

void PropiedadesController::ingresarCasa(DataCasa casa) {
    Casa* ca = new Casa(casa.getAmbientes(),casa.getDormitorios(),
                                       casa.getBanios(),casa.getGarage(),casa.getDireccion(),
                                       casa.getMetrosCuadradosEdificados(),casa.getMetrosCuadradosTotales(),
                                        casa.getM2Verdes());
    ca->setCodigo(generarCodigo());
    Sesion* s = Sesion::getInstance();
    ca->setInmobiliaria((Inmobiliaria*)s->getUsuario());
    ca->setZona(this->zActual);
    this->zActual->AgregarPropiedad(ca);
    this->pActual = ca;
}

void PropiedadesController::ponerEnAlquiler(float precio) {

}

void PropiedadesController::ponerEnVenta(float precio) {

}

string PropiedadesController::getCodigPropiedad() { //fixme: WTF!!!!!!
//    return __cxx11::basic_string<char, char_traits<_CharT>, allocator<_CharT>>();
}

void PropiedadesController::EliminarPropiedad(string codigoPropiedad) {

}

DataPropiedad PropiedadesController::verPropiedad(string codigoPropiedad) {
    return zActual->SeleccionarPropiedad(codigoPropiedad)->CrearDataPropiedad();
}

void PropiedadesController::actualizarPropiedad(DataPropiedad p) {

}

Edificio *PropiedadesController::SeleccionarEdificioPriv(string idEdificio) {
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.begin();
    Edificio* p = NULL;
    while((it != deptos.end())&&(p == NULL)){
        p = it->second->BuscarEdificio(idEdificio);
        it++;
    }
    return p;
}

Propiedad *PropiedadesController::buscarPropiedad(string codigoPropiedad) {
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.begin();
    Propiedad* p = NULL;
    while((it != deptos.end())&&(p == NULL)){
        p = it->second->BuscarPropiedad(codigoPropiedad);
        it++;
    }
    if(it == deptos.end()){
        throw std::invalid_argument( "El edificio no se encuentra en el sistema o aun no fue asigando a una zona" );
    }
    return p;
}

string PropiedadesController::generarCodigo() {
    string codigo = dActual->getId();
    codigo.operator+=(zActual->getCodigo());
    codigo.operator+=(to_string(codigoPropiedadTotal++));
    return codigo;
}

PropiedadesController::PropiedadesController() {

}

PropiedadesController::~PropiedadesController() {

}
