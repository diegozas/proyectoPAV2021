#include "CInicioClase.h"
#include "ManejadorAsignatura.h"
#include "ManejadorClase.h"
#include "DtInstanciaClase.h"
#include "Estudiante.h"
#include "Teorico.h"
#include "Monitoreo.h"
#include "Practico.h"
#include "ManejadorPerfil.h"

class ManejadorPerfil;

//ManejadorAsignatura *ma= ManejadorAsignatura::getInstancia();
//ManejadorPerfil *mp =ManejadorPerfil::getInstance();
//ManejadorClase *mc =ManejadorClase::getInstance();


CInicioClase::CInicioClase(){}
CInicioClase::~CInicioClase(){}


list <string> CInicioClase::asignaturasAsignadas(string email){
    ManejadorPerfil *mp =ManejadorPerfil::getInstance();
    Perfil *p=mp->getPerfil(email);
    Docente * d=dynamic_cast<Docente*>(p);
    this->docente=d;
    return d->asignaturas();
}
bool CInicioClase::selectAsignatura(DtIniciarClase iniciarClase){    
    this->ic=iniciarClase;
    Docente * d = this->docente;

    bool tiene=d->tieneMonitoreo(iniciarClase.getCodigo());
    return tiene;
}

list <string> CInicioClase::inscriptosAsignaturas(){
    ManejadorPerfil *mp =ManejadorPerfil::getInstance();
    list<string> email; 
    list<Perfil*> perfiles=mp->getPerfiles();   
    for(list<Perfil*>::iterator it=perfiles.begin();it!=perfiles.end();++it){
        Estudiante * e;
        if(e=dynamic_cast<Estudiante*>(*it)){
            if(e->estaInscripto(this->ic.getCodigo())){
                email.push_back(e->getEmail());
            }
        }
    }

    return email;
}
void CInicioClase::habilitar(string email){
    this->habilitados.push_back(email);
    ManejadorPerfil *mp =ManejadorPerfil::getInstance();
    Perfil *p = mp->getPerfil(email);
    Estudiante *e=dynamic_cast<Estudiante*>(p);
    e->setHabilitado(true);
}
int maximoId(){
    ManejadorClase *mc =ManejadorClase::getInstance();
    list<Clase*> clases=mc->getClases();
    int maximo = 0;
    if (!mc->getClases().empty()){
        for(list<Clase*>::iterator it=clases.begin();it!=clases.end();++it){
            Clase *c;
            if(c=dynamic_cast<Clase*>(*it)){
                if(c->getId() > maximo){
                    maximo = c->getId();
                }
            }
        }
    }
    return maximo;
}

DtIniciarClaseFull CInicioClase::datosIngresados(){
    int id = maximoId() + 1;
    DtIniciarClaseFull dtif=DtIniciarClaseFull(this->ic.getCodigo(), this->ic.getNombre(), this->ic.getFechaHora(), id);
    this->data=dtif;
    return dtif;
}

Rol * CInicioClase::obtenerRolEnAsignaturaSeleccionada(){
    Rol *rolBuscado;    
    list<Rol*>roles=this->docente->getRoles();
    for(list<Rol*>::iterator it=roles.begin();it!=roles.end();++it ){
        Rol* r=dynamic_cast<Rol*>(*it);
        if(r->getAsignatura()->getCodigo()==this->ic.getCodigo()){
            rolBuscado=r;
        }        
    }
    return rolBuscado;
}

Clase* CInicioClase::crearClaseSegunTipo(TipoRol tipo){
    Clase *c;
    switch (tipo)
    {
    case TEORICO:
        c = new Teorico(this->data.getId(), this->data.getNombre(),this->data.getFechaHora(),this->docente,this->data.getCodigo());
        break;
    case PRACTICO:
        c = new Practico(this->data.getId(), this->data.getNombre(),this->data.getFechaHora(),this->docente,this->data.getCodigo());
        break;
    case MONITOREO:
        c = new Monitoreo(this->data.getId(), this->data.getNombre(),this->data.getFechaHora(),this->docente,this->habilitados,this->data.getCodigo());
        break;
    default:
        break;
    }
    return c;
}

void CInicioClase::iniciarClase(){
    ManejadorAsignatura *ma= ManejadorAsignatura::getInstancia();
    ManejadorClase *mc =ManejadorClase::getInstance();    
    Rol * rolEnAsignatura = obtenerRolEnAsignaturaSeleccionada();
    Clase * clase = crearClaseSegunTipo(rolEnAsignatura->getTipoRol());
    mc->agregarClase(clase);
    Asignatura * asignatura = ma -> obtenerAsignatura(this->data.getCodigo());
    asignatura->agregarClase(clase);
}

list<string> CInicioClase::getEmailsDocentes()
{
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    list<Perfil *> perfiles = mp->getPerfiles();
    list<string> correos;
    for (list<Perfil*>::iterator it=perfiles.begin();it!=perfiles.end();++it)
    {
        if(Docente *d = dynamic_cast<Docente *>(*it)){
            correos.push_back(d->getEmail());
        }
        
    }
    return correos;
};
void CInicioClase::cargarDatos(){
    Fecha fecha(12, 12, 2021);
    TimeStamp time (fecha, 1, 1, 1);
    ManejadorPerfil *mp= ManejadorPerfil::getInstance();
    ManejadorClase *mc= ManejadorClase::getInstance();
    ManejadorAsignatura *ma= ManejadorAsignatura::getInstancia();
    Perfil *p= mp->getPerfil("3");
    if(Docente *d=dynamic_cast<Docente*>(p)){
        Asignatura *a = ma->obtenerAsignatura("1");
        Asignatura *a2= ma->obtenerAsignatura("2");
        Teorico *t= new Teorico(1,"NuevaClase",time,d,"1");
        Practico *p= new Practico(2,"NuevaClase2",time,d,"2");
        mc->agregarClase(t);
        mc->agregarClase(p);
        a->agregarClase(t);
        a2->agregarClase(p);
    }

    
}

void CInicioClase::cancelar(){}//Nuevo