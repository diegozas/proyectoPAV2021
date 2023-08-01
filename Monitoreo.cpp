#include "Monitoreo.h"
#include "ManejadorPerfil.h"
#include "DtInfoMonitoreo.h"
class ManejadorPerfil;

Monitoreo::Monitoreo() {}
Monitoreo::Monitoreo(int id, string nombre, TimeStamp inicio, Docente *docente, list<string> habilitados, string codigoAsignatura) : Clase(id, nombre, inicio, docente, codigoAsignatura)
{
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    this->estudiantes = mp->obtenerMapEstudiantes(habilitados);
}
void Monitoreo::borrarEstudiantes()
{
    //for(map<string,Estudiante*>::iterator it=this->estudiantes.begin();it!=this->estudiantes.end();++it){
    //    estudiantes.erase(it);
    //}
    estudiantes.clear();
}

DtInfoClase * Monitoreo::getDtInfoClase()
{

    list<string> profes;
    list<string> habilitados;
    map<string,Docente*> docentes=getDocentes();
    for (map<string, Docente *>::iterator it = docentes.begin(); it != docentes.end(); ++it)
    {
        profes.push_back(it->second->getNombre());
    }
    for (map<string, Estudiante *>::iterator it = this->estudiantes.begin(); it != this->estudiantes.end(); ++it)
    {
        habilitados.push_back(it->second->getNombre());
    }

    DtInfoMonitoreo *dtic = new DtInfoMonitoreo(getId(), getNombre(), profes,habilitados);
    return dtic;
}
Monitoreo::~Monitoreo() {}
