#include <iostream>
#include "Database.h"

#include "interfaces/ILog.h"
#include "Sesion.h"
#include "Factory.h"

//forward declaration de las funciones
void doMenu();
void doIniciarSesion();
void doAltaInteresado();//Admin
void doAltaInmobiliaria();//Admin
void doAltaEdificio();//Inmobiliaria
void doAltaPropiedad();//Inmobiliaria
void doConsultarPropiedad();//Interesado e Inmobiliaria
void doModificarPropiedad();//Inmobiliaria
void doEliminarPropiedad();//Inmobiliaria
void doEnviarMensaje(); //Interesado e Inmobiliaria todo: ver si es necesario separar los casos de uso de enviar mensaje en dos funciones
void doObtenerReporteInmobiliarias();//Admin
void doCerrarSesion();//Usuario


int main(){
    Sesion* sesion = Sesion::getInstance();
    if(!sesion->isLogged()){
        cout << "BIENVENIDO AL SISTEMA DE INMOBILIARIAS MICASA" << EOF;
        cout << "---------------------------------------------" << EOF;
        doIniciarSesion();
    }else{
        doMenu();
        string command;
        //todo: pedir comando
        if(command == "menu") doMenu();
        else if(command == "Alta Inmobiliaria"){if(sesion->esTipo("admin"))doAltaInmobiliaria();}
        else if(command == "Alta Interesado"){if(sesion->esTipo("admin"))doAltaInteresado();}
        else if(command == "Alta Edificio"){if(sesion->esTipo("inmobiliaria"))doAltaEdificio();}
        else if(command == "Alta Propiedad"){if(sesion->esTipo("inmobiliaria"))doAltaPropiedad();}
        else if(command == "Consultar Propiedad"){if(sesion->esTipo("interesado")||sesion->esTipo("inmobiliaria"))doConsultarPropiedad();}
        else if(command == "Modificar Propiedad"){if(sesion->esTipo("inmobiliaria"))doModificarPropiedad();}
        else if(command == "Eliminar Propiedad"){if(sesion->esTipo("inmobiliaria"))doEliminarPropiedad();}
        else if(command == "Enviar Mensaje"){if(sesion->esTipo("interesado")||sesion->esTipo("inmobiliaria"))doEnviarMensaje();}
        else if(command == "Obtener Reporte Inmobiliarias"){if(sesion->esTipo("admin"))doObtenerReporteInmobiliarias();}
        else if(command == "Cerrar Sesion"){doCerrarSesion();}
    }
//todo: ver de como loopear esta parte.
    return 0;
}
void doMenu(){
    Sesion* sesion = Sesion::getInstance();
    cout << "---------------------------------------------" << EOF;
    if(sesion->isLogged()){
        if(sesion->esTipo("admin"))
            cout << "- Alta Inmobiliaria" << EOF;
        if(sesion->esTipo("admin"))
            cout << "- Alta Interesado" << EOF;
        if(sesion->esTipo("inmobiliaria"))
            cout << "- Alta Edificio" << EOF;
        if(sesion->esTipo("inmobiliaria"))
            cout << "- Alta Propiedad" << EOF;
        if(sesion->esTipo("interesado")||sesion->esTipo("inmobiliaria"))
            cout << "- Consultar Propiedad" << EOF;
        if(sesion->esTipo("inmobiliaria"))
            cout << "- Modificar Propiedad" << EOF;
        if(sesion->esTipo("inmobiliaria"))
            cout << "- Eliminar Propiedad" << EOF;
        if(sesion->esTipo("interesado")||sesion->esTipo("inmobiliaria"))
            cout << "- Enviar Mensaje" << EOF;
        if(sesion->esTipo("admin"))
            cout << "- Obtener Reporte Inmobiliarias" << EOF;
    }
}

void doIniciarSesion(){
    Factory* factroy = Factory::getInstance();
    ILog* interface = factroy->getILog();

    delete interface;
}
void doAltaInmobiliaria(){
    Factory* factroy = Factory::getInstance();
    IUsuarios* interface = factroy->getIUsuarios();

    delete interface;
}
void doAltaInteresado(){
    Factory* factroy = Factory::getInstance();
    IUsuarios* interface = factroy->getIUsuarios();

    delete interface;
}
void doAltaEdificio(){ //todo: No tiene interface asignada
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();

    delete interface;
}
void doAltaPropiedad(){
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();

    delete interface;
}
void doConsultarPropiedad(){
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();

    delete interface;
}
void doModificarPropiedad(){
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();

    delete interface;
}
void doEliminarPropiedad(){
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();

    delete interface;
}
void doEnviarMensaje(){
    Factory* factroy = Factory::getInstance();
    IConversaciones* interface = factroy->getIConversaciones();

    delete interface;
}
void doObtenerReporteInmobiliarias(){
    Factory* factroy = Factory::getInstance();
    IUsuarios* interface = factroy->getIUsuarios();

    delete interface;
}
void doCerrarSesion(){
    Factory* factroy = Factory::getInstance();
    ILog* interface = factroy->getILog();

    delete interface;
}