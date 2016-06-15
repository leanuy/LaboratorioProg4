#ifndef LAB6_IUSUARIOS_H
#define LAB6_IUSUARIOS_H

#include <string>
#include <map>
#include "../datatypes/DataInmobiliaria.h"
#include "../datatypes/DataReporteInmobiliaria.h"


using namespace std;

class IUsuarios {
public:
    virtual void IngresarInmobiliaria(string nombre, string mail, string direccion) = 0;
    virtual list<DataReporteInmobiliaria> ReportesInmobiliaria() = 0;
    virtual bool CheckEmail(string mail) = 0;
    virtual void DarAltaInteresado(string nombre, string apellido, string email, int edad) = 0;
    virtual ~IUsuarios();
    virtual void checkName(string name) = 0;
};


#endif //LAB6_IUSUARIOS_H