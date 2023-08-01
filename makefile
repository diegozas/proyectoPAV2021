main: Fabrica.o CListadoClase.o CEliminarAsignatura.o CInicioClase.o Participacion.o CAsignarAsignaturaDocente.o CAltaUsuario.o CEnviarMensaje.o CInscripcionAsignatura.o CAsisteEnVivo.o CAltaAsignatura.o Perfil.o DtUsuario.o DtInstanciaClase.o DtAsignatura.o DtAsistir.o DtClase.o  DtInfoClase.o DtInfoMonitoreo.o DtInfoTeorico.o DtIniciarClase.o DtIniciarClaseFull.o DtIniciarMonitoreo.o DtParticipacion.o DtPerfil.o main.o Estudiante.o Docente.o Asignatura.o Rol.o TimeStamp.o Fecha.o Log.o AsistenteEnDiferido.o AsistenteEnVivo.o ManejadorAsignatura.o ManejadorClase.o ManejadorPerfil.o Clase.o Monitoreo.o Practico.o Teorico.o
	g++ Fabrica.o CListadoClase.o CEliminarAsignatura.o CInicioClase.o Participacion.o CAsignarAsignaturaDocente.o CAltaUsuario.o CEnviarMensaje.o CInscripcionAsignatura.o CAsisteEnVivo.o CAltaAsignatura.o Perfil.o DtUsuario.o DtInstanciaClase.o DtAsignatura.o DtAsistir.o DtClase.o  DtInfoClase.o DtInfoMonitoreo.o DtInfoTeorico.o DtIniciarClase.o DtIniciarClaseFull.o DtIniciarMonitoreo.o DtParticipacion.o DtPerfil.o main.o Estudiante.o Docente.o Asignatura.o Rol.o TimeStamp.o Fecha.o Log.o AsistenteEnDiferido.o AsistenteEnVivo.o ManejadorAsignatura.o ManejadorClase.o ManejadorPerfil.o Clase.o Monitoreo.o Practico.o Teorico.o -g -o programa

CAsignarAsignaturaDocente.o: CAsignarAsignaturaDocente.cpp
	g++ -g -c CAsignarAsignaturaDocente.cpp

CEnviarMensaje.o: CEnviarMensaje.cpp
	g++ -g -c CEnviarMensaje.cpp

CEliminarAsignatura.o: CEliminarAsignatura.cpp	
	g++ -g -c CEliminarAsignatura.cpp
	
Clase.o: Clase.cpp
	g++ -g -c Clase.cpp

Monitoreo.o: Monitoreo.cpp
	g++ -g -c Monitoreo.cpp

Practico.o: Practico.cpp
	g++ -g -c Practico.cpp

Teorico.o: Teorico.cpp
	g++ -g -c Teorico.cpp

ManejadorAsignatura.o: ManejadorAsignatura.cpp
	g++ -g -c ManejadorAsignatura.cpp

ManejadorClase.o: ManejadorClase.cpp
	g++ -g -c ManejadorClase.cpp

ManejadorPerfil.o: ManejadorPerfil.cpp
	g++ -g -c ManejadorPerfil.cpp

CListadoClase.o: CListadoClase.cpp
	g++ -g -c CListadoClase.cpp


AsistenteEnVivo.o: AsistenteEnVivo.cpp
	g++ -g -c AsistenteEnVivo.cpp

AsistenteEnDiferido.o: AsistenteEnDiferido.cpp
	g++ -g -c AsistenteEnDiferido.cpp

Log.o: Log.cpp
	g++ -g -c Log.cpp

Fecha.o: Fecha.cpp
	g++ -g -c Fecha.cpp

TimeStamp.o: TimeStamp.cpp
	g++ -g -c TimeStamp.cpp

Rol.o: Rol.cpp
	g++ -g -c Rol.cpp

Asignatura.o: Asignatura.cpp
	g++ -g -c Asignatura.cpp

Docente.o: Docente.cpp
	g++ -g -c Docente.cpp

Estudiante.o: Estudiante.cpp
	g++ -g -c Estudiante.cpp

main.o: main.cpp
	g++ -g -c main.cpp

DtInstanciaClase.o: DtInstanciaClase.cpp	
	g++ -g -c DtInstanciaClase.cpp

DtAsignatura.o: DtAsignatura.cpp
	g++ -g -c DtAsignatura.cpp

DtAsistir.o: DtAsistir.cpp
	g++ -g -c DtAsistir.cpp

DtClase.o: DtClase.cpp
	g++ -g -c DtClase.cpp


DtInfoClase.o: DtInfoClase.cpp
	g++ -g -c DtInfoClase.cpp

DtInfoMonitoreo.o: DtInfoMonitoreo.cpp	
	g++ -g -c DtInfoMonitoreo.cpp

DtInfoTeorico.o: DtInfoTeorico.cpp
	g++ -g -c DtInfoTeorico.cpp

DtIniciarClase.o: DtIniciarClase.cpp
	g++ -g -c DtIniciarClase.cpp

DtIniciarClaseFull.o: DtIniciarClaseFull.cpp
	g++ -g -c DtIniciarClaseFull.cpp

DtIniciarMonitoreo.o: DtIniciarMonitoreo.cpp
	g++ -g -c DtIniciarMonitoreo.cpp

DtParticipacion.o: DtParticipacion.cpp
	g++ -g -c DtParticipacion.cpp

DtPerfil.o: DtPerfil.cpp
	g++ -g -c DtPerfil.cpp


Perfil.o: Perfil.cpp
	g++ -g -c Perfil.cpp

CAltaAsignatura.o: CAltaAsignatura.cpp
	g++ -g -c CAltaAsignatura.cpp

CAsisteEnVivo.o: CAsisteEnVivo.cpp
	g++ -g -c CAsisteEnVivo.cpp

CInscripcionAsignatura.o: CInscripcionAsignatura.cpp
	g++ -g -c CInscripcionAsignatura.cpp

Fabrica.o: Fabrica.cpp
	g++ -g -c Fabrica.cpp

Participacion.o: Participacion.cpp
	g++ -g -c Participacion.cpp

DtUsuario.o: DtUsuario.cpp
	g++ -g -c DtUsuario.cpp

CAltaUsuario.o: CAltaUsuario.cpp
	g++ -g -c CAltaUsuario.cpp

CInicioClase.o: CInicioClase.cpp
	g++ -g -c CInicioClase.cpp

clean:
	rm -rf *.o programa
	clear













