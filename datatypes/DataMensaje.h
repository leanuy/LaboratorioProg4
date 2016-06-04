#ifndef LAB6_DATAMENSAJE_H
#define LAB6_DATAMENSAJE_H

#include <string>

using namespace std;

class DataMensaje {
private:
    bool esInteresado;
    string texto;
public:
    DataMensaje(bool esInteresado, string mensaje);
    ~DataMensaje();

};


#endif //LAB6_DATAMENSAJE_H
