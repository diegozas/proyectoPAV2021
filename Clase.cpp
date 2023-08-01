#include "Clase.h"


Clase::Clase(){}
Clase::Clase(int id,string nombre,TimeStamp inicio,Docente *docente,string codigoAsignatura){
    this->id=id;
    this->nombre=nombre;
    this->inicio=inicio;
    this->docentes.insert(pair<string,Docente*>(docente->getEmail(),docente));
    this->codigoAsignatura=codigoAsignatura;
}
void Clase::setID(int id){
    this->id=id;
}
void Clase::setInicio(TimeStamp inicio){
    this->inicio=inicio;
}
void Clase::setFinal(TimeStamp final){
    this->final=final;
}
void Clase::setRuta(string ruta){
    this->rutaVideo=ruta;
}
int Clase::getId(){
    return this->id;
}
string Clase::getNombre(){
    return this->nombre;
}
TimeStamp Clase::getInicio(){
    return this->inicio;
}
TimeStamp Clase::getFinal(){
    return this->final;
}
string Clase::getRuta(){
    return this->rutaVideo;
}
Clase::~Clase(){}


 void Clase::agregarAsistencia(AsistenteEnVivo* a){
     this->vivo.push_back(a);
 }


 int Clase::getAsistencias(){
     return this->vivo.size();
 }


 void Clase::agregarParticipacion(Participacion* p){
     this->coleccionParticipaciones.insert(pair<int,Participacion*>(p->getId(),p));
 }


 list<AsistenteEnVivo*> Clase::getAsistencia(){
     return this->vivo;
 }


 bool Clase::existeDocente(string email){
     map<string,Docente*>::iterator it=this->docentes.find(email);
     if(it!=this->docentes.end()){
         return true;
     }else{
         return false;
     }

 }


bool Clase::existeParticipacion(int id){
    map<int,Participacion*>::iterator it=this->coleccionParticipaciones.find(id);
    if(it!=this->coleccionParticipaciones.end()){
        return true;
    }else{
        return false;
    }
}

int Clase::getCantParticipaciones(){
    return this->coleccionParticipaciones.size();
}


 map<int,Participacion*> Clase::getColeccionParticipacion(){
     return this->coleccionParticipaciones;
 }



 Participacion* Clase::getParticipacion(int id){
    map<int,Participacion*>::iterator it=this->coleccionParticipaciones.find(id);
    return it->second;
}



void Clase::agregarDocente(Docente* d){
    docentes.insert(std::pair<string,Docente*>(d->getEmail(),d));
}
void Clase::eliminarParticipacion(){
    for(map<int,Participacion*>::iterator it=this->coleccionParticipaciones.begin();it!=this->coleccionParticipaciones.end();++it){
        Participacion*p=it->second;
        delete p;
    }
    coleccionParticipaciones.clear();
}

void Clase::eliminarAsisteEnVivo(){
    for(list<AsistenteEnVivo*>::iterator it=this->vivo.begin();it!=this->vivo.end();++it){
        AsistenteEnVivo* a=*it;
        delete a;
    }
    this->vivo.clear();
}

void Clase::eliminarDocentes(){
    //for(map<string,Docente*>::iterator it=this->docentes.begin();it!=this->docentes.end();++it){
    //    docentes.erase(it);
    //}
    docentes.clear();    
}

DtInfoClase * Clase::getDtInfoClase(){

    list<string> profes;
    for(map<string,Docente*>::iterator it=this->docentes.begin();it!= this->docentes.end();++it){
        profes.push_back(it->second->getNombre());
    }

    DtInfoClase* dtic= new DtInfoClase(this->id,this->nombre,profes);
    return dtic;

}
map<string,Docente*> Clase::getDocentes(){
    return this->docentes;
}
