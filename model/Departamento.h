#ifndef LAB6_DEPARTAMENTO_H
#define LAB6_DEPARTAMENTO_H

#include <string>

#include "DataZona.h"
#include "DataDepartamento.h"


using namespace std;

class Departamento {
private:
	string id;
	string nombre;
public:
    Departamento(String nombre, String id);
    DataDepartamento CrearDataDepartamento();
    //Set DataZona ListarZonas()
    void SeleccionarZona(String idZona);
    Propiedad BuscarPropiedad(Propiedad idPropiedad);
    ~Departamento();
};



#endif //LAB6_DEPARTAMENTO_H