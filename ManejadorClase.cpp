//ManejadorClase.cpp
//Definicion de operaciones de la clase ManejadorClase
#include "ManejadorClase.h"

//constructor
ManejadorClase::ManejadorClase(){}

//Instancia de clase
ManejadorClase* ManejadorClase::instance = NULL;

//Instancia de clase
ManejadorClase* ManejadorClase::getInstance(){
    if (instance == NULL)
        instance = new ManejadorClase();
    return instance;
}
        
//Destructor
ManejadorClase::~ManejadorClase(){}

//funciones
//Agrega una Clase a la coleccion de Clases
void ManejadorClase::agregarClase(Clase * clase){
    clases.insert(std::pair<int,Clase*>(clase->getId(),clase));
}      

//Remueve una Clase de la coleccion de Clases
void ManejadorClase::removerClase(Clase * clase){
    std::map<int,Clase*>::iterator it = this->clases.find(clase->getId());
    this->clases.erase(it);
}      


//funciones get
//retorna todas las Clases del sistema
std::list<Clase*> ManejadorClase::getClases(){
    std::list<Clase*> Clases;
    for (std::map<int, Clase*>::iterator it=this->clases.begin(); it!=this->clases.end(); ++it)
        Clases.push_back(it->second);
    return Clases;
}            

//retorna una Clase         
Clase * ManejadorClase::getClase(int id){
    std::map<int,Clase*>::iterator it = this->clases.find(id);
    return it->second;
}
 //retorna true si existe una clase con ese id
bool ManejadorClase::existeClase(int id){
    std::map<int,Clase*>::iterator it = this->clases.find(id);
    return (it != this->clases.end());
}
