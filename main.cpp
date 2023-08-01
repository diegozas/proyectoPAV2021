
#include "DtAsignatura.h"
#include "DtInstanciaClase.h"
#include "DtAsistir.h"
#include "DtParticipacion.h"
#include "DtUsuario.h"
#include "DtInfoClase.h"
#include "DtInfoMonitoreo.h"
#include "DtInfoTeorico.h"

#include "Fabrica.h"

#include "ICAltaAsignatura.h"

#include "ICAsisteEnVivo.h"

#include "ICInscripcionAsignatura.h"

#include "ICEnviarMensaje.h"

#include "ICAltaUsuario.h"

#include "ICAsignarAsignaturaDocente.h"

#include "ICInicioClase.h"

#include "ICEliminarAsignatura.h"

#include "ICListadoClase.h"

#include <list>
#include <string>
#include <iostream>
#include <ctime>
using namespace std;

//Variables globales
Fabrica *f = Fabrica::getInstance();
ICAltaAsignatura *ICA = f->getICAltaAsignatura();
ICInscripcionAsignatura *ICI = f->getICInscripcionAsignatura();
ICAsisteEnVivo *ICAA = f->getICAsisteEnVivo();
ICEnviarMensaje *ICE = f->getICEnviarMensaje();
ICAltaUsuario *ICALTA = f->getICAltaUsuario();
ICAsingarAsignaturaDocente *ICAAD = f->getICAsignarAsignaturaDocente();
ICInicioClase *ICIC = f->getICInicioClase();
ICEliminarAsignatura *ICELIMINAR = f->getICEliminarAsignatura();
ICListadoClase *ICLC = f->getICListadoClase();

//Declaración de primitivas
void menuAgregarUsuario();
void menuAltaDeAsignatura();
void menuAsignacionDeDocentesAsignatura();
void menuInscripcionAsignaturas();
void menuInicioDeClase();
void menuAsistenciaClase();
void menuEnviarMensaje();
void menu();

//MENU ALTA USUARIO
void menuAgregarUsuario()
{
    string nombre, email, contrasena, urlImg, doc, inst, op, op2;
    int x;
    DtUsuario dt;
    bool seguir = true;
    system("clear");
    cout << "Alta Usuario" << endl;
    while (seguir){
        cout << "Nombre" << endl;
        getline(cin >> ws, nombre);
        cout << "Email" << endl;
        cin >> email;
        cout << "Password" << endl;
        cin >> contrasena;
        cout << "Imagen url" << endl;
        cin >> urlImg;
        dt = DtUsuario(nombre, email, contrasena, urlImg);
        ICALTA->ingresarDatosPerfil(dt);
        cout << "1-Docente 2-Estudiante" << endl;
        cin >> x;
        switch (x){
        case 1:
            cout << "Instituto donde trabaja" << endl;
            getline(cin >> ws, inst);
            cout << "Quiere dar de alta al Docente [S/N]?" << endl;
            cin >> op;
            if (op == "s" || op == "S"){
                try{
                    ICALTA->ingresarDocente(inst);
                }catch (invalid_argument &e){
                    cout << e.what() << endl;
                    cout << "Presione ENTER para continuar" << endl;
                    system("read X");
                }
            }else if (op == "n" || op == "N"){
                ICALTA->cancelar();
            }
            break;

        case 2:
            cout << "Documento" << endl;
            cin >> doc;
            cout << "Quiere dar de alta al Estudiante [S/N]?" << endl;
            cin >> op;
            if (op == "s" || op == "S"){
                try{
                    ICALTA->ingresarEstudiante(doc);
                }
                catch (invalid_argument &e){
                    cout << e.what() << endl;
                    cout << "Presione ENTER para continuar" << endl;
                    system("read X");
                }
            }
            else if (op == "N" || op == "n"){
                ICALTA->cancelar();
            }
            break;
        }

        system("clear");
        cout << "Quiere agregar otro Usuario [S/N]?" << endl;
        cin >> op2;
        if (op2 == "S" || op2 == "s"){
            seguir = true;
            system("clear");
        }
        else if (op2 == "n" || op2 == "N")
        {
            seguir = false;
        }
    }
}

