#ifndef LAB6_ZONA_H
#define LAB6_ZONA_H

#include <string>

#include "../datatypes/DataEdificio.h"
#include "../datatypes/DataPropiedad.h"
#include "../datatypes/DataApartamento.h"
#include "../datatypes/DataCasa.h"
#include "../model/Propiedad.h"
#include "../model/Edificio.h"
#include "../model/Departamento.h"
#include <list>
#include <map>


using namespace std;

class Departamento;
class Propiedad;

class Zona {
private:
	string codigo;
	string nombre;
    map<string,Propiedad*> propiedades;
	Departamento* departamento;
    map<string,Edificio*> edificios;
	//agregar coleccion de zonas limite.


public:
    Zona(string codigo,string nombre);
	~Zona();

	void setNombre(string name);
	string getNombre();
	void setCodigo(string code);
	string getCodigo();
	void setDepartamento(Departamento* departamento);
	Departamento* getDepartamento();
	Edificio* BuscarEdificio(string idEdificio);

    DataZona CrearDataZona();
    list<DataPropiedad*> ListarPropiedadExtendidas();
    Propiedad* SeleccionarPropiedad(string idPropiedad);
    list<DataEdificio> DevolverEdificios();
    DataEdificio DevolverEdificio(string nombreEdificio);
    Departamento* ObtenerDepartamento();
    void AsignarEdificio(Edificio* e);          // esta seria agregar edificio a la zona
	void AgregarPropiedad(Propiedad* p);
	void eliminarPropiedad(string codigo);
};



#endif //LAB6_ZONA_H