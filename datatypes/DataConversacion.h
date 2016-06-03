#ifndef LAB6_DATACONVERSACION_H
#define LAB6_DATACONVERSACION_H

#include <string>

using namespace std;

class DataConversacion {
private:
    string interesado;
public:
    DataConversacion(string interesado);
    string getInteresado();
    ~DataConversacion();
};


#endif //LAB6_DATACONVERSACION_H
