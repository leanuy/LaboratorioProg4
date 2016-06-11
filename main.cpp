#include <iostream>
#include "Database.h"

#include "interfaces/ILog.h"
#include "Sesion.h"
#include "Factory.h"

using namespace std;

//forward declaration de las funciones
void doMenu();
bool doComando();
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


int main() {
    bool salir = false;
    string com, opcion;
    Sesion *sesion = Sesion::getInstance();
    cout << "BIENVENIDO AL SISTEMA DE INMOBILIARIAS MICASA" << endl;
    cout << "---------------------------------------------" << endl;
    while (!salir) {
        if (!sesion->isLogged()) {
            cout << "Ingrese una de las opciones: 'Iniciar Sesion' o 'salir': " << endl;
            getline(cin,com);
            if(com == "Iniciar Sesion"){
                doIniciarSesion();
                if(sesion->isLogged()){
                    doMenu();
                }
            }else{
                cout << "El programa se va a cerrar, desea salir? [S/N]: ";
                getline(cin,opcion);
                salir = ((opcion == "S")||(opcion == "s"));
            }
        } else {
            salir = doComando();
        }
    }
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
        cout << "- Cerrar Sesion" << endl;
    }
}
bool doComando(){
    Sesion* sesion = Sesion::getInstance();

    string command;
    //todo: pedir comando
    cout << "Ingresar una opcion del menu: ";
    getline(cin,command);
    cout << endl;
    if(command == "menu") {
        doMenu();
        return false;
    }
    else if(command == "Alta Inmobiliaria"){if(sesion->esTipo("admin"))doAltaInmobiliaria();return false;}
    else if(command == "Alta Interesado"){if(sesion->esTipo("admin"))doAltaInteresado();return false;}
    else if(command == "Alta Edificio"){if(sesion->esTipo("inmobiliaria"))doAltaEdificio();return false;}
    else if(command == "Alta Propiedad"){if(sesion->esTipo("inmobiliaria"))doAltaPropiedad();return false;}
    else if(command == "Consultar Propiedad"){if(sesion->esTipo("interesado")||sesion->esTipo("inmobiliaria"))doConsultarPropiedad();return false;}
    else if(command == "Modificar Propiedad"){if(sesion->esTipo("inmobiliaria"))doModificarPropiedad();return false;}
    else if(command == "Eliminar Propiedad"){if(sesion->esTipo("inmobiliaria"))doEliminarPropiedad();return false;}
    else if(command == "Enviar Mensaje"){if(sesion->esTipo("interesado")||sesion->esTipo("inmobiliaria"))doEnviarMensaje();return false;}
    else if(command == "Obtener Reporte Inmobiliarias"){if(sesion->esTipo("admin"))doObtenerReporteInmobiliarias();return false;}
    else if(command == "Cerrar Sesion"){doCerrarSesion();return false;}
    //else if(command == ""){return false;}
    else if(command == "salir"){return true;}
    else {return false;}
}


void doIniciarSesion(){
    string email;
    bool first;
    string psw1, psw2;
    bool iguales;
    bool incorrecta;
    Factory* factroy = Factory::getInstance();
    ILog* interface = factroy->getILog();
    cout << "Ingrese su Email: ";
    getline(cin, email);
    cout << endl;
    try{
        first = interface->IngresarEmail(email);
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }

    if (first){
        iguales = false;
        cout << "Es la primera vez que ingresa al sistema, se le pedira que ingrese una contrasenia y luego la confirme" << endl;
        while(! iguales) {
            cout << "Ingresar Contrasenia:";
            getline(cin, psw1);
            cout << endl;
            cout << "Confirmar Contrasenia:";
            getline(cin, psw2);
            cout << endl;
            iguales = interface->SetearPassword(psw1, psw2);
            if (! iguales){
                cout << "Las contrasenias ingresadas no coinciden, vuelva a intentar" << endl;
            };
        }
    }
    else{
        incorrecta = true;
        while (incorrecta) {
            cout << "Ingresar Contrasenia:";
            getline(cin, psw1);
            cout << endl;
            incorrecta = !interface->IngresarPassword(psw1);
            if (incorrecta) {
                cout << "La contrasenia ingresada es incorrecta" << endl;
            };
        }
    };
    delete interface;
}


