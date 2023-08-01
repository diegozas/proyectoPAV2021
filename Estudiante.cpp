#include "Estudiante.h"

#include "ManejadorAsignatura.h"

//ManejadorAsignatura * ma=ManejadorAsignatura::getInstancia();

Estudiante::Estudiante() {}
Estudiante::Estudiante(string nombre, string imagen, string email, string password, string documento) : Perfil(nombre, imagen, email, password)
{
    this->documento = documento;
    this->habilitado = false;
}
void Estudiante::setDocumento(string documento)
{
    this->documento = documento;
}
string Estudiante::getDocumento()
{
    return this->documento;
}
Estudiante::~Estudiante() {}

bool Estudiante::tieneAsignatura(string codigo)
{
    map<string, Asignatura *>::iterator it = this->asignaturas.find(codigo);
    if (it != asignaturas.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Estudiante::agregarAsignatura(Asignatura *a)
{
    asignaturas.insert(std::pair<string, Asignatura *>(a->getCodigo(), a));
}

list<string> Estudiante::asignaturasInscripto()
{
    list<string> inscripto;
    for (map<string, Asignatura *>::iterator it = this->asignaturas.begin(); it != this->asignaturas.end(); ++it)
    {
        inscripto.push_back(it->first);
    }
    return inscripto;
}
void Estudiante::setHabilitado(bool h) {
    this->habilitado=h;
}
bool Estudiante::getHabilitado() {
    return this->habilitado;
}

bool Estudiante::estaInscripto(string codigo)
{
    bool estaInscripto = false;
    for (map<string, Asignatura *>::iterator it = this->asignaturas.begin(); it != this->asignaturas.end(); ++it)
    {
        if (it->first == codigo)
        {
            estaInscripto = true;
        }
    }
    return estaInscripto;
}

void Estudiante::eliminarAsignatura(string codigo)
{
    map<string, Asignatura *>::iterator it = this->asignaturas.find(codigo);
    if (it != asignaturas.end())
    {
        asignaturas.erase(it);
    }
}
