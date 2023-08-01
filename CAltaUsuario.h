#ifndef CALTAUSUARIO_H
#define CALTAUSUARIO_H
#include <iostream>
#include "ICAltaUsuario.h"
#include "DtUsuario.h"
#include "Perfil.h"
#include "ManejadorPerfil.h"
using namespace std;

class CAltaUsuario:public ICAltaUsuario{
    private:
          DtUsuario datos;
    public:
        CAltaUsuario();
        ~CAltaUsuario();
        void ingresarDatosPerfil(DtUsuario dtUsuario);
        void ingresarEstudiante(string doc);
        void ingresarDocente(string inst);
        void cancelar();
        void setDatos(DtUsuario);
        void cargarDatos();
};
#endif


