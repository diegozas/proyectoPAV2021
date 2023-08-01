#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H
#include "Perfil.h"
#include "Asignatura.h"
#include <string>
#include <map>
#include <list>
using namespace std;
class Estudiante:public Perfil{
    private:
        string documento;
        map<string,Asignatura*> asignaturas;
        bool habilitado;
    public:
        Estudiante();
        Estudiante(string,string,string,string,string);
        void setDocumento(string);
        string getDocumento();
        ~Estudiante();

        void setHabilitado(bool);
        bool getHabilitado();
        list <string> asignaturasInscripto();
        bool tieneAsignatura(string);
        void agregarAsignatura(Asignatura*);
        bool estaInscripto(string);//nuevo

        void eliminarAsignatura(string);

};







#endif