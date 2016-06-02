//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_DATAZONA_H
#define LAB6_DATAZONA_H

#include <string>

using namespace std;

class DataZona {
private:
    string codigo;
    string nombre;
public:
    DataZona(string code,string name);
    ~DataZona();
    string getCodigo();
    string getNombre();
};


#endif //LAB6_DATAZONA_H
