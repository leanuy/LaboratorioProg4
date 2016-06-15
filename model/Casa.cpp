//
// Created by leandro on 01/06/16.
//

#include "Casa.h"
#include "../Sesion.h"

Casa::Casa(int ambientes, int dormitorios, int banios, bool garage, string direccion, float m2Edificados,
           float m2Totales, float m2Verdes) {
    this->setAmbientes(ambientes);
    this->setDormitorios(dormitorios);
    this->setBanios(banios);
    this->setGarage(garage);
    this->setDireccion(direccion);
    this->setMetrosCuadradosEdificados(m2Edificados);
    this->setMetrosCuadradosTotales(m2Totales);
    this->setMetrosCuadradosVerdes(m2Verdes);
    this->setAlquiler(NULL);
    this->setVenta(NULL);
}

DataCasa Casa::CrearDataPropiedad() {
    DataCasa data = DataCasa(this->getAmbientes(), this->getDormitorios(), this->getBanios(), this->tieneGarage(),
                            this->getDireccion(), this->getMetrosCuadradosEdificados(),
                            this->getMetrosCuadradosTotales(), this->getMetrosCuadradosVerdes());
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
        map<string, Conversacion*>::iterator it = this->conversaciones.find(this->getCodigo()+"-"+sesion->getEmail());
        if(it != this->conversaciones.end()){
            data.setCantidadMensajes(it->second->CantidadMensajes());
        }else{
            data.setCantidadMensajes(0);
        }
    }

    return data;
}

DataCasa* Casa::CrearPtrDataPropiedad() {
    DataCasa* data = new DataCasa(this->getAmbientes(), this->getDormitorios(), this->getBanios(), this->tieneGarage(),
                             this->getDireccion(), this->getMetrosCuadradosEdificados(),
                             this->getMetrosCuadradosTotales(), this->getMetrosCuadradosVerdes());

    data->setCodigo(this->getCodigo());
    return data;
}

float Casa::getMetrosCuadradosVerdes() {
    return this->metrosCuadradosVerdes;
}

void Casa::setMetrosCuadradosVerdes(float m2verdes) {
    this->metrosCuadradosVerdes = m2verdes;
}


Casa::~Casa() {
    for(map<string, Conversacion*>::iterator it = this->conversaciones.begin(); it != this->conversaciones.end(); it++)
        it->second = NULL;
    this->conversaciones.clear();
    this->setInmobiliaria(NULL);
}


