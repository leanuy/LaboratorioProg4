#include "Database.h"
#include "model/Interesado.h"
#include "model/Apartamento.h"
#include "model/Casa.h"

Database* Database::instance = NULL;
Database::Database() {
    this->usuarios.clear();
    this->departamentos.clear();
    this->edificiosN_A.clear();
}
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
        this->edificiosN_A.erase(it);
    }else{
        edificio = NULL;
    }
    return edificio;
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
        this->departamentos["A"] = new Departamento("A", "Canelones");
        this->departamentos["B"] = new Departamento("B", "Maldonado");
        this->departamentos["C"] = new Departamento("C", "Rocha");
        this->departamentos["D"] = new Departamento("D", "Salto");
        this->departamentos["E"] = new Departamento("E", "Montevideo");
    //ADD ZONAS:
    this->departamentos["A"]->AddZona(new Zona("101", "Zona1"));
    this->departamentos["A"]->AddZona(new Zona("102", "Zona2"));
    this->departamentos["B"]->AddZona(new Zona("103", "Zona3"));
    this->departamentos["D"]->AddZona(new Zona("104", "Zona4"));
    this->departamentos["D"]->AddZona(new Zona("105", "Zona5"));
    //ADD APARTAMENTOS:
    Inmobiliaria * inmobiliaria;
    Edificio* edificio;
    Zona* zona;
    Apartamento* apartamento;
    apartamento = new Apartamento(2, 1, 1, false, "Iturria 1115 AP 104", 34, 34);
    apartamento->setEdificio(this->edificiosN_A["Apache Valiente"]);
    apartamento->setCodigo("1111");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"]);
    apartamento->setInmobiliaria(inmobiliaria);
    inmobiliaria->Vender(34567, apartamento);
    zona = this->departamentos["A"]->SeleccionarZona("101");
    zona->AddPropiedad(apartamento);
    edificio = this->RemoveEdificio("Apache Valiente");
    zona->AsignarEdificio(edificio);

    apartamento = new Apartamento(3, 1, 1, false, "Iturria 1115 AP 105", 35, 35);
    apartamento->setEdificio(edificio);
    apartamento->setCodigo("1112");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"]);
    apartamento->setInmobiliaria(inmobiliaria);
    inmobiliaria->Vender(65789, apartamento);
    this->departamentos["A"]->SeleccionarZona("101")->AddPropiedad(apartamento);

    apartamento = new Apartamento(2, 1, 1, true, "Callejon 456 AP 01", 45, 45);
    apartamento->setEdificio(this->edificiosN_A["Mebeo"]);
    apartamento->setCodigo("1113");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm2@sis.com"]);
    apartamento->setInmobiliaria(inmobiliaria);
    inmobiliaria->Alquilar(7689, apartamento);
    zona = this->departamentos["A"]->SeleccionarZona("102");
    zona->AddPropiedad(apartamento);
    edificio = this->RemoveEdificio("Mebeo");
    zona->AsignarEdificio(edificio);

    apartamento = new Apartamento(7, 3, 2, true, "Corcega 3456 AP 2", 34, 34);
    apartamento->setEdificio(this->edificiosN_A["Socrates"]);
    apartamento->setCodigo("1114");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm2@sis.com"]);
    apartamento->setInmobiliaria(inmobiliaria);
    inmobiliaria->Alquilar(6789, apartamento);
    zona = this->departamentos["B"]->SeleccionarZona("103");
    zona->AddPropiedad(apartamento);
    edificio = this->RemoveEdificio("Socrates");
    zona->AsignarEdificio(edificio);

    apartamento = new Apartamento(4, 1, 1, false, "Lucrecia 456 AP 2", 25, 25);
    apartamento->setEdificio(this->edificiosN_A["El Burdel"]);
    apartamento->setCodigo("1115");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm3@sis.com"]);
    apartamento->setInmobiliaria(inmobiliaria);
    inmobiliaria->Alquilar(7890, apartamento);
    zona = this->departamentos["D"]->SeleccionarZona("104");
    zona->AddPropiedad(apartamento);
    edificio = this->RemoveEdificio("El Burdel");
    zona->AsignarEdificio(edificio);

    apartamento = new Apartamento(2, 1, 1, false, "Lucrecia 456 AP 2", 25, 25); //todo: direccion erronea
    apartamento->setEdificio(edificio);
    apartamento->setCodigo("1116");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm4@sis.com"]);
    apartamento->setInmobiliaria(inmobiliaria);
    inmobiliaria->Alquilar(768, apartamento);
    this->departamentos["D"]->SeleccionarZona("104")->AddPropiedad(apartamento);

    apartamento = NULL;
    edificio = NULL;
    zona = NULL;
    //ADD CASAS:
    Casa* casa;
    casa = new Casa(12, 5, 1, true, "Chana 2345", 34, 44, 10);
    casa->setCodigo("2111");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"]);
    casa->setInmobiliaria(inmobiliaria);
    inmobiliaria->Vender(45000, casa);
    this->departamentos["D"]->SeleccionarZona("105")->AddPropiedad(casa);

    casa = new Casa(2, 1, 1, false, "Gloria 345", 35, 55, 20);
    casa->setCodigo("2112");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"]);
    casa->setInmobiliaria(inmobiliaria);
    inmobiliaria->Vender(34560, casa);
    this->departamentos["D"]->SeleccionarZona("105")->AddPropiedad(casa);

    casa = new Casa(3, 1, 1, false, "Chapaz 345", 12, 22, 10);
    casa->setCodigo("2113");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm2@sis.com"]);
    casa->setInmobiliaria(inmobiliaria);
    inmobiliaria->Vender(13000, casa);
    this->departamentos["A"]->SeleccionarZona("101")->AddPropiedad(casa);

    casa = new Casa(6, 3, 2, true, "Juanico 456", 34, 34, 0);
    casa->setCodigo("2114");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm3@sis.com"]);
    casa->setInmobiliaria(inmobiliaria);
    inmobiliaria->Alquilar(20000, casa);
    this->departamentos["A"]->SeleccionarZona("102")->AddPropiedad(casa);

    casa = new Casa(3, 1, 1, false, "Venecia 3456", 25, 25, 0);
    casa->setCodigo("2115");
    inmobiliaria = dynamic_cast<Inmobiliaria*>(this->usuarios["inm4@sis.com"]);
    casa->setInmobiliaria(inmobiliaria);
    inmobiliaria->Alquilar(56789, casa);
    this->departamentos["A"]->SeleccionarZona("101")->AddPropiedad(casa);

    //ADD MENSAJES:
    Conversacion* conversacion;

    conversacion = new Conversacion();
    conversacion->AgregarMensaje(true, "PERDON ME EQUIVOQUE", "2111", "2016-05-23 12:35");
    dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"])->AddConversacion("int3@sis.com", conversacion);
    dynamic_cast<Interesado*>(this->usuarios["int3@sis.com"])->AddConversacion("inm1@sis.com", conversacion);

    conversacion = new Conversacion();
    conversacion->AgregarMensaje(true, "Cuanto cuesta?", "2114", "2016-05-24 12:30");
    dynamic_cast<Inmobiliaria*>(this->usuarios["inm3@sis.com"])->AddConversacion("int2@sis.com", conversacion);
    dynamic_cast<Interesado*>(this->usuarios["int2@sis.com"])->AddConversacion("inm3@sis.com", conversacion);

    conversacion = new Conversacion();
    conversacion->AgregarMensaje(true, "Estoy Interesado", "2111", "2016-05-25 13:02");
    dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"])->AddConversacion("int1@sis.com", conversacion);
    dynamic_cast<Interesado*>(this->usuarios["int1@sis.com"])->AddConversacion("inm1@sis.com", conversacion);

    conversacion = new Conversacion();
    conversacion->AgregarMensaje(true, "Quiero hacer una oferta ya!", "1111", "2016-06-01 00:30");
    dynamic_cast<Inmobiliaria*>(this->usuarios["inm2@sis.com"])->AddConversacion("int4@sis.com", conversacion);
    dynamic_cast<Interesado*>(this->usuarios["int4@sis.com"])->AddConversacion("inm2@sis.com", conversacion);

    conversacion = new Conversacion();
    conversacion->AgregarMensaje(true, "tiene humedad?", "1112", "2016-06-02 12:45");
    dynamic_cast<Inmobiliaria*>(this->usuarios["inm4@sis.com"])->AddConversacion("int1@sis.com", conversacion);
    dynamic_cast<Interesado*>(this->usuarios["int1@sis.com"])->AddConversacion("inm4@sis.com", conversacion);

    conversacion = new Conversacion();
    conversacion->AgregarMensaje(true, "Cual es el precio?", "1113", "2016-06-03 02:05");
    dynamic_cast<Inmobiliaria*>(this->usuarios["inm1@sis.com"])->AddConversacion("int5@sis.com", conversacion);
    dynamic_cast<Interesado*>(this->usuarios["int5@sis.com"])->AddConversacion("inm1@sis.com", conversacion);
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

