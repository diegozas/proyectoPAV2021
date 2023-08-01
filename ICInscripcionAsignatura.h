#ifndef ICINSCRIPCIONASIGNATURA
#define ICINSCRIPCIONASIGNATURA
#include <string>
#include <list>
using namespace std;
class ICInscripcionAsignatura{
    public:
        virtual list<string> asignaturaNoInscripto(string)=0;
        virtual void selectAsignatura(string)=0;
        virtual void inscribir()=0;
        virtual void cancelar()=0;
        virtual list<string> getEmailsEstudiantes()=0;
        virtual void cargarDatos()=0;
};


#endif