//
// Created by leandro on 31/05/16.
//

#include "PropiedadesController.h"

int PropiedadesController::codigoPropiedadTotal = 0;

void PropiedadesController::SeleccionarDepartamento(string idDepartamento) {
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.find(idDepartamento);
    if(it == deptos.end()){
        throw std::invalid_argument( "El departamento no existe en el sistema" );
    }
    this->dActual = it->second;
}

void PropiedadesController::SeleccionarZona(string idZona) {
    this->zActual= this->dActual->SeleccionarZona(idZona);
}

void PropiedadesController::SeleccionarEdificio(string idEdificio) {
    this->eActual = SeleccionarEdificioPriv(idEdificio);
    if(this->eActual == NULL){
        throw std::invalid_argument("El edificio ingresado no se encuentra en el sistema");
    }
}

void PropiedadesController::ingresarApartamento(DataApartamento apartamento) {
    Apartamento* apto = new Apartamento(apartamento.getAmbientes(),apartamento.getDormitorios(),
                            apartamento.getBanios(),apartamento.getGarage(),apartamento.getDireccion(),
                            apartamento.getMetrosCuadradosEdificados(),apartamento.getMetrosCuadradosTotales());
    apto->setEdificio(eActual);
    apto->setCodigo(generarCodigo());
    Sesion* s = Sesion::getInstance();
    Inmobiliaria* inmobiliaria =(Inmobiliaria*)s->getUsuario();
    apto->setInmobiliaria(inmobiliaria);
    inmobiliaria->AddPropiedad(apto);
    apto->setZona(this->zActual);
    this->zActual->AgregarPropiedad(apto);
    this->pActual = apto;
}

void PropiedadesController::ingresarCasa(DataCasa casa) {
    Casa* ca = new Casa(casa.getAmbientes(),casa.getDormitorios(),
                                       casa.getBanios(),casa.getGarage(),casa.getDireccion(),
                                       casa.getMetrosCuadradosEdificados(),casa.getMetrosCuadradosTotales(),
                                        casa.getM2Verdes());
    ca->setCodigo(generarCodigo());
    Sesion* s = Sesion::getInstance();
    Inmobiliaria* inmobiliaria =(Inmobiliaria*)s->getUsuario();
    ca->setInmobiliaria(inmobiliaria);
    inmobiliaria->AddPropiedad(ca);

    ca->setZona(this->zActual);
    this->zActual->AgregarPropiedad(ca);
    this->pActual = ca;
}

void PropiedadesController::ponerEnAlquiler(float precio) {
    Sesion* s = Sesion::getInstance();
    Inmobiliaria* inmo = (Inmobiliaria*)s->getUsuario();
    inmo->Alquilar(precio,pActual);
}

void PropiedadesController::ponerEnVenta(float precio) {
    Sesion* s = Sesion::getInstance();
    Inmobiliaria* inmo = (Inmobiliaria*)s->getUsuario();
    inmo->Vender(precio,pActual);
}

string PropiedadesController::getCodigPropiedad() {
    return pActual->getCodigo();
}

void PropiedadesController::EliminarPropiedad(string codigoPropiedad) {
    this->pActual = buscarPropiedadPriv(codigoPropiedad);
    Sesion* sesion = Sesion::getInstance();
    Usuario* u = sesion->getUsuario();
    if(this->pActual->getInmobiliaria() == u) {
        this->pActual->DesvincularConversaciones();
        Zona *z = this->pActual->getZona();
        z->eliminarPropiedad(codigoPropiedad);
    }else{
        throw std::invalid_argument("La propiedad no pertenece a su inmobiliaria");
    }
}

DataPropiedad* PropiedadesController::verPropiedad(string codigoPropiedad) {
    this->pActual = buscarPropiedadPriv(codigoPropiedad);
    Sesion* sesion = Sesion::getInstance();
    Usuario* u = sesion->getUsuario();
    if(this->pActual->getInmobiliaria() == u) {
        if (dynamic_cast<Casa *>(this->pActual)){
            DataCasa *c = dynamic_cast<Casa *>(this->pActual)->CrearPtrDataPropiedad();
            return c;
        } else {
            DataApartamento *d = dynamic_cast<Apartamento *>(this->pActual)->CrearPtrDataPropiedad();
            return d;
        }
    }else{
        throw std::invalid_argument("La propiedad no pertenece a su inmobiliaria");
    }
}

