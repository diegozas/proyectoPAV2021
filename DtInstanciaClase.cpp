#include "DtInstanciaClase.h"
DtInstanciaClase::DtInstanciaClase(){}
DtInstanciaClase::DtInstanciaClase(bool monitoreo,bool practico,bool teorico){
    this->monitoreo=monitoreo;
    this->practico=practico;
    this->teorico=teorico;
}
bool DtInstanciaClase::getMonitoreo(){
    return this->monitoreo;
}
bool DtInstanciaClase::getPractico(){
    return this->practico;
}
bool DtInstanciaClase::getTeorico(){
    return this->teorico;
}
DtInstanciaClase::~DtInstanciaClase(){}


ostream& operator <<(ostream& sal,const DtInstanciaClase& dt){
    if(dt.monitoreo && dt.practico && dt.teorico){
        cout<<"Tipo: Monitoreo, Practico y Teorico"<<endl;
        return sal;
    }else if(dt.monitoreo && dt.practico){
        cout<<"Tipo: Monitoreo y Practico"<<endl;
        return sal;
    }else if(dt.monitoreo && dt.teorico){
        cout<<"Tipo: Monitoreo y Teorico"<<endl;
        return sal;
    }else if(dt.practico && dt.teorico){
        cout<<"Tipo: Practico y Teorico"<<endl;
        return sal;
    }else if(dt.practico){
        cout<<"Tipo: Practico"<<endl;
        return sal;
    }else if(dt.monitoreo){
        cout<<"Tipo: Monitoreo"<<endl;
        return sal;
    }else{
        cout<<"Tipo: Teorico"<<endl;
        return sal;
    }
}