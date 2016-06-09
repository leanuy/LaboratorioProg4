
#include "ConversacionesController.h"
#include "../Sesion.h"
#include "../model/Interesado.h"

ConversacionesController::ConversacionesController(){
    this->dActual = NULL;
    this->zActual = NULL;
    this->pActual = NULL;
    this->cActual = NULL;
}

list<DataDepartamento> ConversacionesController::ListarDepartamentos(){
    Database * db = Database::getInstance();
    map<string, Departamento*>::iterator it = db->getDepartamentos().begin();
    list<DataDepartamento> l;
    while (it != db->getDepartamentos().end()){
        l.push_back(it->second->CrearDataDepartamento());
        it++;
    }
    return l;
}
void ConversacionesController::SeleccionarDepartamento(string idDepartamento){
    Database * db = Database::getInstance();
    map<string, Departamento*>::iterator it = db->getDepartamentos().find(idDepartamento);
    if(it == db->getDepartamentos().end()){
        this->dActual = NULL;
        //todo: throw exeption de que no se enconto el departamento que se intento seleccionar
    }
    this->dActual = it->second;
}
list<DataZona> ConversacionesController::ListarZonas(){
    return dActual->ListarZonas();
}
void ConversacionesController::SeleccionarZona(string idZona){
    this->zActual= this->dActual->SeleccionarZona(idZona);
}
list<DataPropiedad> ConversacionesController::ListarPropiedades(){
    return this->zActual->ListarPropiedadesEstaticas();
}
void ConversacionesController::SeleccionarPropiedad(string idPropiedad){
    this->pActual = this->zActual->SeleccionarPropiedad(idPropiedad);
    Sesion* sesion = Sesion::getInstance();
    Interesado* interesado = dynamic_cast<Interesado*>(sesion->getUsuario());
    this->cActual = this->pActual->getInmobiliaria()->SeleccionarConversacion(interesado->getEmail());
    if(this->cActual == NULL){
        this->cActual = new Conversacion;
        this->pActual->getInmobiliaria()->AddConversacion(interesado->getEmail(), this->cActual);
        interesado->AddConversacion(this->pActual->getInmobiliaria()->getEmail(), this->cActual);
    }
}

list<DataConversacion> ConversacionesController::ListarConversaciones(){
    Sesion* sesion = Sesion::getInstance();
    Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(sesion->getUsuario());
    list<DataConversacion> l = inmobiliaria->ListarConversaciones();
    return l;

}
void ConversacionesController::SeleccionarConversacion(string idInteresado){
    Sesion* sesion = Sesion::getInstance();
    Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*>(sesion->getUsuario());
    this->cActual = inmobiliaria->SeleccionarConversacion(idInteresado);
}
list<DataMensaje> ConversacionesController::ListarMensajes(){
    return this->cActual->ListarMensajes();
}
void ConversacionesController::AgregarMensaje(string mensaje){
    Sesion* sesion = Sesion::getInstance();
    this->cActual->AgregarMensaje(sesion->getUsuario()->esTipo("interesado"), mensaje);
    this->cActual->setLastUpdate();
}
ConversacionesController::~ConversacionesController(){
    //No se crea memoria dinamica que deba ser destruida al destruir el controller.
}