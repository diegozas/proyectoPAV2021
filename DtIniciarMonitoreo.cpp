#include"TimeStamp.h"
#include"DtIniciarClaseFull.h"
#include"DtIniciarClase.h"
#include"DtIniciarMonitoreo.h"
#include<iostream>

using namespace std;

DtIniciarMonitoreo::DtIniciarMonitoreo(){};
DtIniciarMonitoreo::DtIniciarMonitoreo(string codigo,string nombre,TimeStamp fechaHora,int id,list<string> habilitados){
    this->codigo=codigo;
    this->nombre=nombre;
    this->fechaHora=fechaHora;
    this->id=id;
    this->habilitados=habilitados;
}

list<string> DtIniciarMonitoreo::getHabilitados(){
    return this->habilitados;
}
DtIniciarMonitoreo::~DtIniciarMonitoreo(){}