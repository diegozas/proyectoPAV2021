#ifndef DTUSUARIO_H
#define DTUSUARIO_H
#include<iostream>
using namespace std;

class DtUsuario{
    private:
        string nombre;
        string email;
        string contrasena;
        string urlImg;
    public:
        DtUsuario();
        DtUsuario(string,string,string,string);
        string getNombre();
        string getEmail();
        string getContrasena();
        string getUrlImg();
        ~DtUsuario();
};
#endif 
