//
// Created by agus on 01/06/16.
//

#ifndef LAB3_CONVERSACIONESCONTROLLER_H

#define LAB3_CONVERSACIONESCONTROLLER_H

#include "../Database.h"
#include "../interfaces/IConversaciones.h"
#include "../model/Departamento.h"
#include <string>
#include <list>
#include <map>

using namespace std;

class ConversacionesController: public IConversaciones{
private:
    Departamento* dActual;
    Zona* zActual;
    Propiedad* pActual;
    Conversacion* cActual;
public:
    ConversacionesController();
    //Interesado
    list<DataDepartamento> ListarDepartamentos();
    void SeleccionarDepartamento(string idDepartamento);
    //Interesado
    list<DataZona> ListarZonas();
    void SeleccionarZona(string idZona);
    //Interesado
    list<DataPropiedad*> ListarPropiedades();
    void SeleccionarPropiedad(string idPropiedad);
    //Inmobiliaria
    list<DataConversacion> ListarConversaciones();
    void SeleccionarConversacion(string idInteresado);
    //Interesado e Inmobiliaria (indiferente, no es necesario hacer casteo)
    list<DataMensaje> ListarMensajes();
    void AgregarMensaje(string mensaje);

    ~ConversacionesController();
};


#endif //LAB3_CONVERSACIONESCONTROLLER_H
