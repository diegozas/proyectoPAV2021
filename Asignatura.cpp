#include "Asignatura.h"
#include "Clase.h"
#include "Monitoreo.h"

Asignatura::Asignatura(){}
Asignatura::Asignatura(string codigo,string nombre,DtInstanciaClase dt){
    this->codigo=codigo;
    this->nombre=nombre;
    this->tipoClase=dt;
}
void Asignatura::setCodigo(string codigo){
    this->codigo=codigo;
}
void Asignatura::setNombre(string nombre){
    this->nombre=nombre;
}

void Asignatura::setTipo(DtInstanciaClase dt){
    this->tipoClase=dt;
}

string Asignatura::getCodigo(){
    return this->codigo;
}
string Asignatura::getNombre(){
    return this->nombre;
}

DtInstanciaClase Asignatura::getTipo(){
    return this->tipoClase;
}

Asignatura::~Asignatura(){}



list<int> Asignatura::clasesOnline(){
    list<int> clase;
    for(map<int,Clase*>::iterator it= this->clases.begin();it!=this->clases.end();++it){
        clase.push_back(it->first);
    }
    return clase;
}


void Asignatura::agregarClase(Clase* c){
    clases.insert(std::pair<int,Clase*>(c->getId(),c));
}
void Asignatura::eliminarClaes(){
    for(map<int,Clase*>::iterator it=this->clases.begin();it!=this->clases.end();++it){
        it->second->eliminarAsisteEnVivo();
        it->second->eliminarDocentes();
        it->second->eliminarParticipacion();
        if(Monitoreo *m=dynamic_cast<Monitoreo*>(it->second)){
            m->borrarEstudiantes();
        }
        Clase *c=it->second;
        delete c;
    }
    clases.clear();
}


map<int,Clase*> Asignatura::getClases(){
    return this->clases;
}