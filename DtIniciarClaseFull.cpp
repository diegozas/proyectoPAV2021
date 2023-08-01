#include "DtIniciarClase.h"
#include "DtIniciarClaseFull.h"
#include "TimeStamp.h"
#include<iostream>
#include<list>

using namespace std;

DtIniciarClaseFull::DtIniciarClaseFull(){};
DtIniciarClaseFull::DtIniciarClaseFull(string codigo,string nombre,TimeStamp fechaHora,int id){
    this->codigo=codigo;
    this->nombre=nombre;
    this->fechaHora=fechaHora;
    this->id=id;
}

int DtIniciarClaseFull::getId(){
    return this->id;
}

ostream& operator<<(ostream& salida,const DtIniciarClaseFull&dt){// Nuevo Carlos
    cout<<"Codigo de Asignatura: "<<dt.codigo<<" "<<"Nombre de la clase: "<< dt.nombre <<" "<<"Fecha y Hora: "<< dt.fechaHora<<endl<<"Id clase:"<<dt.id<<endl;
    return salida;
}
DtIniciarClaseFull::~DtIniciarClaseFull(){};