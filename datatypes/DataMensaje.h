#ifndef LAB6_DATAMENSAJE_H
#define LAB6_DATAMENSAJE_H

#include <string>

using namespace std;

class DataMensaje {
private:
    bool esInteresado;
    string texto;
    string idPropiedad;
    time_t TOA;
public:
    DataMensaje(bool esInteresado, string mensaje, time_t TOA, string idPropiedad);
    bool isInteresado();
    string getTexto();
    string getIdPropiedad();
    string getTOA();
    ~DataMensaje();

};


#endif //LAB6_DATAMENSAJE_H
