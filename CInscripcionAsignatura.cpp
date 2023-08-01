#include "CInscripcionAsignatura.h"

CInscripcionAsignatura::CInscripcionAsignatura(){}
CInscripcionAsignatura::~CInscripcionAsignatura(){}

list<string> CInscripcionAsignatura::asignaturaNoInscripto(string email){
  ManejadorAsignatura* ma=ManejadorAsignatura::getInstancia();
  ManejadorPerfil* mp=ManejadorPerfil::getInstance();
  list<string> noAsignado;
  this->p=mp->getPerfil(email);
  this->asignaturas=ma->listarAsignaturas();
  for(map<string,Asignatura*>::iterator it= this->asignaturas.begin(); it!=this->asignaturas.end();++it){
      if(Estudiante* e= dynamic_cast<Estudiante*>(this->p)){
          if(!e->tieneAsignatura(it->second->getCodigo())){
              noAsignado.push_back(it->first);
            }
        }
  }
  return noAsignado;
    
}

void CInscripcionAsignatura::selectAsignatura(string codigo){
    this->codigo=codigo;
     
}

void CInscripcionAsignatura::inscribir(){
    ManejadorAsignatura* ma=ManejadorAsignatura::getInstancia();
    Asignatura* a= ma->obtenerAsignatura(codigo);
    if(Estudiante* e=dynamic_cast<Estudiante*>(this->p)){
        e->agregarAsignatura(a);
    }
    this->p=NULL;
    cout<<"Se inscribio a la Asignatura de codigo "<<this->codigo<<" Correctamente"<<endl;
    cout<<"Presione ENTER para continuar"<<endl;
    system("read X");
}

list<string> CInscripcionAsignatura::getEmailsEstudiantes()
{
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    list<Perfil *> perfiles = mp->getPerfiles();
    list<string> correos;
    for (list<Perfil*>::iterator it=perfiles.begin();it!=perfiles.end();++it)
    {
        if(Estudiante *d = dynamic_cast<Estudiante *>(*it)){
            correos.push_back(d->getEmail());
        }
        
    }
    return correos;
}

void CInscripcionAsignatura::cargarDatos(){
    ManejadorPerfil*mp=ManejadorPerfil::getInstance();
    ManejadorAsignatura* ma=ManejadorAsignatura::getInstancia();
    
    Perfil*p=mp->getPerfil("1");
    
    Asignatura* a1= ma->obtenerAsignatura("1");
    Asignatura* a2= ma->obtenerAsignatura("2");
   
    if(Estudiante* e=dynamic_cast<Estudiante*>(p)){
        e->agregarAsignatura(a1);
    }
    if(Estudiante* e=dynamic_cast<Estudiante*>(p)){
        e->agregarAsignatura(a2);
    }
}

void CInscripcionAsignatura::cancelar(){}