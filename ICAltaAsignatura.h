#ifndef ICALTAASIGNATURA_H
#define ICALTAASIGNATURA_H
#include "DtAsignatura.h"
class ICAltaAsignatura{
    public:
        virtual DtAsignatura ingresar(DtAsignatura datosAsignatura)=0;
        virtual void altaAsignatura()=0;
        virtual void cancelar()=0;
        virtual void cargarDatos()=0;
};

#endif