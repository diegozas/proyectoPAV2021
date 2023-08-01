#include"DtInfoClase.h"
#include"DtInfoMonitoreo.h"
#include<iostream>
#include<list>

using namespace std;

DtInfoMonitoreo::DtInfoMonitoreo(){};
DtInfoMonitoreo::DtInfoMonitoreo(int id,string nombre,list<string> docentes,list<string> estudiantes){
    this->id=id;
    this->nombre=nombre;
    this->docentes=docentes;
    this->estudiantes=estudiantes;
};
list<string> DtInfoMonitoreo::getEstudiantes(){
    return this->estudiantes;
}
DtInfoMonitoreo::~DtInfoMonitoreo(){};