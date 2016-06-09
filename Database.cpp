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
    map<string,Usuario*>::iterator it = this->usuarios.find(usuario->getEmail());
    if(it != this->usuarios.end()){
        throw std::invalid_argument("Usuario ya existe");
    }else{
        this->usuarios[usuario->getEmail()] = usuario;
    }
    //this->usuarios.insert(this->usuarios.begin(), pair<string, Usuario*>(usuario->getEmail(), usuario));
}
void Database::AddEdificio(Edificio* edificio){
        this->edificiosN_A.insert(this->edificiosN_A.begin(), pair<string, Edificio*>(edificio->getNombre(), edificio));
        //this->edificiosN_A[edificio->getNombre()] = edificio; todo verificar cuando sobreescribe algo que ya estaba
        //map<string,Edificio*>::iterator it = this->edificiosN_A.find(edificio->getNombre());
        //if(it != this->edificiosN_A.end()){
        //    throw std::invalid_argument("Edificio ya existe");
        //}else{
        //    this->edificiosN_A[edificio->getNombre()] = edificio;
        //}
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
    //todo no habria que eliminar el edificio? o ya el erase lo borra. si el erase borra ver poeque a veces no queremos eso
}
Database::~Database(){}

