#include "CAltaAsignatura.h"
#include <iostream>
using namespace std;

CAltaAsignatura::CAltaAsignatura(){}
CAltaAsignatura::~CAltaAsignatura(){}

DtAsignatura CAltaAsignatura::ingresar(DtAsignatura datosAsignatura){
    this->setDatos(datosAsignatura);
    DtAsignatura datos= DtAsignatura(datosAsignatura.getCodigo(),datosAsignatura.getNombre(),datosAsignatura.getTipo());
    return datos;

}

void CAltaAsignatura::altaAsignatura(){
    
    ManejadorAsignatura * ma=ManejadorAsignatura::getInstancia();
    bool existe= ma->existeAsignatura(this->datos.getCodigo());
    if(existe){
        throw invalid_argument ("ERROR:YA EXISTE UNA ASIGNATURA CON ESE CODIGO EN EL SISTEMA"); 
    }else{
    Asignatura *a= new Asignatura(this->datos.getCodigo(),this->datos.getNombre(),this->datos.getTipo());
    ma->agregarAsignatura(a);
    cout<<"Se agrego la asignatura de codigo: "<<this->datos.getCodigo()<<" Correctamente"<<endl;
    cout<<"Presione Enter para continuar"<<endl;
    system("read X");
   }
}


void CAltaAsignatura::cancelar(){}

void CAltaAsignatura::setDatos(DtAsignatura dt){
    this->datos=dt;
}




 void CAltaAsignatura::cargarDatos(){
     ManejadorAsignatura*ma=ManejadorAsignatura::getInstancia();
     DtInstanciaClase dti=DtInstanciaClase(true,true,true);
     DtInstanciaClase dti2=DtInstanciaClase(true,true,true);
     
     Asignatura*a=new Asignatura("1","PAV",dti);
     Asignatura*a1=new Asignatura("2","BD",dti2); 
     ma->agregarAsignatura(a);
     ma->agregarAsignatura(a1);
 }