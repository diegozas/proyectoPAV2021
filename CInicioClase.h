#ifndef CINICIOCLASE_H
#define CINICIOCLASE_H
#include "ICInicioClase.h"
#include "Docente.h"
#include "DtIniciarClase.h"
class CInicioClase:public ICInicioClase{
    private:
        Docente * docente;
        DtIniciarClase ic;
        DtIniciarClaseFull data;
        list<string>habilitados;//HABILITADOS MONITOREO
        
        Rol *obtenerRolEnAsignaturaSeleccionada();
        Clase* crearClaseSegunTipo(TipoRol);
    public:
        CInicioClase();
        ~CInicioClase();
        list <string> asignaturasAsignadas(string);
        bool selectAsignatura(DtIniciarClase);
        list <string> inscriptosAsignaturas();        
        void habilitar(string);
        DtIniciarClaseFull datosIngresados();
        void iniciarClase();
        void cancelar();//Nuevo
        list<string> getEmailsDocentes();
        void cargarDatos();
};

#endif