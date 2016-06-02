//
// Created by agus on 01/06/16.
//

#ifndef LAB3_MENSAJE_H
#define LAB3_MENSAJE_H

#include <string>
#include "../datatypes/DataMensaje.h"

using namespace std;

class Mensaje {
private:
    bool esInteresado;
    string fecha;
    string texto;
public:
    Mensaje(string mensaje);
    DataMensaje* CrearDataMensaje();
    ~Mensaje();
};


#endif //LAB3_MENSAJE_H
