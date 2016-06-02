#ifndef LAB6_USUARIOSCONTROLLER_H
#define LAB6_USUARIOSCONTROLLER_H

#include <string>
#include <map>
#include "../interfaces/IUsuarios.h"
#include "../datatypes/DataInmobiliaria.h"

using namespace std;

class UsuariosController: public IUsuarios {

public:

    void IngresarInmobiliaria(string nombre, string mail, string direccion);
    map<string,DataInmobiliaria> ReportesInmobiliaria();
    void CheckEmail(string mail);
    void DarAltaInteresado(string nombre, string apellido, int email);
};
#endif //LAB6_USUARIOSCONTROLLER_H
