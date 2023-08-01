#ifndef ICINICIOCLASE_H
#define ICINICIOCLASE_H
#include <list>
#include <string>
#include "DtIniciarClase.h"
#include "DtIniciarClaseFull.h"
#include "Estudiante.h"
using namespace std;
class ICInicioClase{
    public:
            virtual list <string> asignaturasAsignadas(string) = 0;
            virtual bool selectAsignatura(DtIniciarClase) = 0;
            virtual list <string> inscriptosAsignaturas() = 0;            
            virtual void habilitar(string) = 0;
            virtual DtIniciarClaseFull datosIngresados() = 0;
            virtual void iniciarClase() = 0;
            virtual void cancelar() = 0; // nuevo
            virtual list<string> getEmailsDocentes()=0;
            virtual void cargarDatos()=0;
            
};

#endif