//
// Created by agus on 02/06/16.
//

#ifndef LAB6_DATAPROPIEDAD_H
#define LAB6_DATAPROPIEDAD_H

#include <string>
#include "../datatypes/DataReporteInmobiliaria.h"

using namespace std;

class DataPropiedad {
private:
    string codigo;
    int ambientes;
    int dormitorios;
    int banios;
    bool garage;
    string direccion;
    float metrosCuadradosEdificados;
    float metrosCuadradosTotales;
    int CantidadMensajes;
    time_t lastUpdate;

    bool enAlquiler;
    bool enVenta;
    float precioAlquiler;
    float precioVenta;
    DataReporteInmobiliaria inmobiliaria;

protected:
    void setCodigo(string codigo);
    void setAmbientes(int ambientes);
    void setDormitorios(int dormitorios);
    void setBanios(int banios);
    void setGarage(bool garage);
    void setDireccion(string direccion);
    void setMetrosCuadradosEdificados(float metrosCuadradosEdificados);
    void setMetrosCuadradosTotales(float metrosCuadradosTotales);
    void setCantidadMensajes(int CantidadMensajes);
    void setLastUpdate(time_t lastUpdate);
    void setAlquiler(float precio);
    void setVenta(float precio);
    void setInmobiliaria(string nombre,string mail,string dir);
public:
    DataPropiedad();
    string getCodigo();
    int getAmbientes();
    int getDormitorios();
    int getBanios();
    bool getGarage();
    string getDireccion();
    float getMetrosCuadradosEdificados();
    float getMetrosCuadradosTotales();
    int getCantidadMensajes();
    time_t getLastUpdate();
    string getLastUpdateStr();
    float getAlquiler();
    float getVenta();
    DataReporteInmobiliaria getInmobiliaria();

    virtual ~DataPropiedad();

    friend class Casa;
    friend class Apartamento;
};


#endif //LAB6_DATAPROPIEDAD_H
