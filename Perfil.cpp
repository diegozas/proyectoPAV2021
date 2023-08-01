#include "Perfil.h"

Perfil::Perfil(){}

Perfil::Perfil(string nombre,string imagen,string email,string password){
    this->nombre=nombre;
    this->imagenURL=imagen;
    this->email=email;
    this->password=password;
}

void Perfil::setNombre(string nombre){
    this->nombre=nombre;
}
void Perfil::setImagen(string imagen){
    this->imagenURL=imagen;
}
void Perfil::setPassword(string password){
    this->password=password;
}
void Perfil::setEmail(string email){
    this->email=email;
}

string Perfil::getNombre(){
    return this->nombre;
}
string Perfil::getImagen(){
    return this->imagenURL;
}
string Perfil::getEmail(){
    return this->email;
}
string Perfil::getPassword(){
    return this->password;
}

DtUsuario Perfil::getDtPerfil(){
    DtUsuario respuesta = DtUsuario(this->getNombre(),this->getEmail(),this->getPassword(),this->getImagen());
    return respuesta;
}
Perfil::~Perfil(){}
