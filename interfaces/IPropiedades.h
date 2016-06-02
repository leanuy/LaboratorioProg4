//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_IPROPIEDADES_H
#define LAB6_IPROPIEDADES_H

#include <string>

#include "../datatypes/DataDepartamento.h"
#include "../datatypes/DataCasa.h"
#include "../datatypes/DataApartamento.h"
#include "../datatypes/DataPropiedad.h"
#include "../datatypes/DataZona.h"
#include "../datatypes/DataEdificio.h"


using namespace std;

class IPropiedades {
public:
    // virtual SET(DataDepartamento) ListarDepartamentos();
    virtual void SeleccionarDepartamento(string idDepartamento) = 0;
    // virtual SET (DataZona) ListarZonas() = 0;
    virtual void SeleccionarZona(string idZona) = 0;
    // virtual SET(DataEdificio) VerEdificiosZona() = 0;
    virtual void SeleccionarEdificio(string idEdificio) = 0;
    virtual void ingresarApartamento(DataApartamento apartamento) = 0;
    virtual void ingresarCasa(DataCasa casa) = 0;
    virtual void ponerEnAlquiler(float precio) = 0;
    virtual void ponerEnVenta(float precio) = 0;
    virtual string getCodigPropiedad() = 0;
    virtual void EliminarPropiedad(string codigoPropiedad) = 0;
    virtual DataPropiedad verPropiedad(string codigoPropiedad) = 0;
    virtual void actualizarPropiedad(DataPropiedad p) = 0;
};


#endif //LAB6_IPROPIEDADES_H
