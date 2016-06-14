//
// Created by leandro on 31/05/16.
//

#ifndef LAB6_PROPIEDAD_H
#define LAB6_PROPIEDAD_H

#include <string>

#include "../model/Conversacion.h"
#include "../datatypes/DataDepartamento.h"
#include "../datatypes/DataPropiedad.h"
#include "../model/Zona.h"
#include "../model/Inmobiliaria.h"


using namespace std;

class Zona;
class Inmobiliaria;
class Alquiler;
class Venta;
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
    Inmobiliaria* inmobiliaria;
    Zona* zona;
    Venta* venta;
    Alquiler* alquiler;

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
    float getMetrosCuadradosEdificados();
    void setMetrosCuadradosEdificados(float m2);
    float getMetrosCuadradosTotales();
    void setMetrosCuadradosTotales(float m2);
    Zona* getZona();
    void setZona(Zona * zona);
    Inmobiliaria* getInmobiliaria();
    void setInmobiliaria(Inmobiliaria * inmobiliaria);
    Alquiler* getAlquiler();
    void setAlquiler(Alquiler* a);
    Venta* getVenta();
    void setVenta(Venta* v);

    void LinkConversacion(Conversacion* c);
    bool ExisteConversacion();
    //SET(DataMensaje) ListarMensajes();
    void InsertarNuevoMensaje(string mensaje);
    DataDepartamento ObtenerDepartamento();
    void Actualizar(DataPropiedad p);
    virtual ~Propiedad() = 0;
};


#endif //LAB6_PROPIEDAD_H
