//
// Created by agus on 01/06/16.
//

#ifndef LAB3_MENSAJE_H
#define LAB3_MENSAJE_H


class Mensaje {
private:
    bool esInteresado;
    Fecha fecha;
    Hora hora;
    string texto;
public:
    Mensaje(string mensaje);
    DataMensaje CrearDataMensaje();
    ~Mensaje();
};


#endif //LAB3_MENSAJE_H
