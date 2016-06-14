#include <cstring>
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
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.begin();
    if(it == deptos.end()){
        throw std::invalid_argument("No hay Departamentos");
    }
    list<DataDepartamento> li;
    list<DataDepartamento>::iterator iter = li.begin();
    while(it != deptos.end()){
        li.insert(iter,it->second->CrearDataDepartamento());
        iter = li.begin();
        it++;
    }
    return li;
}
void ConversacionesController::SeleccionarDepartamento(string idDepartamento){
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.find(idDepartamento);
    if(it == deptos.end()){
        throw std::invalid_argument( "El departamento no existe en el sistema" );
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
string ConversacionesController::SeleccionarPropiedad(string idPropiedad){
    this->pActual = this->zActual->SeleccionarPropiedad(idPropiedad);
    Sesion* sesion = Sesion::getInstance();
    Interesado* interesado = dynamic_cast<Interesado*>(sesion->getUsuario());
    this->cActual = this->pActual->SeleccionarConversacion(this->pActual->getCodigo() + "-"+ interesado->getEmail());
    if(this->cActual == NULL){
        this->cActual = new Conversacion;
        this->pActual->AddConversacion(this->pActual->getCodigo() + "-"+ interesado->getEmail(), this->cActual);
        interesado->AddConversacion(this->pActual->getCodigo(), this->cActual);
    }
    return this->pActual->getInmobiliaria()->getEmail();
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
    string codigoPropiedad;
    if(sesion->esTipo("intersado"))
        codigoPropiedad = this->pActual->getCodigo();
    else
        codigoPropiedad = "";
    this->cActual->AgregarMensaje(sesion->getUsuario()->esTipo("interesado"), mensaje, codigoPropiedad);
    this->cActual->setLastUpdate();
}
ConversacionesController::~ConversacionesController(){
    //No se crea memoria dinamica que deba ser destruida al destruir el controller.
}