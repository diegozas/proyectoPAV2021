#ifndef CASIGNARASIGNATURADOCENTE_H
#define CASIGNARASIGNATURADOCENTE_H
#include<iostream>
#include "ICAsignarAsignaturaDocente.h"
#include "TipoRol.h"
#include "Asignatura.h"

#include<list>
#include<map>
using namespace std;

class CAsignarAsignaturaDocente:public ICAsingarAsignaturaDocente{
    private:
        map<string,Asignatura*>asignaturas;
        string codAsignatura;
        string email;
        TipoRol rol;
    public:
        CAsignarAsignaturaDocente();
        list<string> listarAsignaturas();
        list<string> docentesSinLaAsignatura(string);
        void selectDocente(TipoRol,string);
        void asignarDocente();
        DtInstanciaClase getInstancias();
        void cargarDatos();        
        ~CAsignarAsignaturaDocente();
};


#endif 