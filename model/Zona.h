#ifndef LAB6_ZONA_H
#define LAB6_ZONA_H

#include <string>

#include "DataEdificio.h"
#include "DataPropiedadExtendida.h"
#include "DataApartamento.h"
#include <list>


using namespace std;

class Zona {
private:
	string codigo;
	string nombre;
    map<string,Propiedad*>* propiedades;
    Departamento* depto;
    map<string,Edificio*>* edificios;
public:
    Zona(string nombre,string codigo);
    DataZona CrearDataZona();
    list<DataPropiedad> ListarPropiedadExtendidas();
    Propiedad* SeleccionarPropiedad(string idPropiedad);
    list<DataEdificio> DevolverEdificios(string nombreEdificio);
    DataEdificio DevolverEdificio(string nombreEdificio);
    Departamento* ObtenerDepartamento();
    void AsignarEdificio(Edificio* e);
    Propiedad* BuscarPropiedad(string idPropiedad);
    ~Zona();
};



#endif //LAB6_ZONA_H