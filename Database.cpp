//
// Created by agus on 01/06/16.
//

#include "Database.h"

Database Database::getInstance(){
    if(this->instance == NULL){
        this->instance = new Database();
    }
    return *this->instance;
}
map<string, Departamento*>* Database::getDepartamentos(){
    return this->departamentos;
};
map<string, Usuario*>* Database::getUsuarios(){
    return this->usuarios;
}
~Database();