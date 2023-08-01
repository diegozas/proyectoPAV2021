#include "ManejadorAsignatura.h"
ManejadorAsignatura* ManejadorAsignatura::instancia=NULL;
ManejadorAsignatura::~ManejadorAsignatura(){}
ManejadorAsignatura::ManejadorAsignatura(){}

ManejadorAsignatura* ManejadorAsignatura::getInstancia(){
    if(instancia==NULL)
        instancia=new ManejadorAsignatura();
    return instancia; 
}

Asignatura* ManejadorAsignatura::obtenerAsignatura(string codigo){
    map<string,Asignatura*>::iterator it=this->coleccionAsignaturas.find(codigo);
    if(it!=this->coleccionAsignaturas.end()){
        return it->second;
    }else{
        return NULL;
    }
}

map<string,Asignatura*> ManejadorAsignatura::listarAsignaturas(){
    return this->coleccionAsignaturas;
}

void ManejadorAsignatura::borrarAsignatura(string codigo){
    map<string,Asignatura*>::iterator it=this->coleccionAsignaturas.find(codigo);
    this->coleccionAsignaturas.erase(it);
}

void ManejadorAsignatura::agregarAsignatura(Asignatura* a){
    coleccionAsignaturas.insert(std::pair<string,Asignatura*>(a->getCodigo(),a));
}

bool ManejadorAsignatura::existeAsignatura(string codigo){
    map<string,Asignatura*>::iterator it=this->coleccionAsignaturas.find(codigo);
    if(it!=this->coleccionAsignaturas.end()){
        return true;
    }else{
        return false;
    }
}

list<string> ManejadorAsignatura::codigoAsignaturas(){
    list<string> codigos;
    for(map<string,Asignatura*>::iterator it=this->coleccionAsignaturas.begin(); it!=this->coleccionAsignaturas.end();++it){
        codigos.push_back(it->first);
    }
    return codigos;
}