//
// Created by leandro on 31/05/16.
//

#include "UsuariosController.h"
#include "../Database.h"
#include "../model/Interesado.h"

UsuariosController::UsuariosController(){}

void UsuariosController::IngresarInmobiliaria(string nombre, string mail, string direccion){
    Inmobiliaria* Inmob = new Inmobiliaria(nombre, mail, direccion);
    Database* b = Database::getInstance();
    try{
        b->AddUsuario(Inmob);
    }catch(invalid_argument e){
        delete Inmob;
        throw std::invalid_argument("El usuario con ese email ya existe en el sistema");
    }
}

list<DataReporteInmobiliaria> UsuariosController::ReportesInmobiliaria() {
    list <DataReporteInmobiliaria> reporte;
    reporte.clear();
    Database *db = Database::getInstance();
    map<string,Usuario*> users = db->getUsuarios();
    map<string,Usuario*>::iterator i = users.begin();
    if(i == users.end()){
        throw std::invalid_argument("No hay usuarios en el sistema");
    }
    while(i != users.end()) {
        if (i->second->esTipo("Inmobiliaria")) {
            Inmobiliaria* inmob = (Inmobiliaria*)i->second;
            list<DataPropPorDepro> propsPorD;
            propsPorD.clear();
            DataReporteInmobiliaria r(inmob->getNombre(),inmob->getEmail(),inmob->getDireccion());
            map<string, Departamento *> deptos = db->getDepartamentos();
            map<string, Departamento *>::iterator it = deptos.begin();
            if (it == deptos.end()) {
                throw std::invalid_argument("No hay departamentos en el sistema");
            }
            //seguir despues


            while (it != deptos.end()) {
                it->second->devolverReporteInmo(reporte);
                it++;
            }
            r.setPropsPorZona(propsPorD);
            reporte.push_back(r);
        }
        i++;
    }
    return reporte;
}
bool UsuariosController::CheckEmail(string mail){// para ver si ya existe el mail
    Database* db = Database::getInstance();
    map<string,Usuario*> usuarios = db->getUsuarios();
    map<string,Usuario*>::iterator it = usuarios.find(mail);
    if(it != usuarios.end()){
        return true;
    }
    else{
        return false;
    };
}
void UsuariosController::DarAltaInteresado(string nombre, string apellido, string email, int edad){
	Interesado* inter = new Interesado(nombre, apellido, email, edad);
    Database* b = Database::getInstance();
    try{
        b->AddUsuario(inter);
    }catch(invalid_argument e){
        delete inter;
        throw std::invalid_argument("El usuario con ese email ya existe en el sistema");
    }
}

UsuariosController::~UsuariosController(){}