void PropiedadesController::actualizarPropiedad(DataPropiedad p) {
        this->pActual->setAmbientes(p.getAmbientes());
        this->pActual->setDormitorios(p.getDormitorios());
        this->pActual->setBanios(p.getBanios());
        this->pActual->setGarage(p.getGarage());
        this->pActual->setDireccion(p.getDireccion());
        this->pActual->setMetrosCuadradosEdificados(p.getMetrosCuadradosEdificados());
        this->pActual->setMetrosCuadradosTotales(p.getMetrosCuadradosTotales());
        if(dynamic_cast<Casa*>(this->pActual) != NULL){
            Casa* ca = dynamic_cast<Casa*>(this->pActual);
            ca->setMetrosCuadradosVerdes(p.getMetrosCuadradosTotales()-p.getMetrosCuadradosEdificados());
        }
        this->pActual = NULL; //desvinculo la propiedad actual del controlador
        // la propiedad ya quedo actualizada.
}

Edificio *PropiedadesController::SeleccionarEdificioPriv(string idEdificio) {
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.begin();
    Edificio* p = NULL;
    while((it != deptos.end())&&(p == NULL)){
        p = it->second->BuscarEdificio(idEdificio);
        it++;
    }
    if(p == NULL){ //busco en los edificios sin asignar
        map<string,Edificio*> edifs = db->getEdificios();
        map<string,Edificio*>::iterator iter = edifs.find(idEdificio);
        if(iter != edifs.end()){
            p = iter->second;
            db->RemoveEdificio(p->getNombre());
            this->zActual->AsignarEdificio(p);
        }
    }
    return p;
}

Propiedad *PropiedadesController::buscarPropiedadPriv(string codigoPropiedad) {
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.begin();
    Propiedad* p = NULL;
    while((it != deptos.end())&&(p == NULL)){
        p = it->second->BuscarPropiedad(codigoPropiedad);
        it++;
    }
    if(it == deptos.end() && p == NULL){
        throw std::invalid_argument( "La propiedad no se encuentra en el sistema" );
    }
    return p;
}

string PropiedadesController::generarCodigo() {
    string codigo = dActual->getId();
    codigo.operator+=(zActual->getCodigo());
    codigo.operator+=(to_string(codigoPropiedadTotal++));
    return codigo;
}

PropiedadesController::PropiedadesController() {
    this->zActual = NULL;
    this->pActual = NULL;
    this->dActual = NULL;
    this->eActual = NULL;
}

PropiedadesController::~PropiedadesController() {

}

DataPropiedad PropiedadesController::BuscarPropiedad(string codigo) {
    this->pActual = buscarPropiedadPriv(codigo);
    if(dynamic_cast<Casa*>(this->pActual)){
        DataCasa c = dynamic_cast<Casa*>(this->pActual)->CrearDataPropiedad();
        return c;
    }else{
        DataApartamento d = dynamic_cast<Apartamento*>(this->pActual)->CrearDataPropiedad();
        return d;
    }
}

list <DataDepartamento> PropiedadesController::ListarDepartamentos() {
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator it = deptos.begin();
    if(it == deptos.end()){
        throw std::invalid_argument("No hay Departamentos");
    }
    list<DataDepartamento> li;
    list<DataDepartamento>::iterator iter = li.begin();
    while(it != deptos.end()){
        li.insert(iter,it->second->CrearDataDepartamento());
        iter = li.begin();
        it++;
    }
    return li;
}

list <DataZona> PropiedadesController::ListarZonas() {
    return this->dActual->ListarZonas();
}

list <DataEdificio> PropiedadesController::VerEdificiosZona() {
    return zActual->DevolverEdificios();
}


list <DataEdificio> PropiedadesController::edificiosSinAsignar() {
    Database* db = Database::getInstance();
    map<string,Edificio*> edificios = db->getEdificios();
    map<string,Edificio*>::iterator it = edificios.begin();
    list<DataEdificio> lista;
    if(it == edificios.end()){
        throw std::invalid_argument("No hay edificios sin asignar");
    }
    while(it != edificios.end()){
        lista.push_back(it->second->CrearDataEdificio());
        it++;
    }
    return lista;
}

list<DataPropiedad> PropiedadesController::ListarPropiedades(){
    return this->zActual->ListarPropiedadesEstaticas();
}

void PropiedadesController::IngresarEdificio(DataEdificio e) {
    Edificio* edi = new Edificio(e.getNombre(),e.getPisos(),e.getGastoComunes());
    Database* db = Database::getInstance();
    map<string,Departamento*> deptos = db->getDepartamentos();
    map<string,Departamento*>::iterator i = deptos.begin();
    while(i != deptos.end()){
        i->second->chequearEdificioEnZonas(e.getNombre());
        i++;
    }
    db->AddEdificio(edi);
}
