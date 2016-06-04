#include "Database.h"
Database* Database::instance = NULL;
Database::Database() { }
Database* Database::getInstance(){
    if(instance == NULL){
        instance = new Database();
    }
    return instance;
}
map<string, Departamento*> Database::getDepartamentos(){
    return this->departamentos;
};
map<string, Usuario*> Database::getUsuarios(){
    return this->usuarios;
}
void Database::AddUsuario(Usuario* usuario){
    this->usuarios.insert(this->usuarios.begin(), pair<string, Usuario*>(usuario->getEmail(), usuario));
}
Database::~Database(){}