//
// Created by agus on 01/06/16.
//

#ifndef LAB3_CONVERSACIONESCONTROLLER_H

#define LAB3_CONVERSACIONESCONTROLLER_H

#include "IConversaciones.h"
#include <string>

using namespace std;

class ConversacionesController: public IConversaciones{
private:
    Departamento* dActual;
    Zona* zActual;
    Propiedad* pActual;
    Conversacion* cActual;
public:
    ConversacionesController();

    void set_dActual(Departamento* d);
    void set_zActual(Zona* z);
    void set_pActual(Propiedad* p);
    void set_cActual(Conversacion* c);
    Departamento* get_dActual();
    Zona* get_zActual();
    Propiedad* get_pActual();
    Conversacion* get_cActual();

    void ListarDepartamentos();//agus:Agregar tipo de devolucion
    void SeleccionarDepartamento(string idDepartamento);
    void ListarZonas();//agus:Agregar tipo de devolucion
    void SeleccionarZona(string idZona);
    void ListarPropiedades();//agus:Agregar tipo de devolucion
    void SeleccionarPropiedad(string idPropiedad);
    void ListarConversaciones();//agus:Agregar tipo de devolucion
    void SeleccionarConversacion(string idConversacion);
    void ListarMensajes();//agus:Agregar tipo de devolucion
    void AgregarMensaje(string mensaje);
    ~ConversacionesController();
};


#endif //LAB3_CONVERSACIONESCONTROLLER_H
