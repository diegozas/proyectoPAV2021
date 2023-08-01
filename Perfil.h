#ifndef PERFIL_H
#define PERFIL_H
#include <string>
#include "DtUsuario.h"
using namespace std;

class Perfil{
    private:
        string nombre;
        string imagenURL;
        string email;
        string password;
    public:
        Perfil();
        Perfil(string,string,string,string);
        void setNombre(string);
        void setImagen(string);
        void setPassword(string);
        void setEmail(string);
        string getNombre();
        string getImagen();
        string getEmail();
        string getPassword();
	DtUsuario getDtPerfil();
       	virtual ~Perfil();
};
#endif
