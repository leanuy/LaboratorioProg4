//
// Created by leandro on 01/06/16.
//

#ifndef LAB6_DATADEPARTAMENTO_H
#define LAB6_DATADEPARTAMENTO_H

#include <string>
using namespace std;

class DataDepartamento {
private:
    string id;
    string nombre;
public:
    DataDepartamento(string id,string nombre);
    ~DataDepartamento();
    string getId();
    string getNombre();
};


#endif //LAB6_DATADEPARTAMENTO_H
