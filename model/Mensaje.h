//
// Created by agus on 01/06/16.
//

#ifndef LAB3_MENSAJE_H
#define LAB3_MENSAJE_H

#include <string>
#include <ctime>
#include "../datatypes/DataMensaje.h"

using namespace std;

class Mensaje {
private:
    bool esInteresado;
    time_t TOA;
    string codigoPropiedad;
    string texto;
public:
    Mensaje(bool esInteresado, string mensaje, string date = "");
    time_t getTOA();
    DataMensaje CrearDataMensaje();
    ~Mensaje();
};


#endif //LAB3_MENSAJE_H
