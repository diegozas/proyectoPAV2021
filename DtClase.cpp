#include<iostream>
#include "TipoRol.h"
#include "TimeStamp.h"
#include "DtClase.h"
using namespace std;

DtClase::DtClase(){}
DtClase::DtClase(int id,string nombre,TipoRol tipo,TimeStamp inicio ){
    this->id=id;
    this->nombre=nombre;
    this->tipo=tipo;
    this->inicio=inicio;
}

int DtClase::getId(){
    return this->id;
};
string DtClase::getNombre(){
    return this->nombre;
};
TipoRol DtClase::getTipo(){
    return this->tipo;
};
TimeStamp DtClase::getInicio(){
    return this->inicio;
};
DtClase::~DtClase(){}