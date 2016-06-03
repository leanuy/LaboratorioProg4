//
// Created by agus on 01/06/16.
//

#include "Database.h"
Database* Database::instance = NULL;
Database::Database() { }
Database* Database::getInstance(){
    if(instance == NULL){
        instance = new Database();
    }
    return instance;
}
map<string, Departamento*>* Database::getDepartamentos(){
    return this->departamentos;
};
map<string, Usuario*>* Database::getUsuarios(){
    return this->usuarios;
}
Database::~Database(){}