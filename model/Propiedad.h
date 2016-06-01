//
// Created by leandro on 31/05/16.
//

#ifndef LAB6_PROPIEDAD_H
#define LAB6_PROPIEDAD_H

#include <string>
#include "Conversacion.h"



using namespace std;

class Propiedad {
private:
    string codigo;
    int ambientes;
    int dormitorios;
    int banios;
    bool garage;
    string direccion;
    float metrosCuadradosEdificados;
    float metrosCuadradosTotales;

public:
    Propiedad();

    string getCodigo();
    void setCodigo(string code);
    int getAmbientes();
    void setAmbientes(int amb);
    int getDormitorios();
    void setDormitorios(int dor);
    int getBanios();
    void setBanios(int ban);
    bool tieneGarage();
    void setGarage(bool garage);
    string getDireccion();
    void setDireccion(string dir);
    float getM2Edificados();
    void setM2Edificados(float m2);
    float getM2Totales();
    void setM2Totales(float m2);


    void linkConversacion(Conversacion* c);
    DataPropiedad crearDataPropiedadExtendida();
    bool existeConversacion();
    //SET(DataMensaje) ListarMensajes();
    void InsertarNuevoMensaje(string mensaje);
    DataDepartamento ObtenerDepartamento();
    void Actualizar(DataPropiedad p);
    ~Propiedad();
};


#endif //LAB6_PROPIEDAD_H
