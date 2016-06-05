//
// Created by leandro on 31/05/16.
//

#ifndef LAB6_PROPIEDADESCONTROLLER_H
#define LAB6_PROPIEDADESCONTROLLER_H

#include <string>
#include "../interfaces/IPropiedades.h"
#include "../model/Propiedad.h"
#include "../model/Zona.h"
#include "../model/Edificio.h"
#include "../model/Departamento.h"
#include "../model/Apartamento.h"
#include "../model/Casa.h"
#include "../Database.h"
#include "../Sesion.h"
#include "../model/Alquiler.h"
#include "../model/Venta.h"
#include <typeinfo>



using namespace std;

class PropiedadesController: public IPropiedades {
private:
    Departamento* dActual;
    Zona* zActual;
    Edificio* eActual;
    Propiedad* pActual;
    static int codigoPropiedadTotal = 0;


    Edificio* SeleccionarEdificioPriv(string idEdificio);
    Propiedad* buscarPropiedadPriv(string codigoPropiedad);
    string generarCodigo();
public:
    PropiedadesController();
    ~PropiedadesController();
    list<DataDepartamento> ListarDepartamentos();
    void SeleccionarDepartamento(string idDepartamento);
    list<DataZona> ListarZonas();
    void SeleccionarZona(string idZona);
    list<DataEdificio> VerEdificiosZona();
    void SeleccionarEdificio(string idEdificio);
    void ingresarApartamento(DataApartamento apartamento);
    void ingresarCasa(DataCasa casa);
    void ponerEnAlquiler(float precio);
    void ponerEnVenta(float precio);
    string getCodigPropiedad();
    DataPropiedad BuscarPropiedad(string codigo);
    void EliminarPropiedad(string codigoPropiedad);
    DataPropiedad verPropiedad(string codigoPropiedad);
    void actualizarPropiedad(DataPropiedad p);
};
#endif //LAB6_PROPIEDADESCONTROLLER_H