//MENU ALTA ASIGNATURA
void menuAltaDeAsignatura(){
    DtAsignatura dt, datos;
    DtInstanciaClase dti;
    string codigo, nombre, op;
    bool monitoreo, practico, teorico;
    system("clear");
    cout << "Alta asignatura" << endl;
    cout << "Codigo de la asignatura" << endl;
    cin >> codigo;
    cout << "Nombre de la asignatura" << endl;
    getline(cin >> ws, nombre);
    for (int i = 0; i < 3; i++){
        if (i == 0){
            cout << "Monitoreo [S/N]?" << endl;
            cin >> op;
            if (op == "S" || op == "s"){
                monitoreo = true;
            }
            else{
                monitoreo = false;
            }
        }
        else if (i == 1){
            cout << "Practico [S/N]?" << endl;
            cin >> op;
            if (op == "S" || op == "s"){
                practico = true;
            }
            else{
                practico = false;
            }
        }
        else if (i == 2){
            cout << "Teorico [S/N]?" << endl;
            cin >> op;
            if (op == "S" || op == "s"){
                teorico = true;
            }
            else{
                teorico = false;
            }
        }
    }
    dti = DtInstanciaClase(monitoreo, practico, teorico);
    dt = DtAsignatura(codigo, nombre, dti);
    system("clear");
    cout << "Datos de la asignatura" << endl;
    datos = ICA->ingresar(dt);
    cout << datos << endl;
    cout << "Quiere dar de alta la asignatura [S/N]?" << endl;
    cin >> op;
    if (op == "S" || op == "s"){
        try{
            ICA->altaAsignatura();
        }
        catch (invalid_argument &e){
            cout << e.what() << endl;
            cout << "Presione ENTER para continuar" << endl;
            system("read X");
        }
    }
    else if (op == "N" || op == "n"){
        ICA->cancelar();
    }
}

//MENU ALTA ASIGANCION DOCENTE ASIGNATURA
void menuAsignacionDeDocentesAsignatura(){
    system("clear");
    string s;
    bool seguir = true;
    while (seguir){
        try{
            list<string> asignaturas = ICAAD->listarAsignaturas();
            for (list<string>::iterator it = asignaturas.begin(); it != asignaturas.end(); ++it){
                cout << "Asignatura: " << (*it) << endl;
            }
            string codigo, email, opi;
            TipoRol rol;
            cout << "Ingrese el codigo de asignatura: ";
            cin >> codigo;
            try{
                list<string> docentes = ICAAD->docentesSinLaAsignatura(codigo);
                for (list<string>::iterator it = docentes.begin(); it != docentes.end(); ++it){
                    cout << "Email:" << (*it) << endl;
                }
                cout << "Ingrese el email del docente: ";
                DtInstanciaClase dti = ICAAD->getInstancias();
                cin >> email;
                cout << "Seleccione un rol: " << endl;
                if (dti.getMonitoreo()){
                    cout << "M-Monitoreo" << endl;
                }
                if (dti.getPractico())
                {
                    cout << "P-Practico" << endl;
                }
                if (dti.getTeorico()){
                    cout << "T-Teorico" << endl;
                }
                cin >> opi;
                if (opi == "M" || opi == "m"){
                    rol = MONITOREO;
                }
                if (opi == "P" || opi == "p")
                {
                    rol = PRACTICO;
                }
                if (opi == "T" || opi == "t"){
                    rol = TEORICO;
                }
                ICAAD->selectDocente(rol, email);
                ICAAD->asignarDocente();
                cout << "Presione ENTER para continuar" << endl;
                system("read X");
                system("clear");
                cout << "Quiere continuar asignando [S/N]?" << endl;
                cin >> s;
                if (s == "S" || s == "s"){
                    seguir = true;
                    system("clear");
                }
                else if (s == "n" || s == "N"){
                    seguir = false;
                }
            }
            catch (invalid_argument &e){
                cout << e.what() << endl;
                cout << "Quiere continuar asignando [S/N]?" << endl;
                cin >> s;
                if (s == "S" || s == "s"){
                    seguir = true;
                    system("clear");
                }
                else if (s == "n" || s == "N"){
                    seguir = false;
                }
            }
        }
        catch (invalid_argument &e){
            cout << e.what();
            seguir = false;
        }
    }
}

