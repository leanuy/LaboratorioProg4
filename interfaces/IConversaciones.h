#ifndef LAB3_ICONVERSACIONES_H
#define LAB3_ICONVERSACIONES_H

#include <string>

using namespace std;

class IConversaciones {
public:
    IConversaciones();
    virtual void ListarDepartamentos() = 0;//agus:Agregar tipo de devolucion
    virtual void SeleccionarDepartamento(string idDepartamento) = 0;
    virtual void ListarZonas() = 0;//agus:Agregar tipo de devolucion
    virtual void SeleccionarZona(string idZona) = 0;
    virtual void ListarPropiedades() = 0;//agus:Agregar tipo de devolucion
    virtual void SeleccionarPropiedad(string idPropiedad) = 0;
    virtual void ListarConversaciones() = 0;//agus:Agregar tipo de devolucion
    virtual void SeleccionarConversacion(string idConversacion) = 0;
    virtual void ListarMensajes() = 0;//agus:Agregar tipo de devolucion
    virtual void AgregarMensaje(string mensaje) = 0                         ;
    virtual ~IConversaciones();
};


#endif //LAB3_ICONVERSACIONES_H
