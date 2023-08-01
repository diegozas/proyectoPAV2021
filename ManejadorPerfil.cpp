//ManejadorPerfil.cpp
//Definicion de operaciones de la clase ManejadorPerfil
#include "ManejadorPerfil.h"

//constructor
ManejadorPerfil::ManejadorPerfil(){
}

//Instancia de clase
ManejadorPerfil* ManejadorPerfil::instance = NULL;

//Instancia de clase
ManejadorPerfil* ManejadorPerfil::getInstance(){
    if (instance == NULL)
        instance = new ManejadorPerfil();
    return instance;
}
        
//Destructor
ManejadorPerfil::~ManejadorPerfil(){
}

//funciones
//Agrega un Perfil a la coleccion de Perfiles
void ManejadorPerfil::agregarPerfil(Perfil * perfil){
    perfiles.insert(std::pair<std::string,Perfil*>(perfil->getEmail(),perfil));
}      

//Remueve un Perfil de la coleccion de Perfiles
void ManejadorPerfil::removerPerfil(Perfil * perfil){
    std::map<std::string,Perfil*>::iterator it = this->perfiles.find(perfil->getEmail());
    this->perfiles.erase(it);
}      


//funciones get
//retorna todos los Perfiles del sistema
std::list<Perfil*> ManejadorPerfil::getPerfiles(){
    std::list<Perfil*> Perfiles;
    for (std::map<std::string, Perfil*>::iterator it=this->perfiles.begin(); it!=this->perfiles.end(); ++it)
        Perfiles.push_back(it->second);
    return Perfiles;
}            

//retorna un Perfil         
Perfil * ManejadorPerfil::getPerfil(std::string email){
    std::map<std::string,Perfil*>::iterator it = this->perfiles.find(email);
    return it->second;
}    

 //retorna true si existe un perfil con ese email
bool ManejadorPerfil::existePerfil(std::string email){
    std::map<std::string,Perfil*>::iterator it = this->perfiles.find(email);
    return (it != this->perfiles.end());
}


map<string,Estudiante*> ManejadorPerfil::obtenerMapEstudiantes(list<std::string> emails){
    map<std::string,Estudiante*> estudiantes;
    for(list<std::string>::iterator it=emails.begin();it!=emails.end();++it){
        Perfil *perfil=this->getPerfil(it->c_str());
        Estudiante* estudiante=dynamic_cast<Estudiante*> (perfil);        
        if(estudiante!=NULL){
            estudiantes.insert(std::pair<string,Estudiante*>(estudiante->getEmail(),estudiante));    
        }
    }
    return estudiantes;
}
