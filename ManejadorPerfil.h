//MANEJADORPERFIL_H.
//Declaracion de la clase ManejadorPerfil
//Se implementa Singleton
//Operaciones se definen en ManejadorPerfil.cpp

#ifndef MANEJADORPERFIL_H
#define MANEJADORPERFIL_H
#include <map>
#include <list>
#include <string>
#include "Perfil.h"
#include "Estudiante.h"
#include "Docente.h"

class ManejadorPerfil{
    private:
        static ManejadorPerfil* instance;
        std::map<std::string,Perfil*> perfiles;
        
        //Constructor
        ManejadorPerfil();

    public:
        //Instancia de clase
        static ManejadorPerfil* getInstance();
        
        //Destructor
        ~ManejadorPerfil();
        
        //funciones
        void agregarPerfil(Perfil * perfil);      //Agrega un Perfil a la coleccion de Perfiles
        void removerPerfil(Perfil * perfil);      //Remueve un Perfil de la coleccion de Perfiles

        //funciones get
        std::list<Perfil*> getPerfiles();             //retorna todos los Perfiles del sistema
        Perfil * getPerfil(std::string email);     //retorna un Perfil por email
        bool existePerfil(std::string email);        //retorna true si existe un perfil por email
        map<string,Estudiante*> obtenerMapEstudiantes(list<std::string>);
};
#endif //MANEJADORPERFIL_H
