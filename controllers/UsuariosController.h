#ifndef LAB6_PROPIEDADESCONTROLLER_H
#define LAB6_PROPIEDADESCONTROLLER_H

#include <string>

using namespace std;

class UsuariosController: public IUsuarios {

public:

    void IngresarInmobiliaria(String nombre, String mail, String direccion) = 0;
    void ReportesInmobiliaria() = 0;
    void CheckEmail(mail: String) = 0;
    void DarAltaInteresado(String nombre, String apellido, int email) = 0;
};
#endif //LAB6_PROPIEDADESCONTROLLER_H
