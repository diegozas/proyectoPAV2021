#include "Fecha.h"

Fecha::Fecha(){}
Fecha::Fecha(int dia,int mes, int anio){
  if (dia<1 || dia>31 || mes<1 || mes>12 || anio<1900)
    throw invalid_argument("Fecha no valida\n");
  else{
    this->dia=dia;
    this->mes=mes;
    this->anio=anio;
  }
}

int Fecha::getDia(){
    return this->dia;
}

int Fecha::getMes(){
    return this->mes;
}

int Fecha::getAnio(){
    return this->anio;
}

Fecha::~Fecha(){}


ostream& operator<<(ostream& sal,const Fecha& f){
    cout<<f.dia<<"/"<<f.mes<<"/"<<f.anio<<" ";
    return sal;
}