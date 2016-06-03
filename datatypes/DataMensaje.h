#ifndef LAB6_DATAMENSAJE_H
#define LAB6_DATAMENSAJE_H

#include <string>

using namespace std;

class DataMensaje {
private:
    bool isOwner;
    string texto;
public:
    DataMensaje(bool isOwnser, string mensaje);
    ~DataMensaje();

};


#endif //LAB6_DATAMENSAJE_H
