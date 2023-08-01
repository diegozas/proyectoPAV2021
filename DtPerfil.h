#ifndef DTPERFIL_H
#define DTPERFIL_H
#include<iostream>
using namespace std;

class DtPerfil{
    private:
        string nombre;
        string imgUrl;
        string email;
        string password;
    public:
        DtPerfil();
        DtPerfil(string,string,string,string);
        string getNombre();
        string getImgUrl();
        string getEmail();
        string getPassword();
        ~DtPerfil();
};
#endif 