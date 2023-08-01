#include"DtPerfil.h"

using namespace std;

DtPerfil::DtPerfil(){};
DtPerfil::DtPerfil(string nombre,string imgUrl,string email,string password){
    this->nombre=nombre;
    this->imgUrl=imgUrl;
    this->email=email;
    this->password=password;
}

string DtPerfil::getNombre(){
    return this->nombre;
}

string DtPerfil::getImgUrl(){
    return this->imgUrl;
}

string DtPerfil::getEmail(){
    return this->email;
}

string DtPerfil::getPassword(){
    return this->password;
}

