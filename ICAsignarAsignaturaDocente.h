#ifndef ICASIGNARASIGNATURADOCENTE_H
#define ICASIGNARASIGNATURADOCENTE_H

#include<iostream>
#include<list>
#include "DtInstanciaClase.h"
#include"TipoRol.h"
using namespace std;

class ICAsingarAsignaturaDocente{
    public:
        virtual list<string> listarAsignaturas()=0;
        virtual list<string> docentesSinLaAsignatura(string)=0;
        virtual void selectDocente(TipoRol,string)=0;
        virtual void asignarDocente()=0;
        virtual DtInstanciaClase getInstancias()=0;
        virtual void cargarDatos()=0;
};
#endif 