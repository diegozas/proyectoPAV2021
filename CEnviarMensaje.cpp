#include "CEnviarMensaje.h"

CEnviarMensaje::CEnviarMensaje() {}
CEnviarMensaje::~CEnviarMensaje() {}

list<int> CEnviarMensaje::clasesOnlineAsistiendo(string email){
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    ManejadorClase *mc = ManejadorClase::getInstance();
    Perfil *p = mp->getPerfil(email);
    this->perfil = p;
    list<Clase*> clases;
    list<int> participa;
    list<AsistenteEnVivo *> asiste;
    clases = mc->getClases();
    if (Estudiante *e = dynamic_cast<Estudiante *>(this->perfil)){
        for (list<Clase *>::iterator it = clases.begin(); it != clases.end(); ++it){
            asiste = (*it)->getAsistencia(); //guarda el list de asiste en vivo que tiene
                                             //la clase que apunta el iterator it en ese momento
            for (list<AsistenteEnVivo *>::iterator it2 = asiste.begin(); it2 != asiste.end(); ++it2){
                //pregunta por cada AsisteEnVivo si tiene el estudiante
                if ((*it2)->getEstudiante()->getEmail() == e->getEmail()){
                    participa.push_back((*it)->getId());
                }
            }
        }
    }else if (Docente *d = dynamic_cast<Docente *>(this->perfil)){
        for (list<Clase *>::iterator it = clases.begin(); it != clases.end(); ++it){
            if ((*it)->existeDocente(d->getEmail())){
                participa.push_back((*it)->getId());
            }
        }
    }

    return participa;
}

list<DtParticipacion *> CEnviarMensaje::selectClase(int clase){
    ManejadorClase *mc = ManejadorClase::getInstance();
    this->participacion = 0;
    this->clase = clase;
    Clase *c = mc->getClase(clase);
    list<DtParticipacion *> participa;
    map<int, Participacion *> p;
    p = c->getColeccionParticipacion();
    DtParticipacion *dt;
    for (map<int, Participacion *>::iterator it = p.begin(); it != p.end(); ++it){
        dt = it->second->getDtParticipacion();
        participa.push_back(dt);
    }
    return participa;
}

void CEnviarMensaje::responder(int participacion){
    this->participacion = participacion;
}

void CEnviarMensaje::ingresarTexto(string texto){
    this->texto = texto;
}


void CEnviarMensaje::enviar(){
    //se crea un TimeStamp con hora y fecha del sistema
    time_t now = time(0);
    tm *time1 = localtime(&now);
    Fecha f = Fecha(time1->tm_mday, time1->tm_mon + 1, time1->tm_year + 1900);
    TimeStamp t = TimeStamp(f, time1->tm_hour, time1->tm_min, time1->tm_sec);
    //------------------------------------------------------------------------------------
    ManejadorClase *mc = ManejadorClase::getInstance();
    Clase *c = mc->getClase(this->clase);  
    int id = c->getCantParticipaciones()+1;
    if (this->participacion == 0){
        //entra en este if si el usuario quiere crear una participacion nueva 
        Participacion *p = new Participacion(id, t, this->texto, this->perfil);
        c->agregarParticipacion(p);
        cout << "Se agrego la Participacion con ID: " << id << " del Usuario: " << this->perfil->getEmail() << " Correctamente" << endl;
        cout << "Presione ENTER para continuar" << endl;
        system("read X");
    }else if (this->participacion != 0){
        //este if es para cuando el usuario quiere responder a una participacion

        Participacion *p1 = c->getParticipacion(this->participacion);
        Participacion *p2 = new Participacion(id, t, this->texto, this->perfil);
        p1->agregarRespuesta(p2);
        c->agregarParticipacion(p2);
        cout << "Se agrego la respuesta del usuario: " << this->perfil->getEmail() << " en la participacion " << this->participacion << " correctamente" << endl;
        cout << "Presione ENTER para continuar" << endl;
        system("read X");
    }
}

list<string> CEnviarMensaje::getEmails(){
    ManejadorPerfil *mp = ManejadorPerfil::getInstance();
    list<Perfil *> perfiles = mp->getPerfiles();
    list<string> correos;
    for (list<Perfil *>::iterator it = perfiles.begin(); it != perfiles.end(); ++it){
        correos.push_back((*it)->getEmail());
    }
    return correos;
}

void CEnviarMensaje::cancelar() {}