//MENU INSCRIPCION ASIGNATURA
void menuInscripcionAsignaturas(){
    system("clear");
    list<string> sinInscribir;
    string email, asignatura, op, op2;
    bool seguir = true;
    cout << "Inscripcion a una asignatura" << endl;
    list<string> correos = ICI->getEmailsEstudiantes();
    if (correos.size() != 0){
        for (list<string>::iterator it = correos.begin(); it != correos.end(); ++it){
            cout << "Email: " << (*it) << endl;
        }
        cout << "Email del estudiante que quiere inscribirse a una asignatura" << endl;
        cin >> email;
        while (seguir){
            sinInscribir = ICI->asignaturaNoInscripto(email);
            if (sinInscribir.empty()){
                cout << "Ya esta inscripto a todas las materias" << endl;
                cout << "Presione ENTER para continuar" << endl;
                system("read x");
                seguir = false;
            }
            else{
                cout << "Codigo de las asignaturas que puede inscribirse" << endl;
                for (list<string>::iterator it = sinInscribir.begin(); it != sinInscribir.end(); ++it){
                    cout << "Codigo:" << *it << endl;
                }
                cout << "Seleccione la asignatura que quiere inscribirse" << endl;
                cin >> asignatura;
                ICI->selectAsignatura(asignatura);
                cout << "Quiere Inscribirse a la asignatura de codigo " << asignatura << " [S/N]?" << endl;
                cin >> op;
                if (op == "S" || op == "s"){
                    ICI->inscribir();
                }
                else if (op == "n" || op == "N"){
                    ICI->cancelar();
                }
            }

            if (seguir){
                system("clear");
                cout << "Quiere inscribirse a otra Asignatura [S/N]?" << endl;
                cin >> op2;
                if (op2 == "S" || op2 == "s"){
                    seguir = true;
                    system("clear");
                }else if (op2 == "n" || op2 == "N"){
                    seguir = false;
                }
            }
        }
    }
    else{
        cout << "No hay estudiantes en el sistema.." << endl;
        cout << "Presione enter para salir.." << endl;
        system("read X");
    }
}

