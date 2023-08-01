#include "DtInfoClase.h"
#include<iostream>
#include<list>

using namespace std;

DtInfoClase::DtInfoClase(){};
DtInfoClase::DtInfoClase(int id,string nombre,list<string> docentes){
    this->id=id;
    this->nombre=nombre;
    this->docentes=docentes;    
};
int DtInfoClase::getId(){
    return this->id;
};
string DtInfoClase::getNombre(){
    return this->nombre;
};
list<string> DtInfoClase:: getDocentes(){
    return this->docentes;
}
ostream& operator <<(ostream & salida,const DtInfoClase* dt){
    cout<<"ID: "<<dt->id<<endl<<"NOMBRE: "<<dt->nombre<<endl;
    return salida;
}
DtInfoClase::~DtInfoClase(){};