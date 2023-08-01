#include"DtUsuario.h"

using namespace std;

DtUsuario::DtUsuario(){};
DtUsuario::DtUsuario(string nombre,string email, string contrasena, string urlImg){
    this->nombre=nombre;
    this->email=email;
    this->contrasena=contrasena;
    this->urlImg=urlImg;
}

string DtUsuario::getNombre(){
    return this->nombre;
}

string DtUsuario::getEmail(){
    return this->email;
}

string DtUsuario::getContrasena(){
    return this->contrasena;
}

string DtUsuario::getUrlImg(){
    return this->urlImg;
}

DtUsuario::~DtUsuario(){}





