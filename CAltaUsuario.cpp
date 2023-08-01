#include "CAltaUsuario.h"
#include <iostream>
using namespace std;

CAltaUsuario::CAltaUsuario(){}
CAltaUsuario::~CAltaUsuario(){}


void CAltaUsuario::ingresarDatosPerfil(DtUsuario dtUsuario){
	this->setDatos(dtUsuario);
	//DtUsuario datos = DtUsuario(dtUsuario.getNombre(),dtUsuario.getEmail(),dtUsuario.getContrasena(),dtUsuario.getUrlImg());
	//return datos;
}

void CAltaUsuario::ingresarEstudiante(string doc){
	ManejadorPerfil* mP = ManejadorPerfil::getInstance();
	bool existe= mP->existePerfil(this->datos.getEmail());
	if(existe){
        	throw invalid_argument ("ERROR:YA EXISTE UN USUARIO CON ESE EMAIL EN EL SISTEMA!"); 
    	}else{
		Estudiante *e= new Estudiante(this->datos.getNombre(),this->datos.getUrlImg(),this->datos.getEmail(),this->datos.getContrasena(),doc);
    		mP->agregarPerfil(e);
			cout<<"Se agrego el Estudiante correctamente"<<endl;
			cout<<"Presione ENTER para continuar"<<endl;
			system("read X");
    	}
}

void CAltaUsuario::ingresarDocente(string inst){
	ManejadorPerfil* mP = ManejadorPerfil::getInstance();
	bool existe= mP->existePerfil(this->datos.getEmail());
	if(existe){
        	throw invalid_argument ("ERROR:YA EXISTE UN USUARIO CON ESE EMAIL EN EL SISTEMA"); 
    	}else{
		Docente *d= new Docente(this->datos.getNombre(),this->datos.getUrlImg(),this->datos.getEmail(),this->datos.getContrasena(), inst);
    		mP->agregarPerfil(d);
			cout<<"Se agrego el Docente correctamente"<<endl;
			cout<<"Presione ENTER para continuar"<<endl;
			system("read X");
    	}
}

void CAltaUsuario::cancelar(){}

void CAltaUsuario::setDatos(DtUsuario dtUsuario){
    this->datos=dtUsuario;
}






void CAltaUsuario::cargarDatos(){
	ManejadorPerfil*mp=ManejadorPerfil::getInstance();
	Estudiante* e=new Estudiante("Diego","asd","1","12","4936354");
    Estudiante* e1=new Estudiante("Diego","asd","2","12","4936354");
    Docente* d=new Docente("Prueba","algo","3","12","no existe");
	Docente* d1=new Docente("Prueba","algo","4","12","no existe");
	mp->agregarPerfil(e);
	mp->agregarPerfil(e1);
	mp->agregarPerfil(d);
	mp->agregarPerfil(d1);
}
