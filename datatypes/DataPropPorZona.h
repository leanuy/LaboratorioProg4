//
// Created by leandro on 11/06/16.
//

#ifndef LAB6_DATAPROPPORZONA_H
#define LAB6_DATAPROPPORZONA_H

#include <string>

using namespace std;

class DataPropPorZona {
private:
    string idZona;
    int cantidadCasas;
    int cantidadAptos;
public:
    DataPropPorZona(string id);
    DataPropPorZona(string idZ,int casas,int aptos);
    ~DataPropPorZona();
    void incrementCasas();
    void incrementAptos();
    string getIdZona();
    int getCantCasas();
    int getCantAptos();
};


#endif //LAB6_DATAPROPPORZONA_H
