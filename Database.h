//
// Created by agus on 01/06/16.
//

#ifndef LAB6_DATABASE_H
#define LAB6_DATABASE_H

#include <map>
#include <string>
#include "model/Departamento.h"
#include "model/Usuario.h"
#include "model/Edificio.h"

class Database {
private:
    Database* instance;
    map<string, Departamento*>* departamentos;
    map<string, Usuario*>* usuarios;
    map<string, Edificio*>* edificiosN_A;
public:
    static Database* getInstance();
    map<string, Departamento*>* getDepartamentos();
    map<string, Usuario*>* getUsuarios();
    ~Database();
};


#endif //LAB6_DATABASE_H
