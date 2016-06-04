//
// Created by leandro on 31/05/16.
//

#include "PropiedadesController.h"

void PropiedadesController::SeleccionarDepartamento(string idDepartamento) {

}

void PropiedadesController::SeleccionarZona(string idZona) {

}

void PropiedadesController::SeleccionarEdificio(string idEdificio) {

}

void PropiedadesController::ingresarApartamento(DataApartamento apartamento) {

}

void PropiedadesController::ingresarCasa(DataCasa casa) {

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

Departamento *PropiedadesController::SeleccionarDepartamentoPriv(string idDepartamento) {
    return nullptr;
}

Zona *PropiedadesController::SeleccionarZonaPriv(string idZona) {
    return nullptr;
}

Edificio *PropiedadesController::SeleccionarEdificioPriv(string idEdificio) {
    return nullptr;
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
    return p;
}
