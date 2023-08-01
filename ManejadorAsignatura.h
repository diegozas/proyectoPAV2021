#ifndef MANEJADORASIGNATURA_H
#define MANEJADORASIGNATURA_H

#include "Asignatura.h"
#include <map>
#include <list>
#include <string>

class ManejadorAsignatura{
    private:
        map<string,Asignatura*> coleccionAsignaturas;
        static ManejadorAsignatura* instancia;
        ManejadorAsignatura();
    public:
        static ManejadorAsignatura* getInstancia();
        map<string,Asignatura*> listarAsignaturas();
        Asignatura* obtenerAsignatura(string);
        bool existeAsignatura(string); 
        void borrarAsignatura(string);
        void agregarAsignatura(Asignatura*);
        virtual ~ManejadorAsignatura();
        list<string> codigoAsignaturas();

};



#endif