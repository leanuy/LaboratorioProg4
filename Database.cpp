//
// Created by agus on 01/06/16.
//

#include "Database.h"

static Database* Database::getInstance(){
    if(instance == NULL){
        this->instance = new Database();
    }
    return this->instance;
}
map<string, Departamento*>* Database::getDepartamentos(){
    return this->departamentos;
};
map<string, Usuario*>* Database::getUsuarios(){
    return this->usuarios;
}
Database::~Database(){}