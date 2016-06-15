#ifndef LAB6_USUARIOSCONTROLLER_H
#define LAB6_USUARIOSCONTROLLER_H

#include <string>
#include <map>
#include "../interfaces/IUsuarios.h"
#include "../datatypes/DataInmobiliaria.h"
#include "../model/Inmobiliaria.h"
#include "../datatypes/DataReporteInmobiliaria.h"


using namespace std;

class UsuariosController: public IUsuarios {

public:
    UsuariosController();
    void IngresarInmobiliaria(string nombre, string mail, string direccion);
    list<DataReporteInmobiliaria> ReportesInmobiliaria();
    bool CheckEmail(string mail);
    void DarAltaInteresado(string nombre, string apellido, string email, int edad);
    void checkName(string name);
    ~UsuariosController();
};
#endif //LAB6_USUARIOSCONTROLLER_H
