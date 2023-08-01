#ifndef CELIMINARASIGNATURA_H
#define CELIMINARASIGNATURA_H


#include "ManejadorAsignatura.h"
#include "ManejadorPerfil.h"
#include "ManejadorClase.h"
#include "ICEliminarAsignatura.h"

class CEliminarAsignatura:public ICEliminarAsignatura{
    private:
        string codigo;
    public:
        CEliminarAsignatura();
        ~CEliminarAsignatura();
        list<string> listarAsignaturas();
        void selectAsignatura(string);
        void eliminarAsignatura();
        void cancelar();

};

#endif