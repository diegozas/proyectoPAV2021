#include "CEliminarAsignatura.h"


CEliminarAsignatura::CEliminarAsignatura(){}

CEliminarAsignatura::~CEliminarAsignatura(){}

list<string> CEliminarAsignatura::listarAsignaturas(){
    ManejadorAsignatura* ma=ManejadorAsignatura::getInstancia();
    list<string> asignaturas;
    asignaturas=ma->codigoAsignaturas();
    return asignaturas;
}

void CEliminarAsignatura::selectAsignatura(string codigo){
    this->codigo=codigo;
}

void CEliminarAsignatura::eliminarAsignatura(){
    ManejadorAsignatura* ma=ManejadorAsignatura::getInstancia();
    ManejadorPerfil* mp=ManejadorPerfil::getInstance();
    ManejadorClase* mc=ManejadorClase::getInstance();
    
    map<int,Clase*> clases;
    Asignatura *a=ma->obtenerAsignatura(this->codigo);
    list<Perfil*> perfiles=mp->getPerfiles();
    clases=a->getClases();


    //Remuve de la coleccion global de clases las calses que tiene asignado la asignautra
    for(map<int,Clase*>::iterator it=clases.begin();it!=clases.end();++it){
        mc->removerClase(it->second);

    }

    //Remueve la asignatura de los perfiles
    for(list<Perfil*>::iterator it=perfiles.begin();it!=perfiles.end();++it){
        if(Estudiante *e=dynamic_cast<Estudiante*>(*it)){
            e->eliminarAsignatura(a->getCodigo());
        }else if(Docente* d=dynamic_cast<Docente*>(*it)){
            d->eliminarAsignatura(a->getCodigo());
        }
    }
    a->eliminarClaes();
    ma->borrarAsignatura(a->getCodigo());
    delete a;
}

void CEliminarAsignatura::cancelar(){}