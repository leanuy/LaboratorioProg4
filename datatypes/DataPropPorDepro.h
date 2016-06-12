//
// Created by leandro on 11/06/16.
//

#ifndef LAB6_DATAPROPPORDEPRO_H
#define LAB6_DATAPROPPORDEPRO_H

#include <string>
#include <list>
#include "../datatypes/DataPropPorZona.h"

using namespace std;

class DataPropPorDepro {
private:
    string idDepto;
    list<DataPropPorZona> porDeptos;
public:
    DataPropPorDepro(string idDepto);
    ~DataPropPorDepro();
    void setPropsPorDeptos(list<DataPropPorZona> l);
    string getIdDepto();
    list<DataPropPorZona> getPorDeptos();
};


#endif //LAB6_DATAPROPPORDEPRO_H
