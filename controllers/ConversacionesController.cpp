
#include "ConversacionesController.h"
ConversacionesController::ConversacionesController(){}

/*
void ConversacionesController::set_dActual(Departamento* d){ this->dActual = d; }
Departamento* ConversacionesController::get_dActual(){ return this->dActual; }
void ConversacionesController::set_zActual(Zona* z){ this->zActual = z; }
Zona* ConversacionesController::get_zActual(){ return this->zActual; }
void ConversacionesController::set_pActual(Propiedad* p){ this->pActual = p; }
Propiedad* ConversacionesController::get_pActual(){ return this->pActual; }
void ConversacionesController::set_cActual(Conversacion* c){ this->cActual = c; }
Conversacion* ConversacionesController::get_cActual(){ return this->cActual; }
*/

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
    this->dActual = db->getDepartamentos().find(idDepartamento)->second;
    if(this->dActual == db->getDepartamentos().end()->second){
        //todo: throw exeption
    }
}
list<DataZona> ConversacionesController::ListarZonas(){
    return dActual->ListarZonas();
}
void ConversacionesController::SeleccionarZona(string idZona){
    this->zActual= this->dActual->SeleccionarZona(idZona);
}
list<DataPropiedad> ConversacionesController::ListarPropiedades(){
    return this->zActual->ListarPropiedadExtendidas();
}
void ConversacionesController::SeleccionarPropiedad(string idPropiedad){
    this->pActual = this->zActual->SeleccionarPropiedad(idPropiedad);
}
list<DataConversacion> ConversacionesController::ListarConversaciones(){
   // return this->pActual->getInmobiliaria()-> Fixme
}
void ConversacionesController::SeleccionarConversacion(string idConversacion){}
list<DataMensaje> ConversacionesController::ListarMensajes(){}//agus:Agregar tipo de devolucion
void ConversacionesController::AgregarMensaje(string mensaje){}
ConversacionesController::~ConversacionesController(){}