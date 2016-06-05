//
// Created by leandro on 01/06/16.
//

#include "Casa.h"

Casa::Casa(int ambientes, int dormitorios, int banios, bool garage, string direccion, float m2Edificados,
           float m2Totales, float m2Verdes) {
    this->setAmbientes(ambientes);
    this->setDormitorios(dormitorios);
    this->setBanios(banios);
    this->setGarage(garage);
    this->setDireccion(direccion);
    this->setMetrosCuadradosTotales(m2Edificados);
    this->setMetrosCuadradosTotales(m2Totales);
    this->setMetrosCuadradosVerdes(m2Verdes);
}

DataPropiedad Casa::CrearDataPropiedad() {
    DataCasa data = DataCasa(this->getAmbientes(), this->getDormitorios(), this->getBanios(), this->tieneGarage(),
                            this->getDireccion(), this->getMetrosCuadradosEdificados(),
                            this->getMetrosCuadradosTotales(), this->getMetrosCuadradosVerdes());

    //data->setCantidadMensajes(0); agus: calcular cantidad de mensajes
    return data;
}

DataPropiedad* Casa::CrearPtrDataPropiedad() {
    DataCasa* data = new DataCasa(this->getAmbientes(), this->getDormitorios(), this->getBanios(), this->tieneGarage(),
                             this->getDireccion(), this->getMetrosCuadradosEdificados(),
                             this->getMetrosCuadradosTotales(), this->getMetrosCuadradosVerdes());

    //data->setCantidadMensajes(0); agus: calcular cantidad de mensajes
    return data;
}

float Casa::getMetrosCuadradosVerdes() {
    return this->metrosCuadradosVerdes;
}

void Casa::setMetrosCuadradosVerdes(float m2verdes) {
    this->metrosCuadradosVerdes = m2verdes;
}


Casa::~Casa() {

}


