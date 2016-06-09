#include "Database.h"
#include "model/Interesado.h"
#include "model/Apartamento.h"
#include "model/Casa.h"

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
        map<string,Edificio*>::iterator it = this->edificiosN_A.find(edificio->getNombre());
        if(it != this->edificiosN_A.end()){
            throw std::invalid_argument("Edificio ya existe");
        }else{
            this->edificiosN_A[edificio->getNombre()] = edificio;
        }
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

void Database::AddData(){
    //ADD ADMIN:
    this->AddUsuario(new Admin());
    //ADD INMOBILIARIAS:
    this->AddUsuario(new Inmobiliaria("Selmo", "inm1@sis.com", "Benitez 1134", "pass4"));
    this->AddUsuario(new Inmobiliaria("Garcia", "inm2@sis.com", "Rivera 1340", "pass5"));
    this->AddUsuario(new Inmobiliaria("Invernissi", "inm3@sis.com", "Comercio 234", "pass6"));
    this->AddUsuario(new Inmobiliaria("Solei", "inm4@sis.com", "Inca 3456", "pass7"));
    //ADD INTERESADOS:
    this->AddUsuario(new Interesado("Julio", "Chaz", "int1@sis.com", 34, "passt1"));
    this->AddUsuario(new Interesado("Andrea", "Berruti", "int2@sis.com", 56, "passt2"));
    this->AddUsuario(new Interesado("Sonia", "Braga", "int3@sis.com", 45, "passt3"));
    this->AddUsuario(new Interesado("Alfonso", "Mier", "int4@sis.com", 30, "passt4"));
    this->AddUsuario(new Interesado("Juan", "Alpi", "int5@sis.com", 60, "passt5"));
    //ADD EDIFICIOS:
    this->AddEdificio(new Edificio("Apache Valiente", 4, 1300));
    this->AddEdificio(new Edificio("Mebeo", 20, 755));
    this->AddEdificio(new Edificio("Socrates", 34, 134));
    this->AddEdificio(new Edificio("El Burdel", 12, 450));
    this->AddEdificio(new Edificio("Milajo", 5, 3456));
    //ADD DEPARTAMENTOS:
        this->departamentos["A"] = new Departamento("Canelones", "A");
        this->departamentos["B"] = new Departamento("Maldonado", "B");
        this->departamentos["C"] = new Departamento("Rocha", "C");
        this->departamentos["D"] = new Departamento("Salto", "D");
        this->departamentos["E"] = new Departamento("Montevideo", "E");
    //ADD ZONAS:
    this->departamentos["A"]->AddZona(new Zona("101", "Zona1"));
    this->departamentos["A"]->AddZona(new Zona("102", "Zona2"));
    this->departamentos["B"]->AddZona(new Zona("103", "Zona3"));
    this->departamentos["D"]->AddZona(new Zona("104", "Zona4"));
    this->departamentos["D"]->AddZona(new Zona("105", "Zona5"));
    //ADD APARTAMENTOS:
    Apartamento* apartamento;
    apartamento = new Apartamento(2, 1, 1, false, "Iturria 1115 AP 104", 34, 34);
    apartamento->setEdificio(this->edificiosN_A["Apache Valiente"]);
    apartamento->setCodigo("1111");
    //todo: Agregar alquileres, venta  desde inmobiliaria y asociar lo alquileres con esta propiedad
    apartamento->setInmobiliaria(dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"]));
    this->departamentos["A"]->SeleccionarZona("Zona1")->AddPropiedad(apartamento);
    //todo: Asociar el edificio con la zona.

    apartamento = new Apartamento(3, 1, 1, false, "Iturria 1115 AP 105", 35, 35);
    apartamento->setEdificio(this->edificiosN_A["Apache Valiente"]);
    apartamento->setCodigo("1112");
    //todo: Agregar alquileres, venta  desde inmobiliaria y asociar lo alquileres con esta propiedad
    apartamento->setInmobiliaria(dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"]));
    this->departamentos["A"]->SeleccionarZona("Zona1")->AddPropiedad(apartamento);

    apartamento = new Apartamento(2, 1, 1, true, "Callejon 456 AP 01", 45, 45);
    apartamento->setEdificio(this->edificiosN_A["Mebeo"]);
    apartamento->setCodigo("1113");
    //todo: Agregar alquileres, venta  desde inmobiliaria y asociar lo alquileres con esta propiedad
    apartamento->setInmobiliaria(dynamic_cast<Inmobiliaria*>(this->usuarios["inm2@sis.com"]));
    this->departamentos["A"]->SeleccionarZona("Zona2")->AddPropiedad(apartamento);
    //todo: Asociar el edificio con la zona.

    apartamento = new Apartamento(7, 3, 2, true, "Corcega 3456 AP 2", 34, 34);
    apartamento->setEdificio(this->edificiosN_A["Socrates"]);
    apartamento->setCodigo("1114");
    //todo: Agregar alquileres, venta  desde inmobiliaria y asociar lo alquileres con esta propiedad
    apartamento->setInmobiliaria(dynamic_cast<Inmobiliaria*>(this->usuarios["inm2@sis.com"]));
    this->departamentos["B"]->SeleccionarZona("Zona3")->AddPropiedad(apartamento);
    //todo: Asociar el edificio con la zona.

    apartamento = new Apartamento(4, 1, 1, false, "Lucrecia 456 AP 2", 25, 25);
    apartamento->setEdificio(this->edificiosN_A["El Burdel"]);
    apartamento->setCodigo("1115");
    //todo: Agregar alquileres, venta  desde inmobiliaria y asociar lo alquileres con esta propiedad
    apartamento->setInmobiliaria(dynamic_cast<Inmobiliaria*>(this->usuarios["inm3@sis.com"]));
    this->departamentos["D"]->SeleccionarZona("Zona4")->AddPropiedad(apartamento);
    //todo: Asociar el edificio con la zona.

    apartamento = new Apartamento(2, 1, 1, false, "Lucrecia 456 AP 2", 25, 25); //todo: direccion erronea
    apartamento->setEdificio(this->edificiosN_A["El Burdel"]);
    apartamento->setCodigo("1116");
    //todo: Agregar alquileres, venta  desde inmobiliaria y asociar lo alquileres con esta propiedad
    apartamento->setInmobiliaria(dynamic_cast<Inmobiliaria*>(this->usuarios["inm4@sis.com"]));
    this->departamentos["D"]->SeleccionarZona("Zona4")->AddPropiedad(apartamento);
    //todo: Asociar el edificio con la zona.
    apartamento = NULL;
    //ADD CASAS:
    Casa* casa;
    casa = new Casa(12, 5, 1, true, "Chana 2345", 34, 44, 10);
    casa->setCodigo("2111");
    //todo: Agregar alquileres, venta  desde inmobiliaria y asociar lo alquileres con esta propiedad
    casa->setInmobiliaria(dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"]));
    this->departamentos["D"]->SeleccionarZona("Zona5")->AddPropiedad(casa);

    casa = new Casa(2, 1, 1, false, "Gloria 345", 35, 55, 20);
    casa->setCodigo("2111");
    //todo: Agregar alquileres, venta  desde inmobiliaria y asociar lo alquileres con esta propiedad
    casa->setInmobiliaria(dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"]));
    this->departamentos["D"]->SeleccionarZona("Zona5")->AddPropiedad(casa);
    //ADD MENSAJES:
}
void Database::DeleteData(){
    //DELETE PROPIEDADES:
    //DELETE EDIFICIOS N_A:
    //DELETE EDIFICIOS DE ZONAS:
    //DELETE ZONAS:
    //DELETE DEPARTAMENTOS:
    //DELETE ALQUILERES:
    //DELETE VENTAS:
    //DELETE CONVERSACIONES (MENSAJES PRIMERO) RECCORRER SOLO POR INMOBILIARIAS:
    //DELETE USUARIOS:
}
Database::~Database(){}

