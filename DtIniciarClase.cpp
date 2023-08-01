#include "DtIniciarClase.h"
#include "TimeStamp.h"
#include <iostream>

using namespace std;

DtIniciarClase::DtIniciarClase(){};
DtIniciarClase::DtIniciarClase(string codigo,string nombre,TimeStamp fechaHora){
    this->codigo=codigo;
    this->nombre=nombre;
    this->fechaHora=fechaHora;
}

string DtIniciarClase::getCodigo(){
    return this->codigo;
}
string DtIniciarClase::getNombre(){
    return this->nombre;
}

TimeStamp DtIniciarClase::getFechaHora(){
    return this->fechaHora;
}
DtIniciarClase::~DtIniciarClase(){};