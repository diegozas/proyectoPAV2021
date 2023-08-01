#include"CAsignarAsignaturaDocente.h"
#include<iostream>
#include <list>
#include <map>
#include"ManejadorPerfil.h"
#include"ManejadorAsignatura.h"
#include"TipoRol.h"
#include "Perfil.h"
#include "Docente.h"


using namespace std;
    ManejadorAsignatura *ma= ManejadorAsignatura::getInstancia();
    ManejadorPerfil *mp =ManejadorPerfil::getInstance();
    
    CAsignarAsignaturaDocente::CAsignarAsignaturaDocente(){};

    list<string>CAsignarAsignaturaDocente:: listarAsignaturas(){
        if(ma->listarAsignaturas().size()==0){
            throw invalid_argument("NO HAY ASIGNATURAS");
        }
        this->asignaturas=ma->listarAsignaturas();
        list<string>as;
        for(map<string,Asignatura*>::iterator it=this->asignaturas.begin(); it!=this->asignaturas.end();++it){
            as.push_back(it->first);
        }
        return as;
    };

    list<string>CAsignarAsignaturaDocente:: docentesSinLaAsignatura(string cod){
        this->codAsignatura=cod;
        if(mp->getPerfiles().size()==0){
            throw invalid_argument("NO HAY PERFILES CREADOS!");
        }else{
            list<Perfil*> perfiles=mp->getPerfiles();                
            list<string>docentes;
            Docente *doc;            
            for(list<Perfil*>::iterator it=perfiles.begin(); it!=perfiles.end();++it){
                doc=dynamic_cast<Docente*>(*it);
                if(doc!=NULL){
                    if(!doc->noDictaAsignatura(cod)){
                        docentes.push_back(doc->getEmail());                        
                    }                                
                }
            }
            if(docentes.size()==0){
                throw invalid_argument("NO HAY DOCENTES PARA ASIGNAR!");
            }
            return docentes; 
        }
       
    };
    DtInstanciaClase CAsignarAsignaturaDocente::getInstancias(){
        DtInstanciaClase dti=ma->obtenerAsignatura(this->codAsignatura)->getTipo();
        return dti;
    };
    void CAsignarAsignaturaDocente::selectDocente(TipoRol rol,string email){
        this->email=email;
        this->rol=rol;
    };

    void CAsignarAsignaturaDocente::asignarDocente(){
        Perfil * perfil=mp->getPerfil(this->email);
        Asignatura * asig=ma->obtenerAsignatura(this->codAsignatura);
        Rol *r=new Rol(asig,this->rol);
        Docente *d;
        d=dynamic_cast<Docente*>(perfil);
        d->addRol(r);
        cout<<"ASIGNACION REALIZADA CON EXITO..."<<endl;
    };

    void CAsignarAsignaturaDocente::cargarDatos(){
    Perfil*p=mp->getPerfil("3");
    Asignatura* a=ma->obtenerAsignatura("1");
    Asignatura* a1=ma->obtenerAsignatura("2");
    Rol*r=new Rol(a,PRACTICO);
    Rol*r1=new Rol(a1,TEORICO);
    if(Docente* d=dynamic_cast<Docente*>(p)){
        d->addRol(r);
    }
    
    if(Docente* d=dynamic_cast<Docente*>(p)){
        d->addRol(r1);
    }


}

    CAsignarAsignaturaDocente::~CAsignarAsignaturaDocente(){};

