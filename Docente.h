#ifndef DOCENTE
#define DOCENTE
#include "Perfil.h"
#include <list>
#include <string>
#include "Asignatura.h"
#include "Rol.h"
using namespace std;
class Rol;
class Docente:public Perfil{
    private:
        string instituto;
        list<Rol*> roles;
    public:
        Docente();
        Docente(string,string,string,string,string);
        void setInstituto(string);
        string getInstituo();
        list<string>asignaturas(); // NUEVO devuelves todas las asignaturas
        bool tieneMonitoreo(string);//NUEVO
        bool noDictaAsignatura(string);//NUEVO
        void addRol(Rol*);//NUEVO
        list<Rol*>getRoles();
        ~Docente();
        void eliminarAsignatura(string);//NUEVO
};

#endif