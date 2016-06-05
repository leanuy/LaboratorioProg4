//
// Created by agus on 02/06/16.
//

#ifndef LAB6_DATAPROPIEDAD_H
#define LAB6_DATAPROPIEDAD_H

#include <string>

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

public:
    DataPropiedad();
    string getCodigo();
    void setCodigo(string codigo);
    int getAmbientes();
    void setAmbientes(int ambientes);
    int getDormitorios();
    void setDormitorios(int dormitorios);
    int getBanios();
    void setBanios(int banios);
    bool getGarage();
    void setGarage(bool garage);
    string getDireccion();
    void setDireccion(string direccion);
    float getMetrosCuadradosEdificados();
    void setMetrosCuadradosEdificados(float metrosCuadradosEdificados);
    float getMetrosCuadradosTotales();
    void setMetrosCuadradosTotales(float metrosCuadradosTotales);
    int getCantidadMensajes();
    void setCantidadMensajes(int CantidadMensajes);
    virtual ~DataPropiedad();
};


#endif //LAB6_DATAPROPIEDAD_H
