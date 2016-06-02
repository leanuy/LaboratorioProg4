#ifndef LAB6_ZONA_H
#define LAB6_ZONA_H

#include <string>

#include "../datatypes/DataEdificio.h"
#include "DataPropiedad.h"
#include "DataApartamento.h"
#include "Propiedad.h"
#include "Edificio.h"
#include "Departamento.h"
#include <list>
#include <map>


using namespace std;

class Zona {
private:
	string codigo;
	string nombre;
    map<string,Propiedad*> propiedades;
	Departamento* depto;
    map<string,Edificio*> edificios;
public:
    Zona(string codigo,string nombre);
	~Zona();

	void setNombre(string name);
	string getNombre();
	void setCodigo(string code);
	string getCodigo();

    DataZona CrearDataZona();
    list<DataPropiedad>* ListarPropiedadExtendidas();
    Propiedad* SeleccionarPropiedad(string idPropiedad);
    list<DataEdificio>* DevolverEdificios(string nombreEdificio);
    DataEdificio DevolverEdificio(string nombreEdificio);
    Departamento* ObtenerDepartamento();
    void AsignarEdificio(Edificio* e);          // esta seria agregar edificio a la zona
    Propiedad* BuscarPropiedad(string idPropiedad);
};



#endif //LAB6_ZONA_H