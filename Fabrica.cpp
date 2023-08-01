//Fabrica.cpp
//Definicion de operaciones de la clase Fabrica
#include "Fabrica.h"

//#include "../controladores/CPerfil.h"

//constructor
Fabrica::Fabrica(){}

//Destructor
Fabrica::~Fabrica(){}

//Instancia de clase
Fabrica* Fabrica::instance = NULL;

//Instancia de clase
Fabrica* Fabrica::getInstance(){
    if (instance == NULL)
        instance = new Fabrica();
    return instance;
}

/*
//funciones
//obtener el controladores
IPerfil* Fabrica::getIPerfil(){
    return new CPerfil();
}
*/

ICAltaAsignatura* Fabrica::getICAltaAsignatura(){
    return new CAltaAsignatura();
}

ICAsisteEnVivo* Fabrica::getICAsisteEnVivo(){
    return new CAsisteEnVivo();
}

ICInscripcionAsignatura* Fabrica::getICInscripcionAsignatura(){
    return new CInscripcionAsignatura();
}


ICEnviarMensaje* Fabrica::getICEnviarMensaje(){
    return new CEnviarMensaje();
}


ICAltaUsuario* Fabrica::getICAltaUsuario(){
    return new CAltaUsuario();
}


ICAsingarAsignaturaDocente* Fabrica::getICAsignarAsignaturaDocente(){
    return new CAsignarAsignaturaDocente();
}


ICInicioClase* Fabrica::getICInicioClase(){
    return new CInicioClase();
}

ICEliminarAsignatura * Fabrica::getICEliminarAsignatura(){
    return new CEliminarAsignatura();
}

ICListadoClase * Fabrica::getICListadoClase(){
    return new CListadoClase();
}
