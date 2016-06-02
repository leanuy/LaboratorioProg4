#ifndef LAB6_ZONA_H
#define LAB6_ZONA_H

#include <string>

#include "../datatypes/DataEdificio.h"
#include "../datatypes/DataPropiedad.h"
#include "../datatypes/DataApartamento.h"
#include "../model/Propiedad.h"
#include "../model/Edificio.h"
#include "../model/Departamento.h"
#include <list>
#include <map>


using namespace std;

class Departamento;

class Zona {
private:
	string codigo;
	string nombre;
    map<string,Propiedad*> propiedades;
	Departamento* depto;
    map<string,Edificio*> edificios;
	Propiedad* BuscarPropiedad(string idPropiedad);
public:
    Zona(string codigo,string nombre);
	~Zona();

	void setNombre(string name);
	string getNombre();
	void setCodigo(string code);
	string getCodigo();

    DataZona CrearDataZona();
    list<DataPropiedad>* ListarPropiedadExtendidas();
    DataPropiedad SeleccionarPropiedad(string idPropiedad);
    list<DataEdificio>* DevolverEdificios(string nombreEdificio);
    DataEdificio DevolverEdificio(string nombreEdificio);
    Departamento* ObtenerDepartamento();
    void AsignarEdificio(Edificio* e);          // esta seria agregar edificio a la zona
};



#endif //LAB6_ZONA_H