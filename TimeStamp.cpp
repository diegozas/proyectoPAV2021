#include "TimeStamp.h"
#include "Fecha.h"

TimeStamp::TimeStamp(){}

TimeStamp::TimeStamp(Fecha fecha,int hora,int minuto,int segundo){
    if (hora<0 || hora>23 || minuto<0 || minuto>60 || segundo<0 || segundo>60)
    throw invalid_argument("Horario no valido\n");
    else{
        this->fecha=fecha;
        this->hora=hora;
        this->minuto=minuto;
        this->segundo=segundo;
    }
}

Fecha TimeStamp::getFecha(){
    return this->fecha;
}
int TimeStamp::getHora(){
    return this->hora;
}
int TimeStamp::getMinuto(){
    return this->minuto;
}
int TimeStamp::getSegundo(){
    return this->segundo;
}
TimeStamp::~TimeStamp(){}



ostream& operator<<(ostream& sal,const TimeStamp& t){
    cout<<"Fecha:"<<(Fecha)t.fecha<<"Hora:"<<t.hora<<":"<<t.minuto<<":"<<t.segundo;
    return sal;
}