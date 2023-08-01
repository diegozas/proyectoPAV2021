//MANEJADORCLASE_H.
//Declaracion de la clase ManejadorClase
//Se implementa Singleton
//Operaciones se definen en ManejadorClase.cpp

#ifndef MANEJADORCLASE_H
#define MANEJADORCLASE_H
#include <map>
#include <list>
#include <string>
#include "Clase.h"
#include "Perfil.h"
#include "Teorico.h"
#include "Monitoreo.h"
#include "Practico.h"
using namespace std;

class ManejadorClase{
    private:
        static ManejadorClase* instance;
        std::map<int,Clase*> clases;
        
        //Constructor
        ManejadorClase();

    public:
        //Instancia de clase
        static ManejadorClase* getInstance();
        
        //Destructor
        ~ManejadorClase();
        
        //funciones
        void agregarClase(Clase * clase);      //Agrega una Clase a la coleccion de Clases
        void removerClase(Clase * clase);     //Remueve una Clase de la coleccion de Clases

        //funciones get
        std::list<Clase*> getClases();             //retorna todas las Clases del sistema
        Clase * getClase(int id);     //retorna una Clase por id
        bool existeClase(int id);        //retorna true si existe una clase por id
};
#endif //MANEJADORPERFIL_H
