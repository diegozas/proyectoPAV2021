#ifndef CALTAASIGNATURA
#define CALTAASIGNATURA
#include <iostream>
#include "ICAltaAsignatura.h"
#include "DtAsignatura.h"
#include "Asignatura.h"
#include "ManejadorAsignatura.h"
using namespace std;
class CAltaAsignatura:public ICAltaAsignatura{
    private:
          DtAsignatura datos;
    public:
        CAltaAsignatura();
        ~CAltaAsignatura();
        DtAsignatura ingresar(DtAsignatura datosAsignatura);
        void altaAsignatura();
        void cancelar();
        void setDatos(DtAsignatura);
        void cargarDatos();
};

#endif