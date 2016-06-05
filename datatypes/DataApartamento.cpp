//
// Created by agus on 02/06/16.
//

#include "DataApartamento.h"

DataApartamento::DataApartamento(int ambientes, int dormitorios, int banios, bool garage, string direccion,
                                 float m2Edificados, float m2Totales) {
    this->setAmbientes(ambientes);
    this->setDormitorios(dormitorios);
    this->setBanios(banios);
    this->setGarage(garage);
    this->setDireccion(direccion);
    this->setMetrosCuadradosEdificados(m2Edificados);
    this->setMetrosCuadradosTotales(m2Totales);
}

DataApartamento::~DataApartamento() {

}
