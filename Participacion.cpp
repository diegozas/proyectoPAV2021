#include "Participacion.h"

Participacion::Participacion(){}

Participacion::Participacion(int id, TimeStamp fecha, string mensaje,Perfil* p){
	this->id=id;
	this->fecha=fecha;
	this->mensaje=mensaje;
	this->perfil=p;
	this->responde=NULL;
}

void Participacion::setId(int id){
	this->id=id;
}

void Participacion::setFecha(TimeStamp fecha){
	this->fecha=fecha;
}

void Participacion::setMensaje(string mensaje){
	this->mensaje=mensaje;
}

void Participacion::setPerfil(Perfil* p){
	this->perfil=p;
}

int Participacion::getId(){
	return this->id;
}

TimeStamp Participacion::getFecha(){
	return this->fecha;
}

string Participacion::getMensaje(){
	return this->mensaje;
}

Perfil* Participacion::getPerfil(){
	return this->perfil;
}

Participacion::~Participacion(){}



DtParticipacion* Participacion::getDtParticipacion(){
	DtParticipacion*dt;
	DtParticipacion*dtr;
	if(this->responde==NULL){
		dt=new DtParticipacion(this->id,this->fecha,this->mensaje,this->perfil->getEmail());
	}else if(this->responde!=NULL){
		dtr=new DtParticipacion(this->responde->getId(),this->responde->getFecha(),this->responde->getMensaje(),this->responde->getPerfil()->getEmail());
		dt=new DtParticipacion(this->id,this->fecha,this->mensaje,this->perfil->getEmail(),dtr);
		
	}
	return dt;

}


Participacion* Participacion::getResponde(){
	return this->responde;
}


	


void Participacion::agregarRespuesta(Participacion* p){
	this->responde=p;
}