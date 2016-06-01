#ifndef LAB6_DEPARTAMENTO_H
#define LAB6_DEPARTAMENTO_H

#include <string>

#include "DataZona.h"
#include "DataDepartamento.h"
#include <map>
#include <listt>

using namespace std;

class Departamento {
private:
	string id;
	string nombre;
	map<string,Zona*>* zonas;
public:
    Departamento(string nombre,string id);
    DataDepartamento CrearDataDepartamento();
    list<DataZona> ListarZonas();
    Zona* SeleccionarZona(string idZona);
    Propiedad* BuscarPropiedad(string idPropiedad);
    ~Departamento();
};



#endif //LAB6_DEPARTAMENTO_H