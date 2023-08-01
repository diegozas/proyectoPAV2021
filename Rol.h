#ifndef ROL_H
#define ROl_H
#include "TipoRol.h"
//#include "Asignatura.h"

class Asignatura;

class Rol{
    private:
        Asignatura* asignatura;
        TipoRol rol;
    public:
        Rol();
        Rol(Asignatura*,TipoRol);
        void setTipoRol(TipoRol);
        void setAsignatura(Asignatura*);
        Asignatura* getAsignatura();
        TipoRol getTipoRol();
        ~Rol();
};




#endif
