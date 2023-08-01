#include "Teorico.h"
#include "DtInfoTeorico.h"
Teorico::Teorico(){}
Teorico::Teorico(int id,string nombre,TimeStamp inicio,Docente* docente,string codigoAsignatura):Clase(id,nombre,inicio,docente,codigoAsignatura){}
Teorico::~Teorico(){}
DtInfoClase * Teorico::getDtInfoClase()
{

    list<string> profes;
    int cantAsistentes = getAsistencias();
    map<string,Docente*> docentes=getDocentes();
    for (map<string, Docente *>::iterator it = docentes.begin(); it != docentes.end(); ++it)
    {
        profes.push_back(it->second->getNombre());
    }

    DtInfoTeorico *dtic = new DtInfoTeorico(getId(), getNombre(), profes,cantAsistentes);
    return dtic;
}

