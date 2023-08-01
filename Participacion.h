#ifndef PARTICIPACION_H
#define PARTICIPACION_H
#include "TimeStamp.h"
#include "Perfil.h"
#include "DtParticipacion.h"
#include <list>
#include <string>
using namespace std;

class Participacion{
	private:
		int id;
		TimeStamp fecha;
		string mensaje;
		Perfil* perfil;
		//list<DtParticipacion> responde;
		Participacion* responde;

	public:
		Participacion();
		Participacion(int,TimeStamp,string,Perfil*);
		void setId(int);
		void setFecha(TimeStamp);
		void setMensaje(string);
		void setPerfil(Perfil*);
		int getId();
		TimeStamp getFecha();
		string getMensaje();
		Perfil* getPerfil();
		~Participacion();
		
		void agregarRespuesta(Participacion*);
		DtParticipacion* getDtParticipacion();
		Participacion* getResponde();

};

#endif