//MENU INICIO CLASE
void menuInicioDeClase()
{
    system("clear");
    string email, codigo, nombre, op, op2;
    TimeStamp fechaHora;
    Fecha fecha;
    int dia, mes, anio, hora, minuto, segundo;
    bool seguir = true;
    bool deMonitoreo;
    list<string> asiganturasAsigadas; // lista de codigos asignaturas
    list<string> alumnosInscriptos;   //lista de alumnos inscriptos
    DtIniciarClase dtic;
    DtIniciarClaseFull dticf;
    cout << "INICIAR CLASE" << endl;
    list<string> correos = ICIC->getEmailsDocentes();
    if (correos.size() != 0)
    {
        for (list<string>::iterator it = correos.begin(); it != correos.end(); ++it)
        {
            cout << "Email: " << (*it) << endl;
        }
        cout << "Ingrese email del docente: " << endl;
        cin >> email;
        asiganturasAsigadas = ICIC->asignaturasAsignadas(email);
        if (asiganturasAsigadas.empty())
        {
            cout << "El Docente no tiene asignaturas asignadas" << endl;
        }
        else
        {
            cout << "Asigaturas asignadas para el docente seleccionado" << endl;
            for (list<string>::iterator it = asiganturasAsigadas.begin(); it != asiganturasAsigadas.end(); ++it)
            {
                cout << "Codigo:" << *it << endl;
            }
            cout << "Inserte codigo de asignatura" << endl;
            cin >> codigo;
            cout << "Inserte nombre de la clase" << endl;
            getline(cin >> ws, nombre);
            cout << "fecha inicio " << endl;
            cout << "dia " << endl;
            cin >> dia;
            cout << "mes " << endl;
            cin >> mes;
            cout << "anio " << endl;
            cin >> anio;
            cout << "hora " << endl;
            cin >> hora;
            cout << "minuto " << endl;
            cin >> minuto;
            cout << "segundo " << endl;
            cin >> segundo;
    
            try
            {
                fecha = Fecha(dia, mes, anio);
                fechaHora = TimeStamp(fecha, hora, minuto, segundo);
                try
                {
                    dtic = DtIniciarClase(codigo, nombre, fechaHora);
                    try
                    {
                        deMonitoreo = ICIC->selectAsignatura(dtic);

                        if (deMonitoreo)
                        {
                            alumnosInscriptos = ICIC->inscriptosAsignaturas();
                            list<string> habilitados;
                            int contador = 0;
                            while (seguir)
                            {
                                if (alumnosInscriptos.size() == 0)
                                {
                                    seguir=false;
                                    cout << "No hay mas alumnos para habilitar.." << endl;
                                    cout << "Presione ENTER para continuar" << endl;
                                    system("read x");
                                
                                }else if (contador == 15)
                                {
                                    seguir=false;
                                    cout << "No se pueden habilitar mas alumnos" << endl;
                                    cout << "Presione ENTER para continuar" << endl;
                                    system("read x");
                                }else{
                                    system("clear");
                                    cout << "Clase de monitoreo" << endl;
                                    cout << "Alumnos inscriptos disponibles a habilitar" << endl;
                                    for (list<string>::iterator it = alumnosInscriptos.begin(); it != alumnosInscriptos.end(); ++it)
                                    {
                                    cout << "email: " << (*it) << endl;
                                    }
                                    cout << "Ingrese alumno a habilitar" << endl;
                                    cin >> email;
                                    habilitados.push_back(email);
                                    bool borre = false;
                                    list<string>::iterator it = alumnosInscriptos.begin();
                                    while (it != alumnosInscriptos.end() && !borre)
                                    {
                                        if ((*it) == email)
                                        {
                                            alumnosInscriptos.remove(email);
                                            borre = true;
                                        }
                                        else
                                        {
                                            it++;
                                        }
                                    }
                                    //alumnosAbilitados.push_back(email);
                                    ICIC->habilitar(email);
                                    system("clear");
                                    cout << "Quiere agregar otro alumno [S/N]? " << endl;
                                    cin >> op;
                                    if (op == "S" || op == "s")
                                    {
                                        seguir = true;
                                        contador++;
                                    }
                                    else if (op == "N" || op == "n")
                                    {
                                        seguir = false;
                                    }
                                }
                           
                            }
                            
                               
                            
                        }
                        system("clear");
                        cout << "Datos ingresados: " << endl;
                        DtIniciarClaseFull dticf = ICIC->datosIngresados();
                        cout << dticf;
                        cout << "Confirmar? [S/N]?" << endl;
                        cin >> op;
                        if (op == "s" || op == "S")
                        {
                            ICIC->iniciarClase();
                        }
                        else if (op == "n" || op == "N")
                        {
                            ICIC->cancelar();
                        }
                        cout << "Presione ENTER para continuar" << endl;
                        system("read x");
                    }
                    catch (invalid_argument &e)
                    {
                        cout << e.what() << endl;
                        cout << "Presione ENTER para continuar" << endl;
                        system("read x");
                    }
                }
                catch (invalid_argument &e)
                {
                    cout << e.what();
                    cout << "Presione ENTER para continuar" << endl;
                    system("read x");
                }
            }
            catch (invalid_argument &e)
            {
                cout << e.what();
                cout << "Presione ENTER para continuar" << endl;
                system("read x");
            }
        }
    }
    else
    {
        cout << "No hay docentes en el sistema.." << endl;
        cout << "Presione enter para salir.." << endl;
        system("read X");
    }
}

