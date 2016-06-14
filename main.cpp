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
            }else if(com == "salir"){
                cout << "El programa se va a cerrar, desea salir? [S/N]: ";
                getline(cin,opcion);
                salir = ((opcion == "S")||(opcion == "s"));
            }else{
                cout << "Comando no reconocido, intente nuevamente" << endl;
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
    else if(command == "salir"){return true;}
    else {return false;}
}


void doIniciarSesion(){
    string email;
    bool first;
    string psw1, psw2;
    bool iguales;
    bool incorrecta;
    int counter = 0;
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
        while(!iguales && (counter < 3)) {
            cout << "Ingresar Contrasenia:";
            getline(cin, psw1);
            cout << endl;
            cout << "Confirmar Contrasenia:";
            getline(cin, psw2);
            cout << endl;
            iguales = interface->SetearPassword(psw1, psw2);
            if (! iguales){
                cout << "Las contrasenias ingresadas no coinciden, vuelva a intentar" << endl;
                counter++;
                cout << "Le quedan " << 3 - counter << " intentos." << endl;
            };
        }
    }
    else{
        incorrecta = true;
        while (incorrecta && (counter < 3)) {
            cout << "Ingresar Contrasenia:";
            getline(cin, psw1);
            cout << endl;
            incorrecta = !interface->IngresarPassword(psw1);
            if (incorrecta) {
                cout << "La contrasenia ingresada es incorrecta, vuelva e intentar" << endl;
                counter++;
                cout << "Le quedan " << 3 - counter << " intentos." << endl;
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
        getline(cin, nombre);
        cout << endl;
        bool existe = true;
        while (existe) {
            cout << "Ingrese el mail de la inmobiliaria:";
            getline(cin, mail);
            cout << endl;
            existe = interface->CheckEmail(mail);
            if (existe){
                cout << "El email ya existe en el sistema" << endl;
            };
        };
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
        if(confirmar == "n" || confirmar == "N"){
            delete interface;
            return;
        }
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
    bool datoNumerico = false;
    int counterStrike = 0;
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
        while(!datoNumerico) {
            cout << "Ingrese la edad: ";
            getline(cin, edadStr);
            try {
                edad = stoi(edadStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counterStrike == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counterStrike++;
            }
        }
        bool existe = true;
        while (existe) {
            cout << "Ingrese el mail:";
            getline(cin, email);
            cout << endl;
            existe = interface->CheckEmail(email);
            if (existe){
                cout << "El email ya existe en el sistema" << endl;
            };
        };
        cout << "Estos son los datos ingresados:" << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
        cout << "Edad: " << edad << endl;
        cout << "Mail: " << email << endl;
        cout << "Desea confirmar el interesado? [S/N] ";
        getline(cin, confirmar);
        cout << endl;
        cambiar = (confirmar == "s" || confirmar == "S");
        if(confirmar == "n" || confirmar == "N"){
            delete interface;
            return;
        }
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

void doAltaEdificio() {
    Factory *factroy = Factory::getInstance();
    string name, pisosStr, gastosStr, confirmar;
    bool cambiar = false;
    bool datoNumerico = false;
    int pisos;
    int counter = 0;
    float gastosComunes;
    IPropiedades *interface = factroy->getIPropiedades();
    cout << "Ingrese los datos del nuevo edificio" << endl;
    while (!cambiar){
        cout << "Nombre: ";
        getline(cin, name);
        while(!datoNumerico) {
            cout << "Pisos:";
            getline(cin, pisosStr);
            try{
                pisos = stoi(pisosStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        }
        datoNumerico = false;
        counter = 0;
        while(!datoNumerico) {
            cout << "Gastos Comunes: ";
            getline(cin, gastosStr);
            try{
                gastosComunes = stof(gastosStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        }
        cout << "Estos son los datos ingresados:" << endl;
        cout << "Nombre: " << name << endl;
        cout << "Pisos: " << pisosStr << endl;
        cout << "Gastos comunes: " << gastosStr << endl;
        cout << "Desea confirmar el interesado? [S/N] ";
        getline(cin, confirmar);
        cout << endl;
        cambiar = (confirmar == "s" || confirmar == "S");
        if (confirmar == "n" || confirmar == "N") {
            delete interface;
            return;
        }
    }
    DataEdificio edi(name,pisos,gastosComunes);
    try{
        interface->IngresarEdificio(edi);
        cout << "Edificio dado de alta con exito" << endl;
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
    bool datoNumerico = false;
    string garageStr;
    bool garage = false;
    string letra, dir;
    string m2EdifStr, m2TotStr, m2VerStr;
    float m2Edif, m2Tot, m2Ver;
    string precioStr;
    float precio;
    string opcionStr, optionStr;
    int opcion, option, counter;
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
        cout << it->getId() << ": " << it->getNombre() << endl;
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

    if(opcionStr == "1"){
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
        //option = stoi(optionStr);
        cout << endl;
        if(optionStr == "1"){
            doAltaEdificio(); // ver donde poner esta alta. si dejarlo ya en la zona actual y que sea distinto al caso de uso Alta edificio
        }
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


        //luego pedir los daqtos del apartamento.
        cout << "A continuacion ingrese los datos del apartamento:" << endl;
        counter = 0;
        while(!datoNumerico) {
            cout << "Cantidad de ambientes : ";
            getline(cin, ambientesStr);
            try {
                ambientes = stoi(ambientesStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        }
        counter = 0;
        datoNumerico = false;
        while(!datoNumerico) {
            cout << "Cantidad de dormitorios : ";
            getline(cin, dormitoriosStr);
            try {
                dormitorios = stoi(dormitoriosStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        }
        counter = 0;
        datoNumerico = false;
        while(!datoNumerico) {
            cout << "Cantidad de banios : ";
            getline(cin, baniosStr);
            try {
                banios = stoi(baniosStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        }
        cout << "Tiene garage? S/N: ";
        getline(cin, garageStr);
        garage = ((garageStr == "s")||(garageStr == "S"));
        cout << endl;
        cout << "Direccion : ";
        getline(cin, dir);
        cout << endl;
        bool coinciden = false;
        while (!coinciden){
            counter = 0;
            datoNumerico = false;
            while(!datoNumerico) {
                cout << "M2 edificados : ";
                getline(cin, m2EdifStr);
                cout << endl;
                try {
                    m2Edif = stof(m2EdifStr);
                    datoNumerico = true;
                }catch(invalid_argument e){
                    cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                    if(counter == 3){
                        cout << "Alta cancelada" << endl;
                        delete interface;
                        return;
                    }
                    counter++;
                }
            }
            counter = 0;
            datoNumerico = false;
            while(!datoNumerico) {
                cout << "M2 totales: ";
                getline(cin, m2TotStr);
                cout << endl;
                try {
                    m2Tot = stof(m2TotStr);
                    datoNumerico = true;
                }catch(invalid_argument e){
                    cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                    if(counter == 3){
                        cout << "Alta cancelada" << endl;
                        delete interface;
                        return;
                    }
                    counter++;
                }
            }
            coinciden = (m2Tot == m2Edif);
            if (!coinciden){
                cout << "Los metros cuadrados totales y edificados no coinciden, vuelva a ingresarlos" << endl;
            };
        }
        DataApartamento NuevoApto(ambientes,dormitorios,banios,garage,dir,m2Edif,m2Tot);
        try{
            interface->ingresarApartamento(NuevoApto);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            delete interface;
            return;
        }
    }
    else if(opcionStr == "2"){
        //si queria ingresar una casa.. pedir datos y hacer ingresar casa/..
        cout << "A continuacion ingrese los datos de la casa:" << endl;
        counter = 0;
        datoNumerico = false;
        while(!datoNumerico) {
            cout << "Cantidad de ambientes : ";
            getline(cin, ambientesStr);
            cout << endl;
            try {
                ambientes = stoi(ambientesStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        };
        counter = 0;
        datoNumerico = false;
        while(!datoNumerico) {
            cout << "Cantidad de dormitorios: ";
            getline(cin, dormitoriosStr);
            cout << endl;
            try {
                dormitorios = stoi(dormitoriosStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        };
        counter = 0;
        datoNumerico = false;
        while(!datoNumerico) {
            cout << "Cantidad de banios: ";
            getline(cin, baniosStr);
            cout << endl;
            try {
                banios = stoi(baniosStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        };

        cout << "Tiene garage? S/N: ";
        getline(cin, garageStr);
        garage = garageStr == "S" || garageStr == "s";
        cout << endl;
        cout << "Direccion : ";
        getline(cin, dir);
        cout << endl;
        bool coinciden = false;
        while (!coinciden) {
            counter = 0;
            datoNumerico = false;
            while(!datoNumerico) {
                cout << "M2 edificados : ";
                getline(cin, m2EdifStr);
                cout << endl;
                try {
                    m2Edif = stof(m2EdifStr);
                    datoNumerico = true;
                }catch(invalid_argument e){
                    cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                    if(counter == 3){
                        cout << "Alta cancelada" << endl;
                        delete interface;
                        return;
                    }
                    counter++;
                }
            };
            counter = 0;
            datoNumerico = false;
            while(!datoNumerico) {
                cout << "M2 totales : ";
                getline(cin, m2TotStr);
                cout << endl;
                try {
                    m2Tot = stof(m2TotStr);
                    datoNumerico = true;
                }catch(invalid_argument e){
                    cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                    if(counter == 3){
                        cout << "Alta cancelada" << endl;
                        delete interface;
                        return;
                    }
                    counter++;
                }
            };
            counter = 0;
            datoNumerico = false;
            while(!datoNumerico) {
                cout << "M2 verdes : ";
                getline(cin, m2VerStr);
                cout << endl;
                try {
                    m2Ver = stof(m2VerStr);
                    datoNumerico = true;
                }catch(invalid_argument e){
                    cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                    if(counter == 3){
                        cout << "Alta cancelada" << endl;
                        delete interface;
                        return;
                    }
                    counter++;
                }
            };
            coinciden = (m2Tot == (m2Edif + m2Ver));
            if (!coinciden){
                cout << "Los metros cuadrados totales, edificados y verdes no son correctos, ingresarlos nuevamente" << endl;
            };
        }
        DataCasa NuevaCasa(ambientes,dormitorios,banios,garage,dir,m2Edif,m2Tot,m2Ver);
        try{
            interface->ingresarCasa(NuevaCasa);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            delete interface;
            return;
        }
    }
    cout << "Si desea Alquilar la propiedad ingrese '1', de lo contrario ingrese '2': ";
    getline(cin, opcionStr);
    opcion = stoi(opcionStr);
    bool algoquenoserepita = false;
    if(opcion == 1){
        while (!algoquenoserepita){
            counter = 0;
            datoNumerico = false;
            while(!datoNumerico) {
                cout << "Ingrese el precio de alquiler : ";
                getline(cin, precioStr);
                cout << endl;
                try {
                    precio = stof(precioStr);
                    datoNumerico = true;
                }catch(invalid_argument e){
                    cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                    if(counter == 3){
                        cout << "Alta cancelada" << endl;
                        delete interface;
                        return;
                    }
                    counter++;
                }
            };
            algoquenoserepita = (precio >= 0);
        };
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
        while (!algoquenoserepita){
            counter = 0;
            datoNumerico = false;
            while(!datoNumerico) {
                cout << "Ingrese el precio de venta: ";
                getline(cin, precioStr);
                cout << endl;
                try {
                    precio = stof(precioStr);
                    datoNumerico = true;
                }catch(invalid_argument e){
                    cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                    if(counter == 3){
                        cout << "Alta cancelada" << endl;
                        delete interface;
                        return;
                    }
                    counter++;
                }
            };
            algoquenoserepita = (precio >= 0);
        };
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

    try{
        l = interface->ListarPropiedades();
    }catch(invalid_argument e){
        cout << e.what() << endl;
        delete interface;
        return;
    }
    list<DataPropiedad>::iterator vacia = l.begin();
    if(vacia == l.end()){
        cout << "No existen propiedades en la zona seleccionada" << endl;
        delete interface;
        return;
    }
    cout << "Propiedades en la zona seleccionada: " << endl;
    for(list<DataPropiedad>::iterator iterador = l.begin(); iterador != l.end(); iterador++){
        cout << "Codigo: " << iterador->getCodigo() << " Direccion: " << iterador->getDireccion();
        cout << " Alquiler: " << (iterador->getAlquiler()?" Si ":" No ");
        cout << " Venta: " << (iterador->getVenta()?" Si ":" No ") << endl;
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
        cout << "Banios: " << i->getBanios() << endl;
        cout << "Tiene Garage: " << (i->getGarage()?"Si":"No") << endl;
        cout << "Direccion: " << i->getDireccion() << endl;
        cout << "M2 edificados: " << i->getMetrosCuadradosEdificados() << endl;
        cout << "M2 totales: " << i->getMetrosCuadradosTotales() << endl;
        if((i->getMetrosCuadradosTotales()-i->getMetrosCuadradosEdificados())!= 0){
            cout << "M2 verdes: " << i->getMetrosCuadradosTotales()-i->getMetrosCuadradosEdificados() << endl;
        }
        cout << "Inmobiliaria: " << endl;
        cout << "Nombre: " << i->getInmobiliaria().getNombre() << endl;
        cout << "E-mail: " << i->getInmobiliaria().getMail() << endl;
        cout << "Direccion: " << i->getInmobiliaria().getDireccion() << endl;
        if(i->getVenta()){
            cout << "Precio de venta: " << i->getVenta() << endl;
        }
        if(i->getAlquiler()){
            cout << "Precio de alquiler: " << i->getAlquiler() << endl;
        }
    }
    delete interface;
}
void doModificarPropiedad(){
    string code;
    bool CasaOapto = false; // true si es casa, false si es apto
    string ambientesStr, dormitoriosStr, baniosStr, garageStr;
    int ambientes, dormitorios, banios, counter;
    bool garage = false;
    bool datoNumerico = false;
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
    float m2edif = p->getMetrosCuadradosEdificados();
    cout << "M2 Edificados : " << m2edif << endl;
    float m2totales = p->getMetrosCuadradosTotales();
    cout << "M2 Totales    : " << m2totales << endl;
    if(p->getMetrosCuadradosEdificados() != p->getMetrosCuadradosTotales()){
        CasaOapto = true;
        float pasto = p->getMetrosCuadradosTotales() - p->getMetrosCuadradosEdificados();
        cout << "M2 Verdes     : " << pasto << endl;
    }
    delete p;
    cout << "A continuacion ingrese los datos de la propiedad nuevamente" << endl;
    counter = 0;
    datoNumerico = false;
    while(!datoNumerico) {
        cout << "Cantidad de ambientes : ";
        getline(cin, ambientesStr);
        cout << endl;
        try {
            ambientes = stoi(ambientesStr);
            datoNumerico = true;
        }catch(invalid_argument e){
            cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
            if(counter == 3){
                cout << "Alta cancelada" << endl;
                delete interface;
                return;
            }
            counter++;
        }
    };
    counter = 0;
    datoNumerico = false;
    while(!datoNumerico) {
        cout << "Cantidad de dormitorios: ";
        getline(cin, dormitoriosStr);
        cout << endl;
        try {
            dormitorios = stoi(dormitoriosStr);
            datoNumerico = true;
        }catch(invalid_argument e){
            cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
            if(counter == 3){
                cout << "Alta cancelada" << endl;
                delete interface;
                return;
            }
            counter++;
        }
    };
    counter = 0;
    datoNumerico = false;
    while(!datoNumerico) {
        cout << "Cantidad de banios: ";
        getline(cin, baniosStr);
        cout << endl;
        try {
            banios = stoi(baniosStr);
            datoNumerico = true;
        }catch(invalid_argument e){
            cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
            if(counter == 3){
                cout << "Alta cancelada" << endl;
                delete interface;
                return;
            }
            counter++;
        }
    };

    cout << "Tiene garage? S/N: ";
    getline(cin, garageStr);
    garage = garageStr == "S" || garageStr == "s";
    cout << endl;
    cout << "Direccion : ";
    getline(cin, dir);
    cout << endl;
    bool coinciden = false;
    while (!coinciden) {
        counter = 0;
        datoNumerico = false;
        while(!datoNumerico) {
            cout << "M2 edificados : ";
            getline(cin, m2EdifStr);
            cout << endl;
            try {
                m2Edif = stof(m2EdifStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        };
        counter = 0;
        datoNumerico = false;
        while(!datoNumerico) {
            cout << "M2 totales : ";
            getline(cin, m2TotStr);
            cout << endl;
            try {
                m2Tot = stof(m2TotStr);
                datoNumerico = true;
            }catch(invalid_argument e){
                cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                if(counter == 3){
                    cout << "Alta cancelada" << endl;
                    delete interface;
                    return;
                }
                counter++;
            }
        };
        if (CasaOapto) {
            counter = 0;
            datoNumerico = false;
            while(!datoNumerico) {
                cout << "M2 verdes : ";
                getline(cin, m2VerStr);
                cout << endl;
                try {
                    m2Ver = stof(m2VerStr);
                    datoNumerico = true;
                }catch(invalid_argument e){
                    cout << "Dato numerico incorrecto, vuelva a intentar" << endl;
                    if(counter == 3){
                        cout << "Alta cancelada" << endl;
                        delete interface;
                        return;
                    }
                    counter++;
                }
            };;
            coinciden = (m2Tot == (m2Edif + m2Ver));
            if (!coinciden){
                cout << "Los metros cuadrados totales, edificados y verdes no son correctos, vuelva a ingresarlos" << endl;
            }
        }else{
            coinciden = (m2Edif == m2Tot);
            if (!coinciden){
                cout << "Los metros cuadrados totales y edificados no coinciden, vuelva a ingresarlos" << endl;
            };
        };
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
        cout << "Propiedad Eliminada con exito!" << endl;
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }
    delete interface;
}
void doEnviarMensaje(){
    Factory* factroy = Factory::getInstance();
    IConversaciones* interface = factroy->getIConversaciones();
    Sesion* sesion = Sesion::getInstance();
    string idInteresado;
    string idInmobiliaria;

    if(sesion->esTipo("interesado")){
        string idDepartamento, idZona, idPropiedad;
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
        getline(cin, idDepartamento);
        cout << endl;
        try {
            interface->SeleccionarDepartamento(idDepartamento);
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
        getline(cin, idZona);
        cout << endl;
        try {
            interface->SeleccionarZona(idZona);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            delete interface;
            return;
        }
        //mostrar las propiedades de esa zona
        list<DataPropiedad> propiedades;
        try {
            propiedades = interface->ListarPropiedades();
        }catch(invalid_argument e){
            cout << e.what() << endl;
            return;
        }
        cout << "Propiedades :" << endl;
        for(list<DataPropiedad>::iterator it = propiedades.begin(); it != propiedades.end(); it++){
            cout << "Codigo : " << it->getCodigo() << endl;
            cout << "Direccion : " << it->getDireccion() << endl;
            cout << "Cantidad mensajes : " << it->getCantidadMensajes() << endl;
            if(it->getCantidadMensajes() > 0){
                cout << "Ultimo mensaje : " << it->getLastUpdateStr() << endl;
            }
            cout << "----------------------------------------" << endl;
        }
        cout << "Ingrese el codigo de la propiedad a seleccionar :";
        getline(cin, idPropiedad);
        cout << endl;
        try {
            idInmobiliaria = interface->SeleccionarPropiedad(idPropiedad);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            return;
        }
        //todo: liberar memoria de las datapropiedades
    }else if(sesion->esTipo("inmobiliaria")){
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
            cout << "Ultimo mensaje : " << it->getLastUpdateStr() << endl;
            cout << "----------------------------------------" << endl;
        }
        cout << "Ingrese el codigo del interesado a seleccionar :";
        getline(cin, idInteresado);
        cout << endl;
        try {
            interface->SeleccionarConversacion(idInteresado);
        }catch(invalid_argument e){
            cout << e.what() << endl;
            delete interface;
            return;
        }
    }
    string enviarMensaje, mensaje;
    list<DataMensaje> mensajes = interface->ListarMensajes();
    for(list<DataMensaje>::iterator it = mensajes.begin(); it != mensajes.end(); it++){
        cout << it->getTOA() << endl;
        if(sesion->esTipo("interesado")&&it->isInteresado()){
            cout << "Yo : " << it->getIdPropiedad() << endl;
        }else if(!sesion->esTipo("interesado")&&it->isInteresado()){
            cout << idInteresado <<" : " << it->getIdPropiedad() << endl;
        }else if(!sesion->esTipo("interesado")&&!it->isInteresado()){
            cout << "Yo : "<< endl;
        }else{
            cout << idInmobiliaria<<" : " << it->getIdPropiedad() << endl;
        }
        cout << it->getTexto() << endl;
        cout << "----------------------------------------" << endl;
    }
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

    try{
        list<DataReporteInmobiliaria> reporte = interface->ReportesInmobiliaria();
        cout << "------------------------" << endl;
        cout << "Reporte por Inmobiliaria" << endl;
        cout << "------------------------" << endl;
        list<DataReporteInmobiliaria>::iterator i = reporte.begin();
        if(i == reporte.end()){
            cout << "No hay reporte de inmobiliarias en el sistema" << endl;
            delete interface;
            return;
        }
        while(i != reporte.end()){
            cout << "---------------------------------------------------------" << endl;
            cout << "Datos de la inmobiliaria: " << endl;
            cout << "                  nombre: " << i->getNombre() << endl;
            cout << "                  E-mail: " << i->getMail() << endl;
            cout << "               Direccion: " << i->getDireccion() << endl;
            cout << "---------------------------------------------------------" << endl;
            list<DataPropPorDepro> listDeptos = i->getPropsPorDepto();
            list<DataPropPorDepro>::iterator it = listDeptos.begin();
            if(it == listDeptos.end()){
                cout << "La inmobiliaria no tiene propiedades" << endl;
            }else {
                while (it != listDeptos.end()){
                    cout << "Departamento: " << it->getIdDepto() << endl;
                    list <DataPropPorZona> listZonas = it->getPorDeptos();
                    list<DataPropPorZona>::iterator iter = listZonas.begin();
                    if (iter == listZonas.end()) {
                        cout << "No hay propiedades de esta inmobiliara en el departamento" << endl;
                    } else {
                        while(iter != listZonas.end()) {
                            cout << "Zona: " << iter->getIdZona() << "| Numero de Casas: ";
                            cout << iter->getCantCasas() << "| Numero de Apartamentos: " << iter->getCantAptos() << endl;
                            iter++;
                        }
                    }
                    it++;
                }
            }
            i++;
        }
        cout << "---------------------------------------------------------" << endl;
    }catch(invalid_argument e){
        cout << e.what() << endl;
    }

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