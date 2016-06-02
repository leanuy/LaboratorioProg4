#ifndef LAB3_ICONVERSACIONES_H
#define LAB3_ICONVERSACIONES_H

#include <string>
#include <list>
#include "../datatypes/DataDepartamento.h"
#include "../datatypes/DataZona.h"
#include "../datatypes/DataPropiedad.h"
#include "../datatypes/DataConversacion.h"
#include "../datatypes/DataMensaje.h"

using namespace std;

class IConversaciones {
public:
    IConversaciones();
    virtual list<DataDepartamento> ListarDepartamentos() = 0;
    virtual void SeleccionarDepartamento(string idDepartamento) = 0;
    virtual list<DataZona> ListarZonas() = 0;
    virtual void SeleccionarZona(string idZona) = 0;
    virtual list<DataPropiedad> ListarPropiedades() = 0;
    virtual void SeleccionarPropiedad(string idPropiedad) = 0;
    virtual list<DataConversacion> ListarConversaciones() = 0;
    virtual void SeleccionarConversacion(string idConversacion) = 0;
    virtual list<DataMensaje> ListarMensajes() = 0;
    virtual void AgregarMensaje(string mensaje) = 0                         ;
    virtual ~IConversaciones();
};


#endif //LAB3_ICONVERSACIONES_H
