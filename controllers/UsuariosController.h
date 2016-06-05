#ifndef LAB6_USUARIOSCONTROLLER_H
#define LAB6_USUARIOSCONTROLLER_H

#include <string>
#include <map>
#include "../interfaces/IUsuarios.h"
#include "../datatypes/DataInmobiliaria.h"
#include "../model/Inmobiliaria.h"


using namespace std;

class UsuariosController: public IUsuarios {

public:
    UsuariosController();
    void IngresarInmobiliaria(string nombre, string mail, string direccion);
    map<string,DataInmobiliaria> ReportesInmobiliaria();
    void CheckEmail(string mail);
    void DarAltaInteresado(string nombre, string apellido, string email, int edad);
    ~UsuariosController();
};
#endif //LAB6_USUARIOSCONTROLLER_H
