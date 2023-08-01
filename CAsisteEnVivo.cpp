#include "CAsisteEnVivo.h"
CAsisteEnVivo::CAsisteEnVivo() {}
CAsisteEnVivo::~CAsisteEnVivo() {}

list<string> CAsisteEnVivo::asignaturasInscripto(string email){
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    list<string> asignado;
    this->p = mp->getPerfil(email);
    if (Estudiante *e = dynamic_cast<Estudiante *>(p))
    {
        asignado = e->asignaturasInscripto();
    }
    return asignado;
}
list<int> CAsisteEnVivo::clasesOnlineDisplonibles(string codigo){
    this->codigo = codigo;
    list<int> clases;
    ManejadorAsignatura *ma = ManejadorAsignatura::getInstancia();
    Asignatura *a = ma->obtenerAsignatura(codigo);
    clases = a->clasesOnline();
    return clases;
}
DtAsistir CAsisteEnVivo::selectClase(int id){
    DtAsistir dta;
    this->id = id;
    dta = DtAsistir(this->codigo, id);
    return dta;
}
void CAsisteEnVivo::asistirClaseVivo(){
    ManejadorClase *mc = ManejadorClase::getInstance();
    time_t now = time(0);
    tm *time = localtime(&now);
    Fecha f = Fecha(time->tm_mday, time->tm_mon + 1, time->tm_year + 1900);
    TimeStamp t = TimeStamp(f, time->tm_hour, time->tm_min, time->tm_sec);
    TimeStamp t1 = TimeStamp(f, time->tm_hour, time->tm_min, time->tm_sec);
    Clase *c = mc->getClase(this->id);    
    if (Monitoreo *m = dynamic_cast<Monitoreo *>(c)){
        Estudiante *e = dynamic_cast<Estudiante *>(this->p);
        if (e->getHabilitado()){
            AsistenteEnVivo *a1 = new AsistenteEnVivo(t, t1, e);
            c->agregarAsistencia(a1);
            e->setHabilitado(false);
            cout << "Se ingreso la Asistencia del Estudiante " << this->p->getEmail() << " en la clase " << c->getId() << " correctamente" << endl;
            cout << "Presione ENTER para continuar" << endl;
            system("read X");
        }else{
            cout << "El estudiante no esta habilitado para esta clase" << endl;
            cout << "Presione ENTER para continuar" << endl;
            system("read X");
        }
    }else{
        if (Estudiante *e = dynamic_cast<Estudiante *>(this->p)){
            AsistenteEnVivo *a1 = new AsistenteEnVivo(t, t1, e);
            c->agregarAsistencia(a1);
            cout << "Se ingreso la Asistencia del Estudiante " << this->p->getEmail() << " en la clase " << c->getId() << " correctamente" << endl;
            cout << "Presione ENTER para continuar" << endl;
            system("read X");
        }
    }
}


list<string> CAsisteEnVivo::getEmailsEstudiantes(){
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    list<Perfil *> perfiles = mp->getPerfiles();
    list<string> correos;
    for (list<Perfil*>::iterator it=perfiles.begin();it!=perfiles.end();++it){
        if(Estudiante *d = dynamic_cast<Estudiante *>(*it)){
            correos.push_back(d->getEmail());
        }
        
    }
    return correos;
}

void CAsisteEnVivo::cancelar() {}