//MENU ASISTENCIA CLASE
void menuAsistenciaClase(){
    system("clear");
    list<string> asignado;
    list<int> clasesOnline;
    string codigo, email, op, op2;
    DtAsistir dta;
    int x;
    cout << "Asistencia a una clase en vivo" << endl;
    list<string> correos = ICAA->getEmailsEstudiantes();
    if (correos.size() != 0)
    {
        for (list<string>::iterator it = correos.begin(); it != correos.end(); ++it)
        {
            cout << "Email: " << (*it) << endl;
        }
        cout << "Email del Estudiante que quiere asisistir" << endl;
        cin >> email;
        asignado = ICAA->asignaturasInscripto(email);
        if (asignado.empty())
        {
            cout << "No esta inscripto a ninguna materia" << endl;
            cout << "Presione ENTER para continuar" << endl;
            system("read x");
        }
        else
        {
            cout << "Asignaturas a la que esta inscripto" << endl;
            for (list<string>::iterator it = asignado.begin(); it != asignado.end(); ++it)
            {
                cout << "Codigo:" << *it << endl;
            }
            cout << "Seleccione una Asignatura" << endl;
            cin >> codigo;
            clasesOnline = ICAA->clasesOnlineDisplonibles(codigo);
            if (clasesOnline.empty())
            {
                cout << "No hay clases iniciada para esa asignatura" << endl;
                cout << "Presione ENTER para continuar" << endl;
                system("read x");
            }
            else
            {
                cout << "Clases Online disponibles" << endl;
                for (list<int>::iterator it = clasesOnline.begin(); it != clasesOnline.end(); ++it)
                {
                    cout << "ID:" << *it << endl;
                }
                cout << "Seleccione la clase que quiere asistir" << endl;
                cin >> x;
                dta = ICAA->selectClase(x);
                system("clear");
                cout << "Datos a la clase que quiere asistir" << endl;
                cout << dta;
                cout << "Quiere asistir a esa clase [S/N]?" << endl;
                cin >> op;
                if (op == "S" || op == "s")
                {
                    ICAA->asistirClaseVivo();
                }
                else if (op == "n" || op == "N")
                {
                    ICAA->cancelar();
                    cout << "No asistio a la clase" << endl;
                    cout << "Presione ENTER para continuar" << endl;
                    system("read x");
                }
            }
        }
    }
    else
    {
        cout << "No hay estudiantes en el sistema.." << endl;
        cout << "Presione ENTER para continuar" << endl;
        system("read x");
    }
}

//Menu Enviar Mensaje
void menuEnviarMensaje()
{
    system("clear");
    list<int> clasesOnlineAsistiendo;
    list<DtParticipacion *> mensajes;
    DtParticipacion *dtresponde;
    int clase;
    string texto, email, op, op2;
    cout << "Enviar Mensaje" << endl;
    list<string> correos = ICE->getEmails();
    if (correos.size() != 0)
    {
        cout << "Email del Usuario que quiere mandar un mensaje" << endl;
        for (list<string>::iterator it = correos.begin(); it != correos.end(); ++it)
        {
            cout << "Email: " << (*it) << endl;
        }
        cin >> email;
        clasesOnlineAsistiendo = ICE->clasesOnlineAsistiendo(email);
        if (clasesOnlineAsistiendo.empty())
        {
            cout << "No esta Asistiendo a ninguna clase" << endl;
            cout << "Presione ENTER para continuar" << endl;
            system("read X");
        }
        else
        {
            cout << "Clases en las que participa" << endl;
            for (list<int>::iterator it = clasesOnlineAsistiendo.begin(); it != clasesOnlineAsistiendo.end(); ++it)
            {
                cout << "Codigo:" << *it << endl;
            }
            cout << "Seleccione una clase" << endl;
            cin >> clase;
            mensajes = ICE->selectClase(clase);
            if (mensajes.empty())
            {
                cout << "No hay Mensajes en esta clase" << endl;
                cout << "Ingrese el mensaje" << endl;
                getline(cin >> ws, texto);
                ICE->ingresarTexto(texto);
                ICE->enviar();
            }
            else
            {
                system("clear");
                cout << "Mensajes de la Clase" << endl;

                for (list<DtParticipacion *>::iterator it = mensajes.begin(); it != mensajes.end(); ++it)
                {
                    cout << (*it);
                    if ((*it)->tieneRespuesta())
                    {
                        cout << "\tRespuesta del Mensaje" << endl;
                        dtresponde = (*it)->getRespuesta();
                        cout <<"\t"<< dtresponde << endl;
                    }
                }
                cout << endl;
                cout << "Quiere responder a un mensaje [S/N]?" << endl;
                cin >> op;
                if (op == "S" || op == "s")
                {
                    cout << "Seleccione un mensaje" << endl;
                    cin >> clase;
                    ICE->responder(clase);
                    cout << "Ingrese el texto" << endl;
                    getline(cin >> ws, texto);
                    ICE->ingresarTexto(texto);
                    cout << "Quiere Enviar el mensaje [S/N]?" << endl;
                    cin >> op2;
                    if (op2 == "S" || op2 == "s")
                    {
                        ICE->enviar();
                    }
                    else if (op2 == "N" || op2 == "n")
                    {
                        ICE->cancelar();
                    }
                }
                else if (op == "N" || op == "n")
                {
                    cout << "Ingrese el texto" << endl;
                    getline(cin >> ws, texto);
                    ICE->ingresarTexto(texto);
                    ICE->enviar();
                }
            }
        }
    }
    else
    {
        cout << "No hay usuarios en el sistema.." << endl;
        cout << "Presione ENTER para continuar" << endl;
        system("read X");
    }
}
void cargarDatos(){
    ICALTA->cargarDatos();//alta Usuario
    ICA->cargarDatos();// alta asignatura
    ICI->cargarDatos();//Inscripcion asignatura
    ICAAD->cargarDatos();//Asignar Asignatura Docente
    ICIC->cargarDatos();//Inicio de clase


    cout<<"Se cargaron correctamente los daots"<<endl;
    cout<<"Presione ENTER para conituar"<<endl;
    system("read x");



}

