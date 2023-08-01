#include "DtAsignatura.h"
DtAsignatura::DtAsignatura(){}
DtAsignatura::DtAsignatura(string codigo,string nombre,DtInstanciaClase tipo){
    this->codigo=codigo;
    this->nombre=nombre;
    this->tipoClase=tipo;
}
string DtAsignatura::getCodigo(){
    return this->codigo;
}
string DtAsignatura::getNombre(){
    return this->nombre;
}
DtInstanciaClase DtAsignatura::getTipo(){
    return this->tipoClase;
}
DtAsignatura::~DtAsignatura(){}

ostream& operator <<(ostream& sal, const DtAsignatura& a){
    cout<<"Codigo: "<<a.codigo<<endl<<"Nombre: "<<a.nombre<<endl<<a.tipoClase;
    return sal;
}