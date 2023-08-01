#include "CListadoClases.h"
#include "ManejadorPerfil.h"
#include "ManejadorAsignatura.h"
#include "Clase.h"
#include "Monitoreo.h"
#include "Teorico.h"
#include "Practico.h"

CListadoClase::CListadoClase() {}
CListadoClase::~CListadoClase() {}

list<string> CListadoClase::asignaturasAsignadas(string email){
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    Perfil *perfil = mp->getPerfil(email);
    this->emailDocente = email;
    list<string> asignaturas;
    if (Docente *d = dynamic_cast<Docente *>(perfil)){
        asignaturas = d->asignaturas();
    }
    return asignaturas;
}

list<DtInfoClase *> CListadoClase::selectAsignatura(string codigoAsignatura){
    ManejadorAsignatura *ma = ManejadorAsignatura::getInstancia();
    Asignatura *a = ma->obtenerAsignatura(codigoAsignatura);
    list<DtInfoClase *> dtic;
    DtInfoClase *dtinfo;
    map<int, Clase *> clases = a->getClases();
    for (map<int, Clase *>::iterator it = clases.begin(); it != clases.end(); ++it){
        if ((it->second)->existeDocente(this->emailDocente)){
            if (Monitoreo *m = dynamic_cast<Monitoreo *>(it->second)){
                dtinfo = m->getDtInfoClase();
                dtic.push_back(dtinfo);
            }
            else{
                if (Teorico *t = dynamic_cast<Teorico *>(it->second))
                {
                    dtinfo = t->getDtInfoClase();
                    dtic.push_back(dtinfo);
                }
                else
                {
                    dtinfo = it->second->getDtInfoClase();
                    dtic.push_back(dtinfo);
                }
            }
        }
    }
    return dtic;
}

list<string> CListadoClase::getEmailsDocentes(){
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    list<Perfil *> perfiles = mp->getPerfiles();
    list<string> correos;
    for (list<Perfil *>::iterator it = perfiles.begin(); it != perfiles.end(); ++it){
        if (Docente *d = dynamic_cast<Docente *>(*it)){
            correos.push_back(d->getEmail());
        }
    }
    return correos;
};