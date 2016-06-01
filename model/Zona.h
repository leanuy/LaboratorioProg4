#ifndef LAB6_ZONA_H
#define LAB6_ZONA_H

#include <string>

#include "DataEdificio.h"
#include "DataPropiedadExtendida.h"
#include "DataApartamento.h"


using namespace std;

class Zona {
private:
	string codigo;
	string nombre;
public:
    Zona(string nombre, string codigo);
    DataZona CrearDataZona();
    //Set DataPropiedadExtendida ListarPropiedadExtendidas()
    void SeleccionarPropiedad(string idPropiedad);
    //Set DataEdificio DevolverEdificios(string nombreEdificio)
    DataEdificio DevolverEdificio(string nombreEdificio);
    DataDepartamento ObtenerDepartamento();
    void ObtenerEdificio(Edificio e);
    Propiedad BuscarPropiedad(Propiedad idPropiedad);
    ~Zona();
};



#endif //LAB6_ZONA_H