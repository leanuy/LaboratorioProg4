#ifndef LAB6_DEPARTAMENTO_H
#define LAB6_DEPARTAMENTO_H

#include <string>

#include "../datatypes/DataZona.h"
#include "../datatypes/DataDepartamento.h"
#include "../model/Propiedad.h"
#include "../model/Zona.h"
#include <map>
#include <list>
#include "../model/Edificio.h"
#include "../model/Inmobiliaria.h"
#include "../datatypes/DataReporteInmobiliaria.h"
#include "../datatypes/DataPropPorDepro.h"

using namespace std;

class Zona;
class Propiedad;
class Edificio;
class Inmobiliaria;

class Departamento {
private:
	string id;
	string nombre;
	map<string,Zona*> zonas;
	void AddZona(Zona*);
public:
    Departamento(string nombre,string id);
    DataDepartamento CrearDataDepartamento();
	list<DataZona> ListarZonas();
    Zona* SeleccionarZona(string idZona);
    Propiedad* BuscarPropiedad(string idPropiedad);
	Edificio* BuscarEdificio(string idEdificio);
	DataPropPorDepro PropiedadesEnElDeptoDeLaInmobiliaria(Inmobiliaria* inm);
	void chequearEdificioEnZonas(string nombre);
    ~Departamento();

	string getId();
	string getNombre();
	void setId(string id);
	void setNombre(string nombre);

	friend class Database;
};



#endif //LAB6_DEPARTAMENTO_H