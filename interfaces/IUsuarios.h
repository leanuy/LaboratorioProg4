#ifndef LAB6_IUSUARIOS_H
#define LAB6_IUSUARIOS_H

#include <string>

#include "DataInmobiliaria.h"


using namespace std;

class IUsuarios {
public:
    virtual void IngresarInmobiliaria(String nombre, String mail, String direccion) = 0;
    virtual void ReportesInmobiliaria() = 0;
    virtual void CheckEmail(mail: String) = 0;
    virtual void DarAltaInteresado(String nombre, String apellido, int email) = 0;

};


#endif //LAB6_IPROPIEDADES_H