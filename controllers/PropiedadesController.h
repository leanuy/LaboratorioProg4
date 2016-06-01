//
// Created by leandro on 31/05/16.
//

#ifndef LAB6_PROPIEDADESCONTROLLER_H
#define LAB6_PROPIEDADESCONTROLLER_H

#include <string>
#include "../model/Propiedad.h"
#include "Zona.h"
#include "../model/Edificio.h"
#include "Departamento.h"



using namespace std;

class PropiedadesController: public IPropiedades {
private:
    Departamento* dActual;
    Zona* zActual;
    Edificio* eActual;
    Propiedad* pActual;

    Departamento* SeleccionarDepartamentoPriv(string idDepartamento);
    Zona* SeleccionarZonaPriv(string idZona);
    Edificio* SeleccionarEdificioPriv(string idEdificio);
    Propiedad* buscarPropiedad(string codigoPropiedad);
public:
    // SET(DataDepartamento) ListarDepartamentos();
    void SeleccionarDepartamento(string idDepartamento);
    // SET (DataZona) ListarZonas();
    void SeleccionarZona(string idZona);
    //SET(DataEdificio) VerEdificiosZona();
    void SeleccionarEdificio(string idEdificio);
    void ingresarApartamento(DataApartamento apartamento);
    void ingresarCasa(DataCasa casa);
    void ponerEnAlquiler(float precio);
    void ponerEnVenta(float precio);
    string getCodigPropiedad();
    void EliminarPropiedad(string codigoPropiedad);
    DataPropiedad verPropiedad(string codigoPropiedad);
    void actualizarPropiedad(DataPropiedad p);
};
#endif //LAB6_PROPIEDADESCONTROLLER_H
