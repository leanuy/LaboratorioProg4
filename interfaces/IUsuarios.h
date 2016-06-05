#ifndef LAB6_IUSUARIOS_H
#define LAB6_IUSUARIOS_H

#include <string>
#include <map>
#include "../datatypes/DataInmobiliaria.h"


using namespace std;

class IUsuarios {
public:
    virtual void IngresarInmobiliaria(string nombre, string mail, string direccion) = 0;
    virtual map<string,DataInmobiliaria> ReportesInmobiliaria() = 0;
    virtual void CheckEmail(string mail) = 0;
    virtual void DarAltaInteresado(string nombre, string apellido, string email, int edad) = 0;
    virtual ~IUsuarios()=0;
};


#endif //LAB6_IUSUARIOS_H