//Menu Eliminar Asignatura
void menuEliminarAsignatura()
{
    system("clear");
    list<string> asignaturas;
    string codigo;
    cout << "Eliminar Asignatura" << endl;
    asignaturas = ICELIMINAR->listarAsignaturas();
    cout << "Asignaturas del sistema" << endl;
    for (list<string>::iterator it = asignaturas.begin(); it != asignaturas.end(); ++it)
    {
        cout << "Codigo:" << *it << endl;
    }
    cout << "Seleccione una asignatura" << endl;
    cin >> codigo;
    ICELIMINAR->selectAsignatura(codigo);
    string op;
    cout << "Eliminar asignatura? [S/N]" << endl;
    cin >> op;
    if (op == "s" || op == "S")
    {
        ICELIMINAR->eliminarAsignatura();
        cout << "Se borro la asignatura de codigo " << codigo << " correctamente" << endl;
        system("read x");
    }
    else
    {
        cout << "No se elimino la asignatura" << endl;
        cout << "Presione enter para salir.." << endl;
        system("read x");
    }
}

void menuListadoClases()
{
    system("clear");
    string codigo, email;
    list<string> docentesDisponibles = ICLC->getEmailsDocentes();
    list<string> docentes;
    list<string> estudiantes;
    cout << "LISTADO DE CLASES" << endl;
    if (docentesDisponibles.size() != 0)
    {
        for (list<string>::iterator it = docentesDisponibles.begin(); it != docentesDisponibles.end(); ++it)
        {
            cout << "Email: " << (*it) << endl;
        }
        cout << "Ingrese email del docente:" << endl;
        cin >> email;
        list<string> asignaturas = ICLC->asignaturasAsignadas(email);
        if (asignaturas.empty())
        {
            cout << "El docente no tiene asignaturas.." << endl;
            cout << "Presione enter.." << endl;
            system("read x");
        }
        else
        {
            cout << "ASIGNATURAS DEL DOCENTE" << endl;
            for (list<string>::iterator it = asignaturas.begin(); it != asignaturas.end(); ++it)
            {
                cout << "Codigo: " << (*it) << endl;
            }
            cout << "Seleccione una asignatura:" << endl;
            cin >> codigo;
            list<DtInfoClase *> dtInfos = ICLC->selectAsignatura(codigo);
            if (dtInfos.empty())
            {
                cout << "El docente no ha inciado clases.." << endl;
                cout << "Presione enter para salir .." << endl;
                system("read X");
            }
            else
            {
                system("clear");
                cout << "INFORMACION DE LAS CLASES" << endl;
                for (list<DtInfoClase *>::iterator it = dtInfos.begin(); it != dtInfos.end(); ++it)
                {
                    if (DtInfoMonitoreo *m = dynamic_cast<DtInfoMonitoreo *>(*it))
                    {
                        cout << m << endl;
                        docentes = m->getDocentes();
                        estudiantes = m->getEstudiantes();
                        cout << "TIPO DE CLASE : MONITOREO" << endl;
                        cout << "DOCENTES" << endl;
                        for (list<string>::iterator it = docentes.begin(); it != docentes.end(); ++it)
                        {
                            cout << "Nombre: " << (*it) << endl;
                        }
                        cout << "ESTUDIANTES" << endl;
                        for (list<string>::iterator it = estudiantes.begin(); it != estudiantes.end(); ++it)
                        {
                            cout << "Nombre: " << (*it) << endl;
                        }
                    }
                    else
                    {

                        if (DtInfoTeorico *t = dynamic_cast<DtInfoTeorico *>(*it))
                        {
                            cout << t << endl;
                            docentes = t->getDocentes();
                            cout << "TIPO DE CLASE : TEORICO" << endl;
                            cout << "DOCENTES" << endl;
                            for (list<string>::iterator it = docentes.begin(); it != docentes.end(); ++it)
                            {
                                cout << "Nombre: " << (*it) << endl;
                            }
                            int cant = t->getCantAsistentes();
                            cout << "Cantidad de asistentes> " << cant << endl;
                        }
                        else
                        {
                            cout << (*it) << endl;
                            docentes = (*it)->getDocentes();
                            cout << "TIPO DE CLASE : PRACTICO" << endl;
                            cout << "DOCENTES" << endl;
                            for (list<string>::iterator it = docentes.begin(); it != docentes.end(); ++it)
                            {
                                cout << "Nombre: " << (*it) << endl;
                            }
                        }
                    }
                }
                cout << "Presione enter.." << endl;
                system("read x");
            }
        }
    }
    else
    {
        cout << "No hay docentes en el sistema.." << endl;
        cout << "Presione enter.." << endl;
        system("read x");
    }
}
//MENU
void menu()
{
    system("clear");
    cout << "_____________________________" << endl;
    cout << "____________MENÚ_____________" << endl;
    cout << "1. Alta de usuario" << endl;
    cout << "2. Alta de asignatura" << endl;
    cout << "3. Asignacion de docentes a una asignatura" << endl;
    cout << "4. Inscripcion a las asignaturas " << endl;
    cout << "5. Inicio de clase" << endl;
    cout << "6. Asistencia a clase" << endl;
    cout << "7. Enviar mensaje" << endl;
    cout << "8. Listado de clase" << endl;
    cout << "9. Eliminar asignatura" << endl;
    cout << "10. Cargar datos" << endl;
    cout << "11. Salir" << endl;
    cout << "_____________________________" << endl;
    cout << "OPCION: ";
}

int main()
{
    int opcion;
    menu();
    cin >> opcion;
    while (opcion != 11)
    {
        switch (opcion)
        {
        case 1:
            menuAgregarUsuario();
            break;
        case 2:
            menuAltaDeAsignatura();
            break;
        case 3:
            menuAsignacionDeDocentesAsignatura();
            break;
        case 4:
            menuInscripcionAsignaturas();
            break;
        case 5:
            menuInicioDeClase();
            break;
        case 6:
            menuAsistenciaClase();
            break;
        case 7:
            menuEnviarMensaje();
            break;
        case 8:
            menuListadoClases();
            break;
        case 9:
            menuEliminarAsignatura();
            break;
        case 10:
            cargarDatos();
            break;
        default:
            break;
        }

        menu();
        cin >> opcion;
    }
    return 0;
}
