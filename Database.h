//
// Created by agus on 01/06/16.
//

#ifndef LAB6_DATABASE_H
#define LAB6_DATABASE_H

#include <map>

class Database {
private:
    Database instance;
    map<string, Departamento*>* departamentos;
    map<string, Usuario*>* usuarios;
    map<string, Edificio*>* edificiosN_A;
public:
    Database getInstance();
    map<string, Departamento*>* getDepartamentos();
    map<string, Usuario*>* getUsuarios();
    ~Database();
};


#endif //LAB6_DATABASE_H
