#------------------------------------------------------------------------------

SOURCE=main.cpp controllers/ConversacionesController.cpp controllers/LogController.cpp controllers/PropiedadesController.cpp controllers/UsuariosController.cpp datatypes/DataApartamento.cpp datatypes/DataCasa.cpp datatypes/DataConversacion.cpp datatypes/DataDepartamento.cpp datatypes/DataEdificio.cpp datatypes/DataInmobiliaria.cpp datatypes/DataMensaje.cpp datatypes/DataPropiedad.cpp datatypes/DataZona.cpp interfaces/IConversaciones.cpp interfaces/ILog.cpp interfaces/IPropiedades.cpp interfaces/IUsuarios.cpp model/Admin.cpp model/Alquiler.cpp model/Apartamento.cpp model/Casa.cpp model/Conversacion.cpp model/Departamento.cpp model/Edificio.cpp model/Inmobiliaria.cpp model/Interesado.cpp model/Mensaje.cpp model/Propiedad.cpp model/Usuario.cpp model/Venta.cpp model/Zona.cpp Factory.cpp Database.cpp Sesion.cpp datatypes/DataUsuario.cpp datatypes/DataInteresado.cpp datatypes/DataReporteInmobiliaria.cpp datatypes/DataPropPorZona.cpp datatypes/DataPropPorDepro.cpp interfaces/ISesion.cpp
MYPROGRAM=lab6

CC=g++

#------------------------------------------------------------------------------

all: $(MYPROGRAM)

$(MYPROGRAM): $(SOURCE)

	$(CC) -std=c++11 $(SOURCE) -o $(MYPROGRAM)

clean:

	rm -f $(MYPROGRAM)



