#ifndef ASIGNATURA_H
#define ASIGNATURA_H
#include "DtInstanciaClase.h"
#include <string>
#include <map>
#include <list>
#include "Clase.h"
using namespace std;

class Clase;
class Monitoreo;

class Asignatura{
    private:
        string codigo;
        string nombre;
        DtInstanciaClase tipoClase;
        map<int,Clase*> clases;
    public:
        Asignatura();
        Asignatura(string,string,DtInstanciaClase);
        void setCodigo(string);
        void setNombre(string);
        void setTipo(DtInstanciaClase);
        string getCodigo();
        string getNombre();
        DtInstanciaClase getTipo();
        virtual ~Asignatura();

        list<int> clasesOnline();
        void agregarClase(Clase*);
        void eliminarClaes();//Nuevo
        map<int,Clase*> getClases();//Nuevo

};


#endif
