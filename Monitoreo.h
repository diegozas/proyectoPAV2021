#ifndef MONITOREO_H
#define MONITOREO_H
#include "Clase.h"
#include "Estudiante.h"
#include <map>
class Monitoreo:public Clase{
    private:
        map<string,Estudiante*> estudiantes;
    public:
        Monitoreo();
        Monitoreo(int,string,TimeStamp,Docente*,list<string>,string);
        void borrarEstudiantes();//Nuevo
        DtInfoClase * getDtInfoClase();
        ~Monitoreo();
       
};
#endif