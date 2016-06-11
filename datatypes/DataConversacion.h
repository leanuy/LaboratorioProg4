#ifndef LAB6_DATACONVERSACION_H
#define LAB6_DATACONVERSACION_H

#include <string>

using namespace std;

class DataConversacion {
private:
    string interesado;
    int cantidadMensajes;
    time_t lastUpdate;
public:
    DataConversacion(string interesado, time_t lastUpdate, int cantidadMensajes);
    string getInteresado();
    int getCantidadMensajes();
    time_t getLastUpdate();
    string getLastUpdateStr();
    ~DataConversacion();
};


#endif //LAB6_DATACONVERSACION_H
