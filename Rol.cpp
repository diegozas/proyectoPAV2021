#include "Rol.h"
Rol::Rol(){}
Rol::Rol(Asignatura* a,TipoRol rol){
    this->asignatura=a;
    this->rol=rol;
}
void Rol::setTipoRol(TipoRol rol){
    this->rol=rol;
}
void Rol::setAsignatura(Asignatura* a){
    this->asignatura=a;
}
Asignatura* Rol::getAsignatura(){
    return this->asignatura;
}
TipoRol Rol::getTipoRol(){
    return this->rol;
}
Rol::~Rol(){}