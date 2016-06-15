//
// Created by leandro on 01/06/16.
//

#include "Apartamento.h"
#include "../Sesion.h"

Apartamento::Apartamento(int ambientes, int dormitorios, int banios, bool garage,string direccion,
                         float m2Edificados, float m2Totales) {
    this->setAmbientes(ambientes);
    this->setDormitorios(dormitorios);
    this->setBanios(banios);
    this->setGarage(garage);
    this->setDireccion(direccion);
    this->setMetrosCuadradosEdificados(m2Edificados);
    this->setMetrosCuadradosTotales(m2Totales);
    this->setAlquiler(NULL);
    this->setVenta(NULL);
}

DataApartamento Apartamento::CrearDataPropiedad() {
    DataApartamento data = DataApartamento(this->getAmbientes(), this->getDormitorios(), this->getBanios(),
                                          this->tieneGarage(), this->getDireccion(),
                                          this->getMetrosCuadradosEdificados(), this->getMetrosCuadradosTotales());

    data.setCodigo(this->getCodigo());
    if(this->getAlquiler() != NULL){
        data.setAlquiler(this->getAlquiler()->getPrecio());
    }
    if(this->getVenta() != NULL){
        data.setVenta(this->getVenta()->getPrecio());
    }
    data.setInmobiliaria(this->getInmobiliaria()->getNombre(),this->getInmobiliaria()->getEmail(),this->getInmobiliaria()->getDireccion());

    Sesion* sesion = Sesion::getInstance();
    if(sesion->esTipo("interesado")){
        data.setCodigo(this->getCodigo());
        map<string, Conversacion*>::iterator it = this->conversaciones.find(this->getCodigo()+"-"+sesion->getEmail());
        if(it != this->conversaciones.end()){
            data.setCantidadMensajes(it->second->CantidadMensajes());
        }else{
            data.setCantidadMensajes(0);
        }
    }
    return data;
}

DataApartamento* Apartamento::CrearPtrDataPropiedad() {
    DataApartamento* data = new DataApartamento(this->getAmbientes(), this->getDormitorios(), this->getBanios(),
                                           this->tieneGarage(), this->getDireccion(),
                                           this->getMetrosCuadradosEdificados(), this->getMetrosCuadradosTotales());
    data->setCodigo(this->getCodigo());
    //data->setCantidadMensajes(0); agus: calcular cantidad de mensajes
    return data;
}

void Apartamento::setEdificio(Edificio *e) {
    this->edif = e;
}

Edificio *Apartamento::getEdificio() {
    return this->edif;
}

Apartamento::~Apartamento() {
    for(map<string, Conversacion*>::iterator it = this->conversaciones.begin(); it != this->conversaciones.end(); it++)
        it->second = NULL;
    this->conversaciones.clear();
    this->setInmobiliaria(NULL);
    this->edif = NULL;
}
