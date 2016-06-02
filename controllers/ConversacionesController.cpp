
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

list<DataDepartamento> ConversacionesController::ListarDepartamentos(){}//agus:Agregar tipo de devolucion
void ConversacionesController::SeleccionarDepartamento(string idDepartamento){}
list<DataZona> ConversacionesController::ListarZonas(){}//agus:Agregar tipo de devolucion
void ConversacionesController::SeleccionarZona(string idZona){}
list<DataPropiedad> ConversacionesController::ListarPropiedades(){}//agus:Agregar tipo de devolucion
void ConversacionesController::SeleccionarPropiedad(string idPropiedad){}
list<DataConversacion> ConversacionesController::ListarConversaciones(){}//agus:Agregar tipo de devolucion
void ConversacionesController::SeleccionarConversacion(string idConversacion){}
list<DataMensaje> ConversacionesController::ListarMensajes(){}//agus:Agregar tipo de devolucion
void ConversacionesController::AgregarMensaje(string mensaje){}
ConversacionesController::~ConversacionesController(){}