#ifndef LAB6_DEPARTAMENTO_H
#define LAB6_DEPARTAMENTO_H

#include <string>

#include "../datatypes/DataZona.h"
#include "../datatypes/DataDepartamento.h"
#include "../model/Propiedad.h"
#include "../model/Zona.h"
#include <map>
#include <list>

using namespace std;

class Zona;
class Propiedad;

class Departamento {
private:
	string id;
	string nombre;
	map<string,Zona*>* zonas;
public:
    Departamento(string nombre,string id);
    DataDepartamento CrearDataDepartamento();
    list<DataZona>* ListarZonas();
    Zona* SeleccionarZona(string idZona);
    Propiedad* BuscarPropiedad(string idPropiedad);
    ~Departamento();
};



#endif //LAB6_DEPARTAMENTO_H