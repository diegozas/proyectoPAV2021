#include "Docente.h"
using namespace std;
Docente::Docente(){}
Docente::Docente(string nombre,string imagen,string email,string password,string ins):Perfil(nombre,imagen,email,password){
    this->instituto=ins;
}
void Docente::setInstituto(string ins){
    this->instituto=ins;
}
bool Docente::noDictaAsignatura(string cod){//NUEVO
    bool encontre=false;
    for(list<Rol*>::iterator it=this->roles.begin();it!=this->roles.end();++it){
        Rol *r=dynamic_cast<Rol*>(*it);
        if(r->getAsignatura()->getCodigo()==cod){
            encontre=true;
        }
    }
    return encontre;
};
list<Rol*>Docente::getRoles(){
    return this->roles;
}
bool Docente::tieneMonitoreo(string codigo){
    Rol *r;
    bool monitoreo =false;    
    for(list<Rol*>::iterator it=this->roles.begin();it!=this->roles.end();++it){
        if(r=dynamic_cast<Rol*>(*it)){
            if(r->getAsignatura()->getCodigo()==codigo){
                if(r->getTipoRol()==MONITOREO){
                    monitoreo=true;
                }                
            }
        }
    }
    return monitoreo;
}
list<string> Docente::asignaturas(){
    list<string>cod;
    for(list<Rol*>::iterator it=this->roles.begin();it!=this->roles.end();++it){
        Rol *r=dynamic_cast<Rol*>(*it);
        if(r!=NULL){
            Asignatura *a=r->getAsignatura();
            string codigo=a->getCodigo();
            cod.push_back(codigo);
        }
    }
    return cod;
}
string Docente::getInstituo(){
    return this->instituto;
}
void Docente::addRol(Rol*rol){//NUEVO
    this->roles.push_back(rol);
}

void Docente::eliminarAsignatura(string codigo){
    bool borre=false;
    list<Rol*>::iterator it=this->roles.begin();
    while(it!=this->roles.end() && !borre){
        if((*it)->getAsignatura()->getCodigo()==codigo){
            Rol* r=(*it);
            roles.remove(r);
            delete r;
            borre =true;
        }else{
            it++;
        }
    }
}
Docente::~Docente(){}