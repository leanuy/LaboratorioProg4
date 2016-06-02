//
// Created by agus on 01/06/16.
//

#ifndef LAB3_CONVERSACIONESCONTROLLER_H

#define LAB3_CONVERSACIONESCONTROLLER_H

#include "../interfaces/IConversaciones.h"
#include "../model/Departamento.h"
#include <string>
#include <list>

using namespace std;

class ConversacionesController: public IConversaciones{
private:
    Departamento* dActual;
    Zona* zActual;
    Propiedad* pActual;
    Conversacion* cActual;
public:
    ConversacionesController();

   /* void set_dActual(Departamento* d);
    void set_zActual(Zona* z);
    void set_pActual(Propiedad* p);
    void set_cActual(Conversacion* c);
    Departamento* get_dActual();
    Zona* get_zActual();
    Propiedad* get_pActual();
    Conversacion* get_cActual();*/

    list<DataDepartamento> ListarDepartamentos();
    void SeleccionarDepartamento(string idDepartamento);
    list<DataZona> ListarZonas();
    void SeleccionarZona(string idZona);
    list<DataPropiedad> ListarPropiedades();
    void SeleccionarPropiedad(string idPropiedad);
    list<DataConversacion> ListarConversaciones();
    void SeleccionarConversacion(string idConversacion);
    list<DataMensaje> ListarMensajes();
    void AgregarMensaje(string mensaje);
    ~ConversacionesController();
};


#endif //LAB3_CONVERSACIONESCONTROLLER_H
