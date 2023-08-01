#include "DtAsistir.h"
#include<iostream>

using namespace std;

DtAsistir::DtAsistir(){}
DtAsistir::DtAsistir(string codigo, int id){
    this->codigo=codigo;
    this->id=id;
}

string DtAsistir::getCodigo(){
    return this->codigo;
}

int DtAsistir::getId(){
    return this->id;
}
DtAsistir::~DtAsistir(){}


ostream& operator <<(ostream& sal,const DtAsistir& dt){
    cout<<"Codigo: "<<dt.codigo<<endl<<"Id: "<<dt.id<<endl;
    return sal;
}