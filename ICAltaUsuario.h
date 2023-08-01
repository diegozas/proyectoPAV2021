#ifndef ICALTAUSUARIO_H
#define ICALTAUSUARIO_H
#include "DtUsuario.h"
class ICAltaUsuario{
    public:
        virtual void ingresarDatosPerfil(DtUsuario dtUsuario)=0;
        virtual void ingresarEstudiante(string doc)=0;
        virtual void ingresarDocente(string inst)=0;
        virtual void cancelar()=0;
        virtual void cargarDatos()=0;
};
#endif
