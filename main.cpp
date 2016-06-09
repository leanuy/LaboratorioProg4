#include <iostream>
#include "Database.h"

#include "interfaces/ILog.h"
#include "Sesion.h"
#include "Factory.h"

using namespace std;

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
    string email;
    bool first;
    string psw1, psw2;
    bool iguales;
    bool incorrecta;
    Factory* factroy = Factory::getInstance();
    ILog* interface = factroy->getILog();
    cout << "Ingrese su Email" << endl;
    cin >> email;
    first = interface->IngresarEmail(email);
    if (first){
        iguales = false;
        cout << "Es la primera vez que ingresa al sistema, se le pedira que ingrese una contrasenia y luego la confirme" << endl;
        while(! iguales) {
            cout << "Ingresar Contrasenia:";
            cin >> psw1;
            cout << endl;
            cout << "Confirmarar Contrasenia:";
            cin >> psw2;
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
            cin >> psw1;
            cout << endl;
            incorrecta = interface->IngresarPassword(psw1);
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
    bool cambiar = true;
    string confirmar;
    Factory* factroy = Factory::getInstance();
    IUsuarios* interface = factroy->getIUsuarios();

    while (cambiar) {
        cout << "Ingrese el nombre de la inmobiliaria:" << endl;
        cin >> nombre;
        cout << "Ingrese el mail de la inmobiliaria:" << endl;
        cin >> mail;
        cout << "Ingrese la direccion de la inmobiliaria:" << endl;
        cin >> direccion;
        cout << "Estos son los datos ingresados:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Mail: " << mail << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Desea confirmar la inmobiliaria? [S/N]: ";
        cin >> confirmar;
        cout << endl;
        cambiar = (confirmar == "s" || confirmar == "S");
    }
    interface->IngresarInmobiliaria(nombre, mail, direccion);

    delete interface;
}


void doAltaInteresado(){
    string nombre;
    string apellido;
    int edad;
    string email;
    bool cambiar = true;
    string confirmar;
    Factory* factroy = Factory::getInstance();
    IUsuarios* interface = factroy->getIUsuarios();
    while (cambiar){
        cout << "Ingrese el nombre del interesado:";
        cin >> nombre;
        cout << "Ingrese el apellido:";
        cin >> apellido;
        cout << "Ingrese la edad:";
        cin >> edad;
        cout << "Ingrese el email:";
        cin >> email;
        cout << "Desea confirmar el interesado? [S/N]";
        cin >> confirmar;
        cout << endl;
        cambiar = (confirmar == "s" || confirmar == "S");
    }
    interface->DarAltaInteresado(nombre,apellido,email,edad);
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
    string id, codZona, codProp, edificioSeleccionado;
    int ambientes, dormitorios, banios;
    bool garage = false;
    string letra, dir;
    float m2Edif, m2Tot, m2Ver;
    float precio;
    int opcion, option;
    //listar los departamentos y seleccionar
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
    cout << "Ingrese el ID del departamento seleccionado :";
    cin >> id;
    cout << endl;
    try {
        interface->SeleccionarDepartamento(id);
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
    cout << "Ingrese el codigo de la zona seleccionada :";
    cin >> codZona;
    cout << endl;
    try {
        interface->SeleccionarZona(codZona);
    }catch(invalid_argument e){
        cout << e.what() << endl;
        return;
    }
    //preguntar si es apartamento o casa y leer
    cout << "Si desea ingresar un Apartamento ingrese '1' o si desea ingresar una Casa ingrese '2': ";
    cin >> opcion;
    switch(opcion){
        case 1:
        {
            //todo si es apartamento listar los edificios en esa zona y dar opcion a hacer alta de edificio

            list<DataEdificio> edificiosZona = interface->VerEdificiosZona();
            cout << "Edificios de la zona" << endl;
            for (list<DataEdificio>::iterator it = edificiosZona.begin(); it != edificiosZona.end(); it++){
                cout << "Edificio: " << it->getNombre() << endl;
            }

            cout << "Edificios sin asignar" << endl;
            list<DataEdificio> ediSinAsignar = interface->edificiosSinAsignar();
            for (list<DataEdificio>::iterator it2 = ediSinAsignar.begin(); it2 != ediSinAsignar.end(); it2++){
                cout << "Edificio: " << it2->getNombre() << endl;
            }

            //si quier ingresar nuevo edificio correr alta edificio. y dejarlo como edificio actual.
            cout << "Si desea ingresar un nuevo edificio al sistema ingrese '1', de lo contrario ingrese 2 : ";
            cin >> option;
            cout << endl;
            if(option == 1){
                doAltaEdificio(); // todo ver donde poner esta alta. si dejarlo ya en la zona actual y que sea distinto al caso de uso Alta edificio
            }else{
                cout << "Ingrese el edificio seleccionado: ";
                cin >> edificioSeleccionado;
                cout << endl;
                try{
                    interface->SeleccionarEdificio(edificioSeleccionado);
                }catch(invalid_argument e){
                    cout << e.what() << endl;
                    return;
                }
            }

            //luego pedir los daqtos del apartamento.
            cout << "A continuacion ingrese los datos del apartamento:" << endl;
            cout << "Cantidad de ambientes : ";
            cin >> ambientes;
            cout << endl;
            cout << "Cantidad de dormitorios : ";
            cin >> dormitorios;
            cout << endl;
            cout << "Cantidad de banios : ";
            cin >> banios;
            cout << endl;
            cout << "Tiene garage? S/N: ";
            cin >> letra;
            garage = ((letra == "s")||(letra == "S"));
            cout << endl;
            cout << "Direccion : ";
            cin >> dir;
            cout << endl;
            cout << "M2 edificados : ";
            cin >> m2Edif;
            cout << endl;
            cout << "M2 totales : ";
            cin >> m2Tot;
            cout << endl;
            DataApartamento NuevoApto(ambientes,dormitorios,banios,garage,dir,m2Edif,m2Tot);
            try{
                interface->ingresarApartamento(NuevoApto);
            }catch(invalid_argument e){
                cout << e.what() << endl;
            }
            break;
        }
        case 2:
        {
            //si queria ingresar una casa.. pedir datos y hacer ingresar casa/..
            cout << "A continuacion ingrese los datos de la casa:" << endl;
            cout << "Cantidad de ambientes : ";
            cin >> ambientes;
            cout << endl;
            cout << "Cantidad de dormitorios : ";
            cin >> dormitorios;
            cout << endl;
            cout << "Cantidad de banios : ";
            cin >> banios;
            cout << endl;
            cout << "Tiene garage? S/N: ";
            cin >> letra;
            cout << endl;
            cout << "Direccion : ";
            cin >> dir;
            cout << endl;
            garage = ((letra == "s")||(letra == "S"));
            cout << "M2 edificados : ";
            cin >> m2Edif;
            cout << endl;
            cout << "M2 totales : ";
            cin >> m2Tot;
            cout << endl;
            cout << "M2 verdes : ";
            cin >> m2Ver;
            cout << endl;
            DataCasa NuevaCasa(ambientes,dormitorios,banios,garage,dir,m2Edif,m2Tot,m2Ver);
            try{
                interface->ingresarCasa(NuevaCasa);
            }catch(invalid_argument e){
                cout << e.what() << endl;
            }
            break;
        }
        default:
            // Hacer algo si ponen mal?????
            break;
    }
    cout << "Si desea Alquilar la propiedad ingrese '1', de lo contrario ingrese '2': ";
    cin >> opcion;
    if(opcion == 1){
        cout << "Ingrese el precio de alquiler : ";
        cin >> precio;
        try{
            interface->ponerEnAlquiler(precio);
            cout << "Puesta en alquiler exitosa!" << endl;
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
    }
    cout << "Si desea Vender la propiedad ingrese '1', de lo contrario ingrese '2': ";
    cin >> opcion;
    if(opcion == 1){
        cout << "Ingrese el precio de Venta : ";
        cin >> precio;
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
    string id, codZona;
    //listar los departamentos y seleccionar
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
    cout << "Ingrese el ID del departamento seleccionado :";
    cin >> id;
    cout << endl;
    try {
        interface->SeleccionarDepartamento(id);
    }catch(invalid_argument e){
        cout << e.what() << endl;
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
    cout << "Ingrese el codigo de la zona seleccionada :";
    cin >> codZona;
    cout << endl;
    try {
        interface->SeleccionarZona(codZona);
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }
    // LEER!>. hasta aca ya se selecciono departamento y zona,, luego.
    // creo que faltaria la funcion listarpropiedades en PropiedadesController y en la interface.
    // ese metodo le prediria listar las propiedades a la zona actual que tiene el controlador. maniana sera otro dia
    //listar las propiedades de esa zona mostrando la lista de codigos y direccion
    //leer el codigo seleccionado.. ir a buscar e imprimier los datos de esa propiedad.
    //fin/
    delete interface;
}
void doModificarPropiedad(){
    string code;
    bool CasaOapto = false; // true si es casa, false si es apto
    int ambientes, dormitorios, banios;
    bool garage = false;
    string letra, dir;
    float m2Edif, m2Tot, m2Ver;
    DataPropiedad* p;
    Factory* factroy = Factory::getInstance();
    IPropiedades* interface = factroy->getIPropiedades();
    //ingresar el codigo de la propiedad a modificar
    cout << "Ingrese el codigo de la propiedad que desea modificar: ";
    cin >> code;
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
    cin >> ambientes;
    cout << endl;
    cout << "Cantidad de dormitorios : ";
    cin >> dormitorios;
    cout << endl;
    cout << "Cantidad de banios : ";
    cin >> banios;
    cout << endl;
    cout << "Tiene garage? S/N: ";
    cin >> letra;
    cout << endl;
    cout << "Direccion : ";
    cin >> dir;
    cout << endl;
    garage = ((letra == "s")||(letra == "S"));
    cout << "M2 edificados : ";
    cin >> m2Edif;
    cout << endl;
    cout << "M2 totales : ";
    cin >> m2Tot;
    cout << endl;
    if(CasaOapto){
        cout << "M2 verdes : ";
        cin >> m2Ver;
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
        list<DataPropiedad*> propiedades;
        try {
            propiedades = interface->ListarPropiedades();
        }catch(invalid_argument e){
            cout << e.what() << endl;
        }
        cout << "Propiedades :" << endl;
        for(list<DataPropiedad*>::iterator it = propiedades.begin(); it != propiedades.end(); it++){
            cout << "Codigo : " << (*it)->getCodigo() << endl;
            cout << "Direccion : " << (*it)->getDireccion() << endl;
            cout << "Cantidad mensajes : " << (*it)->getCantidadMensajes() << endl;
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
    cin >> confirmar;
    if (confirmar == "S" || confirmar == "s") {
        interface->CerrarSesion();
    };
    delete interface;
}