void doAltaInmobiliaria(){
    //nmobiliaria(string nombre, string mail, string direccion);
    string nombre;
    string mail;
    string direccion;
    bool cambiar = false;
    string confirmar;
    Factory* factroy = Factory::getInstance();
    IUsuarios* interface = factroy->getIUsuarios();

    while (!cambiar) {
        cout << "Ingrese el nombre de la inmobiliaria: ";
        getline(cin,nombre);
        cout << endl;
        cout << "Ingrese el mail de la inmobiliaria:";
        getline(cin,mail);
        cout << endl;
        cout << "Ingrese la direccion de la inmobiliaria:";
        getline(cin,direccion);
        cout << endl;
        cout << "Estos son los datos ingresados:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Mail: " << mail << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Desea confirmar la inmobiliaria? [S/N]: ";
        getline(cin, confirmar);
        cout << endl;
        cambiar = (confirmar == "s" || confirmar == "S");
    }
    try {
        interface->IngresarInmobiliaria(nombre, mail, direccion);
        cout << "Inmobiliaria dada de alta con exito!" << endl;
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    delete interface;
}


void doAltaInteresado(){
    string nombre;
    string apellido;
    string edadStr;
    int edad;
    string email;
    bool cambiar = false;
    string confirmar;
    Factory* factroy = Factory::getInstance();
    IUsuarios* interface = factroy->getIUsuarios();
    while (!cambiar){
        cout << "Ingrese el nombre del interesado: ";
        getline(cin, nombre);
        cout << endl;
        cout << "Ingrese el apellido: ";
        getline(cin, apellido);
        cout << endl;
        cout << "Ingrese la edad: ";
        getline(cin, edadStr);
        edad = stoi(edadStr);
        cout << endl;
        cout << "Ingrese el email: ";
        getline(cin, email);
        cout << endl;
        cout << "Estos son los datos ingresados:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Edad: " << edad << endl;
        cout << "Mail: " << email << endl;
        cout << "Desea confirmar el interesado? [S/N] ";
        getline(cin, confirmar);
        cout << endl;
        cambiar = (confirmar == "s" || confirmar == "S");
    }
    try{
        interface->DarAltaInteresado(nombre,apellido,email,edad);
        cout << "Interesado dado de alta con exito!" << endl;
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }

    delete interface;
}

void doAltaEdificio(){ //todo: No tiene interface asignada
    Factory* factroy = Factory::getInstance();
    string name, pisosStr, gastosStr;
    int pisos;
    float gastosComunes;
    IPropiedades* interface = factroy->getIPropiedades();
    cout << "Ingrese los datos del nuevo edificio" << endl;
    cout << "Nombre: ";
    getline(cin, name);
    cout << "Pisos:";
    getline(cin,pisosStr);
    pisos = stoi(pisosStr);
    cout << "Gastos Comunes: ";
    getline(cin,gastosStr);
    gastosComunes = stof(gastosStr);
    DataEdificio edi(name,pisos,gastosComunes);
    try{
        interface->IngresarEdificio(edi);
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    delete interface;
}
void doAltaPropiedad(){
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();
    string id, codZona, codProp, edificioSeleccionado;
    string ambientesStr, dormitoriosStr, baniosStr;
    int ambientes, dormitorios, banios;
    string garageStr;
    bool garage = false;
    string letra, dir;
    string m2EdifStr, m2TotStr, m2VerStr;
    float m2Edif, m2Tot, m2Ver;
    string precioStr;
    float precio;
    string opcionStr, optionStr;
    int opcion, option;
    //listar los departamentos y seleccionar
    list <DataDepartamento> deptos;
    try {
        deptos = interface->ListarDepartamentos();
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    cout << "Departamentos:" << endl;
    for(list<DataDepartamento>::iterator it = deptos.begin(); it != deptos.end(); it++){
        cout << "ID : " << it->getId() << endl;
    }
    cout << "Ingrese el ID del departamento seleccionado :";
    getline(cin, id);
    cout << endl;
    try {
        interface->SeleccionarDepartamento(id);
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    //mostrar las zonas de ese depto
    list<DataZona> zonas;
    try {
        zonas = interface->ListarZonas();
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    cout << "Zonas :" << endl;
    for(list<DataZona>::iterator it = zonas.begin(); it != zonas.end(); it++){
        cout << "Codigo : " << it->getCodigo() << endl;
    }
    cout << "Ingrese el codigo de la zona seleccionada :";
    getline(cin, codZona);
    cout << endl;
    try {
        interface->SeleccionarZona(codZona);
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    //preguntar si es apartamento o casa y leer
    cout << "Si desea ingresar un Apartamento ingrese '1' o si desea ingresar una Casa ingrese '2': ";
    getline(cin, opcionStr);
    opcion = stoi(opcionStr);
    switch(opcion){
        case 1: {
            // si es apartamento listar los edificios en esa zona y dar opcion a hacer alta de edificio
            list <DataEdificio> edificiosZona;
            bool noedif = false;
            try {
                edificiosZona = interface->VerEdificiosZona();
            } catch (invalid_argument e) {
                cout << e.what() << endl;
                noedif = true;
            }
            if (!noedif) {
                cout << "Edificios de la zona" << endl;
                for (list<DataEdificio>::iterator it = edificiosZona.begin(); it != edificiosZona.end(); it++) {
                    cout << "Edificio: " << it->getNombre() << endl;
                }
            }
            noedif = false;
            list<DataEdificio> ediSinAsignar;
            try {
                ediSinAsignar = interface->edificiosSinAsignar();
            }catch(invalid_argument e){
                cout << e.what() << endl;
                noedif = true;
            }
            if(!noedif){
                cout << "Edificios sin asignar" << endl;
                for (list<DataEdificio>::iterator it2 = ediSinAsignar.begin(); it2 != ediSinAsignar.end(); it2++){
                    cout << "Edificio: " << it2->getNombre() << endl;
                }
            }

            //si quier ingresar nuevo edificio correr alta edificio. y dejarlo como edificio actual.
            cout << "Si desea ingresar un nuevo edificio al sistema ingrese '1', de lo contrario ingrese 2 : ";
            getline(cin, optionStr);
            option = stoi(optionStr);
            cout << endl;
            if(option == 1){
                doAltaEdificio(); // ver donde poner esta alta. si dejarlo ya en la zona actual y que sea distinto al caso de uso Alta edificio
            }else{
                cout << "Ingrese el edificio seleccionado: ";
                getline(cin, edificioSeleccionado);
                cout << endl;
                try{
                    interface->SeleccionarEdificio(edificioSeleccionado);
                }catch(invalid_argument e){
                    cout << e.what() << endl;
                    delete interface;
                    return;
                }
            }

            //luego pedir los daqtos del apartamento.
            cout << "A continuacion ingrese los datos del apartamento:" << endl;
            cout << "Cantidad de ambientes : ";
            getline(cin, ambientesStr);
            ambientes = stoi(ambientesStr);
            cout << endl;
            cout << "Cantidad de dormitorios : ";
            getline(cin, dormitoriosStr);
            dormitorios = stoi(dormitoriosStr);
            cout << endl;
            cout << "Cantidad de banios : ";
            getline(cin, baniosStr);
            banios = stoi(baniosStr);
            cout << endl;
            cout << "Tiene garage? S/N: ";
            getline(cin, garageStr);
            garage = ((garageStr == "s")||(garageStr == "S"));
            cout << endl;
            cout << "Direccion : ";
            getline(cin, dir);
            cout << endl;
            cout << "M2 edificados : ";
            getline(cin, m2EdifStr);
            m2Edif = stof(m2EdifStr);
            cout << endl;
            cout << "M2 totales : ";
            getline(cin, m2TotStr);
            m2Tot = stof(m2TotStr);
            cout << endl;
            DataApartamento NuevoApto(ambientes,dormitorios,banios,garage,dir,m2Edif,m2Tot);
            try{
                interface->ingresarApartamento(NuevoApto);
            }catch(invalid_argument e){
                cout << e.what() << endl;
                delete interface;
                return;
            }
            break;
        }
        case 2:
        {
            //si queria ingresar una casa.. pedir datos y hacer ingresar casa/..
            cout << "A continuacion ingrese los datos de la casa:" << endl;
            cout << "Cantidad de ambientes : ";
            getline(cin, ambientesStr);
            ambientes = stoi(ambientesStr);
            cout << endl;
            cout << "Cantidad de dormitorios : ";
            getline(cin, dormitoriosStr);
            dormitorios = stoi(dormitoriosStr);
            cout << endl;
            cout << "Cantidad de banios : ";
            getline(cin, baniosStr);
            banios = stoi(baniosStr);
            cout << endl;
            cout << "Tiene garage? S/N: ";
            getline(cin, garageStr);
            garage = ((garageStr == "s")||(garageStr == "S"));
            cout << endl;
            cout << "Direccion : ";
            getline(cin,dir);
            cout << endl;
            cout << "M2 edificados : ";
            getline(cin, m2EdifStr);
            m2Edif = stof(m2EdifStr);
            cout << endl;
            cout << "M2 totales : ";
            getline(cin, m2TotStr);
            m2Tot = stof(m2TotStr);
            cout << endl;
            cout << "M2 verdes : ";
            getline(cin, m2VerStr);
            m2Ver = stof(m2VerStr);
            cout << endl;
            DataCasa NuevaCasa(ambientes,dormitorios,banios,garage,dir,m2Edif,m2Tot,m2Ver);
            try{
                interface->ingresarCasa(NuevaCasa);
            }catch(invalid_argument e){
                cout << e.what() << endl;
                delete interface;
                return;
            }
            break;
        }
        default:
            // nada...
            break;
    }
    cout << "Si desea Alquilar la propiedad ingrese '1', de lo contrario ingrese '2': ";
    getline(cin, opcionStr);
    opcion = stoi(opcionStr);
    if(opcion == 1){
        cout << "Ingrese el precio de alquiler : ";
        getline(cin, precioStr);
        precio = stof(precioStr);
        try{
            interface->ponerEnAlquiler(precio);
            cout << "Puesta en alquiler exitosa!" << endl;
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
    }
    cout << "Si desea Vender la propiedad ingrese '1', de lo contrario ingrese '2': ";
    getline(cin, opcionStr);
    opcion = stoi(opcionStr);
    if(opcion == 1){
        cout << "Ingrese el precio de Venta : ";
        getline(cin, precioStr);
        precio = stof(precioStr);
        try{
            interface->ponerEnVenta(precio);
            cout << "Puesta en venta exitosa!" << endl;
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
    }

    //pedimos el codigo de la propiedad y lo mostramos.
    try{
        codProp = interface->getCodigPropiedad();
        cout << "Alta Propiedad realizada con exito " << endl;
        cout << "Codigo de la nueva propiedad: " << codProp << endl;
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }

    delete interface;
}
void doConsultarPropiedad(){
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();
    string id, codZona, codProp;
    list<DataPropiedad> l;
    //listar los departamentos y seleccionar

    list <DataDepartamento> deptos;
    try {
        deptos = interface->ListarDepartamentos();
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    cout << "Departamentos:" << endl;
    for(list<DataDepartamento>::iterator it = deptos.begin(); it != deptos.end(); it++){
        cout << it->getId() << " : " << it->getNombre() << endl;
    }
    cout << "Ingrese el ID del departamento seleccionado :";
    getline(cin, id);
    cout << endl;
    try {
        interface->SeleccionarDepartamento(id);
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    //mostrar las zonas de ese depto
    list<DataZona> zonas;
    try {
        zonas = interface->ListarZonas();
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    cout << "Zonas :" << endl;
    for(list<DataZona>::iterator it = zonas.begin(); it != zonas.end(); it++){
        cout << "Codigo : " << it->getCodigo() << endl;
    }
    cout << "Ingrese el codigo de la zona seleccionada :";
    getline(cin, codZona);
    cout << endl;
    try {
        interface->SeleccionarZona(codZona);
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    cout << "Propiedades en la zona seleccionada: " << endl;
    try{
        l = interface->ListarPropiedades();
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    for(list<DataPropiedad>::iterator iterador = l.begin(); iterador != l.end(); iterador++){
        cout << "Codigo: " << iterador->getCodigo() << " Direccion: " << iterador->getDireccion() << endl;
    }
    cout << "Ingrese la propiedad que desea consultar: ";
    getline(cin,codProp);
    cout << endl;
    list<DataPropiedad>::iterator i = l.begin();
    while((i != l.end())&&(i->getCodigo() != codProp)){
        i++;
    }
    if(i == l.end()){
        cout << "La propiedad seleccionada no se encuentra en la lista de propiedades de la zona" << endl;
    }else{
        cout << "Datos de la propiedad consultada" << endl;
        cout << "Codigo: " << i->getCodigo() << endl;
        cout << "Ambientes: " << i->getAmbientes() << endl;
        cout << "Dormitorios: " << i->getDormitorios() << endl;
        cout << "Direccion: " << i->getDireccion() << endl;
        cout << "M2 edificados: " << i->getMetrosCuadradosEdificados() << endl;
        cout << "M2 totales: " << i->getMetrosCuadradosTotales() << endl;
        if((i->getMetrosCuadradosTotales()-i->getMetrosCuadradosEdificados())!= 0){
            cout << "M2 verdes: " << i->getMetrosCuadradosTotales()-i->getMetrosCuadradosEdificados() << endl;
        }
    }
    delete interface;
}
void doModificarPropiedad(){
    string code;
    bool CasaOapto = false; // true si es casa, false si es apto
    string ambientesStr, dormitoriosStr, baniosStr, garageStr;
    int ambientes, dormitorios, banios;
    bool garage = false;
    string letra, dir;
    string m2EdifStr, m2TotStr, m2VerStr;
    float m2Edif, m2Tot, m2Ver;
    DataPropiedad* p;
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();
    //ingresar el codigo de la propiedad a modificar
    cout << "Ingrese el codigo de la propiedad que desea modificar: ";
    getline(cin, code);
    cout << endl;
    //mostrar los datos actuales
    try {
        p = interface->verPropiedad(code);
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }
    cout << "Datos actuales de la propiedad" << endl;
    cout << "Codigo        : " << p->getCodigo() << endl;
    cout << "Ambientes     : " << p->getAmbientes() << endl;
    cout << "Dormitorios   : " << p->getDormitorios() << endl;
    cout << "Banios        : " << p->getBanios() << endl;
    cout << "Garage        : " << (p->getGarage()?"Si":"No") << endl;
    cout << "Direccion     : " << p->getDireccion() << endl;
    cout << "M2 Edificados : " << p->getMetrosCuadradosEdificados() << endl;
    cout << "M2 Totales    : " << p->getMetrosCuadradosTotales() << endl;
    if(DataCasa* c = dynamic_cast<DataCasa*>(p)){
        CasaOapto = true;
        cout << "M2 Verdes     : " << c->getM2Verdes() << endl;
    }
    cout << "A continuacion ingrese los datos de la propiedad nuevamente" << endl;
    cout << "Cantidad de ambientes : ";
    getline(cin, ambientesStr);
    ambientes = stoi(ambientesStr);
    cout << endl;
    cout << "Cantidad de dormitorios : ";
    getline(cin, dormitoriosStr);
    dormitorios = stoi(dormitoriosStr);
    cout << endl;
    cout << "Cantidad de banios : ";
    getline(cin, baniosStr);
    banios = stoi(baniosStr);
    cout << endl;
    cout << "Tiene garage? S/N: ";
    getline(cin, garageStr);
    garage = garageStr == "S" || garageStr == "s";
    cout << endl;
    cout << "Direccion : ";
    getline(cin, dir);
    cout << endl;
    cout << "M2 edificados : ";
    getline(cin, m2EdifStr);
    m2Edif = stof(m2EdifStr);
    cout << endl;
    cout << "M2 totales : ";
    getline(cin, m2TotStr);
    m2Tot = stof(m2TotStr);
    cout << endl;
    if(CasaOapto){
        cout << "M2 verdes : ";
        getline(cin, m2VerStr);
        m2Ver = stof(m2VerStr);
        cout << endl;
    }
    if(CasaOapto){
        DataCasa actualizada(ambientes,dormitorios,banios,garage,dir,m2Edif,m2Tot,m2Ver);
        try{
            interface->actualizarPropiedad(actualizada);
            cout << "Casa actualizada con exito!!!" << endl;
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
    }else{
        DataApartamento updated(ambientes,dormitorios,banios,garage,dir,m2Edif,m2Tot);
        try{
            interface->actualizarPropiedad(updated);
            cout << "Apartamento actualizado con exito!!!" << endl;
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
    }
    delete p;
    delete interface;
}
void doEliminarPropiedad(){
    string code;
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();
    cout << "Ingrese el codigo de la propiedad que desea eliminar: ";
    getline(cin, code);
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
    Sesion* sesion = Sesion::getInstance();

    if(sesion->esTipo("interesado")){
        string idDepartamento, idZona, idPropiedad;
        list <DataDepartamento> deptos;
        try {
            deptos = interface->ListarDepartamentos();
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
        cout << "Departamentos:" << endl;
        for(list<DataDepartamento>::iterator it = deptos.begin(); it != deptos.end(); it++){
            cout << "ID : " << it->getId() << endl;
        }
        cout << "Ingrese el ID del departamento a seleccionar :";
        getline(cin, idDepartamento);
        cout << endl;
        try {
            interface->SeleccionarDepartamento(idDepartamento);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            return;
        }
        //mostrar las zonas de ese depto
        list<DataZona> zonas;
        try {
            zonas = interface->ListarZonas();
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
        cout << "Zonas :" << endl;
        for(list<DataZona>::iterator it = zonas.begin(); it != zonas.end(); it++){
            cout << "Codigo : " << it->getCodigo() << endl;
        }
        cout << "Ingrese el codigo de la zona a seleccionar :";
        getline(cin, idZona);
        cout << endl;
        try {
            interface->SeleccionarZona(idZona);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            return;
        }
        //mostrar las propiedades de esa zona
        list<DataPropiedad> propiedades;
        try {
            propiedades = interface->ListarPropiedades();
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
        cout << "Propiedades :" << endl;
        for(list<DataPropiedad>::iterator it = propiedades.begin(); it != propiedades.end(); it++){
            cout << "Codigo : " << it->getCodigo() << endl;
            cout << "Direccion : " << it->getDireccion() << endl;
            cout << "Cantidad mensajes : " << it->getCantidadMensajes() << endl;
            cout << "----------------------------------------" << endl;
        }
        cout << "Ingrese el codigo de la propiedad a seleccionar :";
        getline(cin, idPropiedad);
        cout << endl;
        try {
            interface->SeleccionarPropiedad(idPropiedad);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            return;
        }
        //todo: liberar memoria de las datapropiedades
    }else if(sesion->esTipo("inmobiliaria")){
        string idInteresado;
        list<DataConversacion> conversaciones;
        try {
            conversaciones = interface->ListarConversaciones();
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
        cout << "Conversaciones :" << endl;
        for(list<DataConversacion>::iterator it = conversaciones.begin(); it != conversaciones.end(); it++){
            cout << "Codigo de interesado : " << it->getInteresado() << endl;
            cout << "Cantidad mensajes : " << it->getCantidadMensajes() << endl;
            cout << "----------------------------------------" << endl;
        }
        cout << "Ingrese el codigo de la propiedad a seleccionar :";
        getline(cin, idInteresado);
        cout << endl;
        try {
            interface->SeleccionarPropiedad(idInteresado);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            return;
        }
    }
    string enviarMensaje, mensaje;
    interface->ListarMensajes();
    cout << "Deseas enviar un mensaje en esta conversacion?(si/no) :";
    getline(cin, enviarMensaje);
    if(enviarMensaje == "si"){
        cout << "Ingrese el mensaje que desea enviar:";
        getline(cin, mensaje);
        interface->AgregarMensaje(mensaje);
    }


    delete interface;
}
void doObtenerReporteInmobiliarias(){
    Factory* factroy = Factory::getInstance();
    IUsuarios* interface = factroy->getIUsuarios();

    delete interface;
}
void doCerrarSesion(){
    string confirmar;
    Factory* factroy = Factory::getInstance();
    ILog* interface = factroy->getILog();
    cout << "Seguro que desea cerrar sesion? [S/N]: ";
    getline(cin, confirmar);
    if (confirmar == "S" || confirmar == "s") {
        interface->CerrarSesion();
    };
    delete interface;
}