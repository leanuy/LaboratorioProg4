#include "DataPropiedad.h"

DataPropiedad::DataPropiedad(){}

string DataPropiedad::getCodigo(){
    return this->codigo;
}

void DataPropiedad::setCodigo(string codigo) {
    this->codigo = codigo;
}

int DataPropiedad::getAmbientes(){
    return this->ambientes;
}

void DataPropiedad::setAmbientes(int ambientes) {
    this->ambientes = ambientes;
}

int DataPropiedad::getDormitorios(){
    return this->dormitorios;
}

void DataPropiedad::setDormitorios(int dormitorios) {
    this->dormitorios = dormitorios;
}

int DataPropiedad::getBanios(){
    return this->banios;
}

void DataPropiedad::setBanios(int banios) {
    this->banios = banios;
}

bool DataPropiedad::getGarage(){
    return this->garage;
}

void DataPropiedad::setGarage(bool garage) {
    this->garage = garage;
}

string DataPropiedad::getDireccion(){
    return this->direccion;
}

void DataPropiedad::setDireccion(string direccion) {
    this->direccion = direccion;
}

float DataPropiedad::getMetrosCuadradosEdificados(){
    return this->metrosCuadradosEdificados;
}

void DataPropiedad::setMetrosCuadradosEdificados(float metrosCuadradosEdificados) {
    this->metrosCuadradosEdificados = metrosCuadradosEdificados;
}

float DataPropiedad::getMetrosCuadradosTotales(){
    return this->metrosCuadradosTotales;
}

void DataPropiedad::setMetrosCuadradosTotales(float metrosCuadradosTotales) {
    this->metrosCuadradosTotales = metrosCuadradosTotales;
}

int DataPropiedad::getCantidadMensajes(){
    return this->CantidadMensajes;
}

void DataPropiedad::setCantidadMensajes(int CantidadMensajes) {
    this->CantidadMensajes = CantidadMensajes;
}
time_t DataPropiedad::getLastUpdate(){
    return this->lastUpdate;
}
string DataPropiedad::getLastUpdateStr(){
    char buff[20];
    time_t now = this->lastUpdate;
    strftime(buff, 20, "%d/%m/%Y %H:%M", localtime(&now));
    return string (buff);
}

void DataPropiedad::setLastUpdate(time_t lastUpdate){
    this->lastUpdate = lastUpdate;
}

DataPropiedad::~DataPropiedad(){}
