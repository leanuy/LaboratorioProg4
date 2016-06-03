#ifndef LAB6_DATACONVERSACION_H
#define LAB6_DATACONVERSACION_H

#include <string>

using namespace std;

class DataConversacion {
private:
    string interesado;
    time_t lastUpdate;
public:
    DataConversacion(string interesado, time_t lastUpdate);
    string getInteresado();
    time_t getLastUpdate();
    ~DataConversacion();
};


#endif //LAB6_DATACONVERSACION_H
