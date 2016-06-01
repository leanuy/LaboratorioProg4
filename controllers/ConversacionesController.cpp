
#include "ConversacionesController.h"
ConversacionesController::ConversacionesController(){}

void ConversacionesController::set_dActual(Departamento* d){ this->dActual = d; }
Departamento* ConversacionesController::get_dActual(){ return this->dActual; }
void ConversacionesController::set_zActual(Zona* z){ this->zActual = z; }
Zona* ConversacionesController::get_zActual(){ return this->zActual; }
void ConversacionesController::set_pActual(Propiedad* p){ this->pActual = p; }
Propiedad* ConversacionesController::get_pActual(){ return this->pActual; }
void ConversacionesController::set_cActual(Conversacion* c){ this->cActual = c; }
Conversacion* ConversacionesController::get_cActual(){ return this->cActual; }

void ConversacionesController::ListarDepartamentos(){}//agus:Agregar tipo de devolucion
void ConversacionesController::SeleccionarDepartamento(string idDepartamento){}
void ConversacionesController::ListarZonas(){}//agus:Agregar tipo de devolucion
void ConversacionesController::SeleccionarZona(string idZona){}
void ConversacionesController::ListarPropiedades(){}//agus:Agregar tipo de devolucion
void ConversacionesController::SeleccionarPropiedad(string idPropiedad){}
void ConversacionesController::ListarConversaciones(){}//agus:Agregar tipo de devolucion
void ConversacionesController::SeleccionarConversacion(string idConversacion){}
void ConversacionesController::ListarMensajes(){}//agus:Agregar tipo de devolucion
void ConversacionesController::AgregarMensaje(string mensaje){}
ConversacionesController::~ConversacionesController(){}