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
map<string, Edificio*> Database::getEdificios(){
    return this->edificiosN_A;
}
void Database::AddUsuario(Usuario* usuario){
    this->usuarios.insert(this->usuarios.begin(), pair<string, Usuario*>(usuario->getEmail(), usuario));
}
void Database::AddEdificio(Edificio* edificio){
    this->edificiosN_A.insert(this->edificiosN_A.begin(), pair<string, Edificio*>(edificio->getNombre(), edificio));
    //this->edificiosN_A[edificio->getNombre()] = edificio; todo verificar cuando sobreescribe algo que ya estaba
}
Edificio* Database::RemoveEdificio(string idEdificio){
    Edificio* edificio;
    map<string, Edificio*>::iterator it = this->edificiosN_A.find(idEdificio);
    if(it != this->edificiosN_A.end()){
        edificio = it->second;
        this->edificiosN_A.erase(idEdificio);
    }else{
        edificio = NULL;
    }
}
Database::~Database(){}

