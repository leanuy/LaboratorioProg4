cmake_minimum_required(VERSION 3.3)
project(lab6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp
        interfaces/IConversaciones.cpp
        interfaces/IConversaciones.h
        interfaces/ILog.cpp
        interfaces/ILog.h
        interfaces/IPropiedades.cpp
        interfaces/IPropiedades.h
        interfaces/IUsuarios.cpp
        interfaces/IUsuarios.h
        controllers/ConversacionesController.cpp
        controllers/ConversacionesController.h
        controllers/LogController.cpp
        controllers/LogController.h
        controllers/PropiedadesController.cpp
        controllers/PropiedadesController.h
        controllers/UsuariosController.cpp
        controllers/UsuariosController.h
        model/Alquiler.cpp
        model/Alquiler.h
        model/Apartamento.cpp
        model/Apartamento.h
        model/Casa.cpp
        model/Casa.h
        model/Edificio.cpp
        model/Edificio.h
        model/Departamento.cpp
        model/Departamento.h
        model/Zona.cpp
        model/Zona.h
        model/Propiedad.cpp
        model/Propiedad.h
        model/Venta.cpp
        model/Venta.h
        model/Inmobiliaria.cpp
        model/Inmobiliaria.h
        Factory.cpp
        Factory.h
        )
add_executable(Lab3 ${SOURCE_FILES})