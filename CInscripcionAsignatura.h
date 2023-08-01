#ifndef CINSCRIPCIONASIGNATURA
#define CINSCRIPCIONASIGNATURA
#include "ICInscripcionAsignatura.h"
#include <list>
#include <map>
#include "Estudiante.h"
#include "Perfil.h"
#include "ManejadorAsignatura.h"
#include "ManejadorPerfil.h"
#include <iostream>
using namespace std;
class CInscripcionAsignatura:public ICInscripcionAsignatura{
    private:
        map<string,Asignatura*> asignaturas;
        string codigo;
        Perfil* p;
    public:
        CInscripcionAsignatura();
        ~CInscripcionAsignatura();
        list<string> asignaturaNoInscripto(string);
        void selectAsignatura(string);
        void inscribir();
        void cancelar();
        list<string> getEmailsEstudiantes();
        void cargarDatos();
};

#endif