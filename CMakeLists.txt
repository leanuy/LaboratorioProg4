cmake_minimum_required(VERSION 3.3)
project(lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        controllers/ConversacionesController.cpp
        controllers/ConversacionesController.h
        controllers/LogController.cpp
        controllers/LogController.h
        controllers/PropiedadesController.cpp
        controllers/PropiedadesController.h
        controllers/UsuariosController.cpp
        controllers/UsuariosController.h
        datatypes/DataApartamento.cpp
        datatypes/DataApartamento.h
        datatypes/DataCasa.cpp
        datatypes/DataCasa.h
        datatypes/DataConversacion.cpp
        datatypes/DataConversacion.h
        datatypes/DataDepartamento.cpp
        datatypes/DataDepartamento.h
        datatypes/DataEdificio.cpp
        datatypes/DataEdificio.h
        datatypes/DataInmobiliaria.cpp
        datatypes/DataInmobiliaria.h
        datatypes/DataMensaje.cpp
        datatypes/DataMensaje.h
        datatypes/DataPropiedad.cpp
        datatypes/DataPropiedad.h
        datatypes/DataZona.cpp
        datatypes/DataZona.h
        interfaces/IConversaciones.cpp
        interfaces/IConversaciones.h
        interfaces/ILog.cpp
        interfaces/ILog.h
        interfaces/IPropiedades.cpp
        interfaces/IPropiedades.h
        interfaces/IUsuarios.cpp
        interfaces/IUsuarios.h
        model/Admin.cpp
        model/Admin.h
        model/Alquiler.cpp
        model/Alquiler.h
        model/Apartamento.cpp
        model/Apartamento.h
        model/Casa.cpp
        model/Casa.h
        model/Conversacion.cpp
        model/Conversacion.h
        model/Departamento.cpp
        model/Departamento.h
        model/Edificio.cpp
        model/Edificio.h
        model/Inmobiliaria.cpp
        model/Inmobiliaria.h
        model/Interesado.cpp
        model/Interesado.h
        model/Mensaje.cpp
        model/Mensaje.h
        model/Propiedad.cpp
        model/Propiedad.h
        model/Usuario.cpp
        model/Usuario.h
        model/Venta.cpp
        model/Venta.h
        model/Zona.cpp
        model/Zona.h
        Factory.cpp
        Factory.h
        Database.cpp
        Database.h
        Sesion.cpp
        Sesion.h
        datatypes/DataUsuario.cpp datatypes/DataUsuario.h datatypes/DataInteresado.cpp datatypes/DataInteresado.h datatypes/DataReporteInmobiliaria.cpp datatypes/DataReporteInmobiliaria.h datatypes/DataPropPorZona.cpp datatypes/DataPropPorZona.h datatypes/DataPropPorDepro.cpp datatypes/DataPropPorDepro.h interfaces/ISesion.cpp interfaces/ISesion.h)
add_executable(Lab6 ${SOURCE_FILES})