//FABRICA_H.
//Declaracion de la clase FABRICA
//Se implementa Singleton
//Operaciones se definen en FABRICA.cpp

#ifndef FABRICA_H
#define FABRICA_H

#include "ICAltaAsignatura.h"
#include "CAltaAsignatura.h"

#include "ICAsisteEnVivo.h"
#include "CAsisteEnVivo.h"

#include "ICInscripcionAsignatura.h"
#include "CInscripcionAsignatura.h"

#include "ICEnviarMensaje.h"
#include "CEnviarMensaje.h"

#include "ICAltaUsuario.h"
#include "CAltaUsuario.h"

#include "ICAsignarAsignaturaDocente.h"
#include "CAsignarAsignaturaDocente.h"

#include "ICInicioClase.h"
#include "CInicioClase.h"


#include "ICEliminarAsignatura.h"
#include "CEliminarAsignatura.h"


#include "ICListadoClase.h"
#include "CListadoClases.h"

#include <iostream>

//definicion de tipo abstracto de datos FABRICA
class Fabrica{

    private:
        static Fabrica* instance;

        //Constructores
        Fabrica();
    
    public:
        
        //Destructor
        ~Fabrica();
        
        //Instancia de clase
        static Fabrica* getInstance();
        
        //obtener controladores
        //IPerfil* getIPerfil();
        ICAltaAsignatura* getICAltaAsignatura();
        ICAsisteEnVivo* getICAsisteEnVivo();
        ICInscripcionAsignatura* getICInscripcionAsignatura();
        ICEnviarMensaje* getICEnviarMensaje();
        ICAltaUsuario* getICAltaUsuario();
        ICAsingarAsignaturaDocente* getICAsignarAsignaturaDocente();
        ICInicioClase* getICInicioClase();
        ICEliminarAsignatura * getICEliminarAsignatura();
        ICListadoClase * getICListadoClase();
};

#endif //FABRICA_H
