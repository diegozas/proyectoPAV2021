#include"DtParticipacion.h"
#include "TimeStamp.h"
#include<iostream>
#include<list>
using namespace std;

DtParticipacion::DtParticipacion(){}
DtParticipacion::DtParticipacion(int id,TimeStamp fecha,string mensaje,string email){
    this->id=id;
    this->fecha=fecha;
    this->mensaje=mensaje;
    this->email=email;
    this->respuesta=false;
}



DtParticipacion::DtParticipacion(int id,TimeStamp fecha,string mensaje,string email,DtParticipacion* dt){
    this->id=id;
    this->fecha=fecha;
    this->mensaje=mensaje;
    this->email=email;
    this->responde=dt;
    this->respuesta=true;
     
}


bool DtParticipacion::tieneRespuesta(){
    return this->respuesta;
}

DtParticipacion* DtParticipacion::getRespuesta(){
    return this->responde;
}

int DtParticipacion::getId(){
    return this->id;
}

TimeStamp DtParticipacion::getFecha(){
    return this->fecha;
}

string DtParticipacion::getMensaje(){
    return this->mensaje;
}


DtParticipacion::~DtParticipacion(){}




ostream& operator<<(ostream& sal,const DtParticipacion* dt){
    cout<<"ID: "<<dt->id<<" "<<(TimeStamp)dt->fecha<<" "<<"Usuario: "<<dt->email<<endl<<"Mensaje: "<<dt->mensaje<<endl;
    return sal;
}