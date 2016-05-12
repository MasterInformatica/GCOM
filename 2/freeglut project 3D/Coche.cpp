#include "Coche.h"
#include <iostream>
#include "Cubo.h"
//#include "Cilindro.h"
//#include "DiscoParcial.h"
//#include "Disco.h"
#include "Rueda.h"
#include "Faro.h"

Coche::Coche(GLfloat size) {
	this->desplazamiento = 0;
	this->giro = 0;
	this->angRuedas = 0;
	// guardo y calculo atributos
	this->size = size;
	this->radioRuedas = this->size / 3.0f;
	this->anchoRuedas = this->radioRuedas;
	this->radioFocos = this->radioRuedas*0.4;
	this->anchoFocos = this->size*0.2;
	//carroceria
	Cubo *carroceria = new Cubo(this->size);
	carroceria->setColor(1.0f, 0.0f, 1.0f);
	carroceria->traslada(0.0f, radioRuedas+(size/2.0), 0.0f);
	introduceObjeto(carroceria);
	
	// ruedas
	Rueda* rueda;
	{	//delantera derecha
		rueda = new Rueda(radioRuedas, anchoRuedas);
		rueda->traslada(0.5*size, radioRuedas, 0.5*size);
		posRuedas[0] = elementos->size();
		introduceObjeto(rueda);
	}
	{	//delantera izquierda
		rueda = new Rueda(radioRuedas, anchoRuedas);
		rueda->traslada(0.5*size, radioRuedas, -0.5*size);
		posRuedas[1] = elementos->size();
		introduceObjeto(rueda);
	}
	{	//trasera derecha
		rueda = new Rueda(radioRuedas, anchoRuedas);
		rueda->traslada(-0.5*size, radioRuedas, 0.5*size);
		posRuedas[2] = elementos->size();
		introduceObjeto(rueda);
	}
	{	//trasera izquierda
		rueda = new Rueda(radioRuedas, anchoRuedas);
		rueda->traslada(-0.5*size, radioRuedas, -0.5*size);
		posRuedas[3] = elementos->size();
		introduceObjeto(rueda);
	}

	//faro
	Faro* faro;
	{	//derecho
		faro = new Faro(radioFocos, 0.3f*radioFocos, anchoFocos);
	
		faro->traslada(0.5*size + anchoFocos/2.0, size, 0.3*size);
		faro->rota(90.0f, 0.0f, 1.0f, 0.0f);

		introduceObjeto(faro);
	}
	{	//izquierdo
		faro = new Faro(radioFocos , 0.3f*radioFocos, anchoFocos);

		faro->traslada(0.5*size + anchoFocos / 2.0, size, -0.3*size);
		faro->rota(90.0f, 0.0f, 1.0f, 0.0f);
		
		introduceObjeto(faro);
	}

}




void Coche::mover(float x) {
	float X = x * 0.05;
	desplazamiento += X;	// lo guardamos por "herencia" de cocheViejo
							// en realidad no hace falta porque TAfin acumula todos
							// los desplazamientos que realizamos

	for (int i = 0; i < 4; i++){ //las ruedas estan en elementos[posRuedas(i)] 
		elementos->at(posRuedas[i])->rota(-15.0*X, 0.0f, 0.0f, 1.0f); //at(i) == get(i) //java
	}

	float andRd = angRuedas * 6.28 / 360.0;
	float mv = size*5;
	if (angRuedas > 0)
		mv = size *-1.0;
	float distCentro = sin(-andRd)*X / (sin(3.14 - (andRd * 2))) + mv;
	traslada(0.0f, 0.0f, distCentro*(1 - (angRuedas/30.0)));
	rota(x*angRuedas, 0.0f, 1.0f, 0.0f);
	traslada(0.0f, 0.0f, -1.0*distCentro*(1 - (angRuedas / 30.0)));
	traslada(X*cos(-1.0*andRd), 0.0f, X*sin(-1.0*andRd));
	//traslada(X,0.0f,0.0f); //sin giro, solo hacia delante
	giro += angRuedas;
	
}

void Coche::girar(float x) {
	float X = x * 3;
	if (angRuedas < -29 && X < 0)
		return;
	if (angRuedas > 29 && X > 0)
		return;
	angRuedas += X;

	elementos->at(posRuedas[0])->rota(15.0*desplazamiento, 0.0f, 0.0f, 1.0f);
	elementos->at(posRuedas[0])->rota(X, 0.0f, 1.0f, 0.0f);
	elementos->at(posRuedas[0])->rota(-15.0*desplazamiento, 0.0f, 0.0f, 1.0f);

	elementos->at(posRuedas[1])->rota(15.0*desplazamiento, 0.0f, 0.0f, 1.0f);
	elementos->at(posRuedas[1])->rota(X, 0.0f, 1.0f, 0.0f);
	elementos->at(posRuedas[1])->rota(-15.0*desplazamiento, 0.0f, 0.0f, 1.0f);

}


Coche::~Coche() {

}
