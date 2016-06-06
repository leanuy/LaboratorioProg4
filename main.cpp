#include <iostream>
#include "Database.h"

#include "interfaces/ILog.h"
#include "Sesion.h"
#include "Factory.h"

//forward declaration de las funciones
void doMenu();
void doComando();
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
        cout << "BIENVENIDO AL SISTEMA DE INMOBILIARIAS MICASA" << endl;
        cout << "---------------------------------------------" << endl;
        doIniciarSesion();
    }else{
        doMenu();
        doComando(); //todo: iterar

    }
//todo: ver de como loopear esta parte.
    return 0;
}
void doMenu(){
    Sesion* sesion = Sesion::getInstance();
    cout << "---------------------------------------------" << endl;
    if(sesion->isLogged()){
        if(sesion->esTipo("admin"))
            cout << "- Alta Inmobiliaria" << endl;
        if(sesion->esTipo("admin"))
            cout << "- Alta Interesado" << endl;
        if(sesion->esTipo("inmobiliaria"))
            cout << "- Alta Edificio" << endl;
        if(sesion->esTipo("inmobiliaria"))
            cout << "- Alta Propiedad" << endl;
        if(sesion->esTipo("interesado")||sesion->esTipo("inmobiliaria"))
            cout << "- Consultar Propiedad" << endl;
        if(sesion->esTipo("inmobiliaria"))
            cout << "- Modificar Propiedad" << endl;
        if(sesion->esTipo("inmobiliaria"))
            cout << "- Eliminar Propiedad" << endl;
        if(sesion->esTipo("interesado")||sesion->esTipo("inmobiliaria"))
            cout << "- Enviar Mensaje" << endl;
        if(sesion->esTipo("admin"))
            cout << "- Obtener Reporte Inmobiliarias" << endl;
    }
}
void doComando(){
    Sesion* sesion = Sesion::getInstance();

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
    //listar los departamentos
    //leer el depto seleccionado
    //mostrar las zonas de ese depto
    //leer la zona seleccionada
    //preguntar si es apartamento o casa y leer//
    //----si es apartamento listar los edificios en esa zona y dar opcion a hacer alta de edificio
    //si quier ingresar nuevo edificio correr alta edificio. y dejarlo como edificio actual.
    //sino leer el edificio que ingreso el usuario y dejarlo como actual.
    //luego pedir los daqtos del apartamento.
    //mandar ingresar apartamento.
    //-----
    //si queria ingresar una casa.. pedir datos y hacer ingresar casa/..
    //------
    //luego preguntar si quiere poner en alquiler.. si quiere poner en alquiler..
    //preguntar si quiere poner en venta.. si quiere poner en venta..
    //ahi pedimos el codigo de la propiedad y lo mostramos.
    //fin...
    delete interface;
}
void doConsultarPropiedad(){
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();
    //listar los departamentos
    //leer el depto seleccionado
    //mostrar las zonas de ese depto
    //leer la zona seleccionada
    //listar las propiedades en esa zona mostrando la lista de codigos y direccion
    //leer el codigo seleccionado.. ir a buscar e imprimier los datos de esa propiedad.
    //fin/
    delete interface;
}
void doModificarPropiedad(){
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();
    //ingresar el codigo de la propiedad a modificar
    //mostrar los datos actuales
    //pedir los datos denuevo
    //mandar guardar.
    //fin.
    delete interface;
}
void doEliminarPropiedad(){
    string code;
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();
    cout << "Ingrese el codigo de la propiedad que desea eliminar: ";
    cin >> code;
    try{
        interface->EliminarPropiedad(code);
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }
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