#ifndef LAB6_ZONA_H
#define LAB6_ZONA_H

#include <string>

#include "DataEdificio.h"
#include "DataPropiedadExtendida.h"
#include "DataApartamento.h"


using namespace std;

class Zona {
private:
	codigo: String
	nombre: String
public:
    Zona(String nombre, String codigo);
    DataZona CrearDataZona();
    //Set DataPropiedadExtendida ListarPropiedadExtendidas()
    void SeleccionarPropiedad(String idPropiedad);
    //Set DataEdificio DevolverEdificios(String nombreEdificio)
    DataEdificio DevolverEdificio(String nombreEdificio);
    DataDepartamento ObtenerDepartamento();
    void ObtenerEdificio(Edificio e);
    Propiedad BuscarPropiedad(Propiedad idPropiedad);
    ~Zona();
};



#endif //LAB6_ZONA_H