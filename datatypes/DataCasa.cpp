//
// Created by agus on 02/06/16.
//

#include "DataCasa.h"

DataCasa::DataCasa(int ambientes, int dormitorios, int banios, bool garage, string direccion, float m2Edificados,
                   float m2Totales, float m2Verdes) {
    this->setAmbientes(ambientes);
    this->setDormitorios(dormitorios);
    this->setBanios(banios);
    this->setGarage(garage);
    this->setDireccion(direccion);
    this->setMetrosCuadradosEdificados(m2Edificados);
    this->setMetrosCuadradosTotales(m2Totales);
    this->metrosCuadradosVerdes = m2Verdes;
    this->setVenta(0);
    this->setAlquiler(0);
}

DataCasa::~DataCasa() {

}

float DataCasa::getM2Verdes() {
    return this->metrosCuadradosVerdes;
}
