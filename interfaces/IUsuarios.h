#ifndef LAB6_IUSUARIOS_H
#define LAB6_IUSUARIOS_H

#include <string>

#include "DataInmobiliaria.h"


using namespace std;

class IUsuarios {
public:
    virtual void IngresarInmobiliaria(string nombre, string mail, string direccion) = 0;
    virtual string ReportesInmobiliaria() = 0;
    virtual void CheckEmail(string mail) = 0;
    virtual void DarAltaInteresado(string nombre, string apellido, int email) = 0;

};


#endif //LAB6_IUSUARIOS_H