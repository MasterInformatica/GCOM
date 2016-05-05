#include "Coche.h"
#include "Cubo.h"
#include "Cilindro.h"
#include "DiscoParcial.h"
#include "Disco.h"

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
	Objeto3D* rueda;
	{	//delantera derecha
		rueda = buildRueda();
		rueda->traslada(0.5*size, radioRuedas, 0.5*size);
		posRuedas[0] = elementos->size();
		introduceObjeto(rueda);
	}
	{	//delantera izquierda

		rueda = buildRueda();
		rueda->traslada(0.5*size, radioRuedas, -0.5*size - anchoRuedas);
		posRuedas[1] = elementos->size();
		introduceObjeto(rueda);
	}
	{	//trasera derecha
		rueda = buildRueda();
		rueda->traslada(-0.5*size, radioRuedas, 0.5*size);
		posRuedas[2] = elementos->size();
		introduceObjeto(rueda);
	}
	{	//trasera izquierda
		rueda = buildRueda();
		rueda->traslada(-0.5*size, radioRuedas, -0.5*size - anchoRuedas);
		posRuedas[3] = elementos->size();
		introduceObjeto(rueda);
	}

	//faro
	Objeto3D* faro;
	{	//derecho
		faro = buildFaro();
		
		faro->traslada(0.5*size, size, 0.3*size);
		faro->rota(90.0f, 0.0f, 1.0f, 0.0f);
		introduceObjeto(faro);
	}
	{	//izquierdo
		faro = buildFaro();

		faro->traslada(0.5*size, size, -0.3*size);
		faro->rota(90.0f, 0.0f, 1.0f, 0.0f);
		introduceObjeto(faro);
	}

}


Objeto3D* Coche::buildRueda(){
	ObjetoCompuesto *rueda = new ObjetoCompuesto();
	DiscoParcial *tapa1, *tapa2;
	Cilindro *goma;
	tapa1 = new DiscoParcial(0, radioRuedas, 0.0f, 300.0f);
	tapa2 = new DiscoParcial(0, radioRuedas, 0.0f, 300.0f);
	goma = new Cilindro(radioRuedas, radioRuedas, anchoRuedas);
	tapa1->traslada(0.0f, 0.0f, anchoRuedas);
	
	rueda->introduceObjeto(goma);
	rueda->introduceObjeto(tapa1);
	rueda->introduceObjeto(tapa2);

	
	
	rueda->setColor(0.0f, 0.0f, 0.0f);
	tapa1->setColor(0.0f, 1.0f, 0.0f);
	tapa2->setColor(1.0f, 0.0f, 0.0f);
	return rueda;
}

Objeto3D* Coche::buildFaro(){
	ObjetoCompuesto *faro = new ObjetoCompuesto();
	Disco *tapa1, *tapa2;
	Cilindro *casquillo;
	tapa1 = new Disco(0, radioFocos*0.3);
	tapa2 = new Disco(0, radioFocos);
	casquillo = new Cilindro(radioFocos*0.3, radioFocos, anchoFocos);

	tapa2->traslada(0.0f, 0.0f, anchoFocos);

	faro->introduceObjeto(casquillo);
	faro->introduceObjeto(tapa1);
	faro->introduceObjeto(tapa2);

	faro->setColor(0.0f, 1.0f, 0.0f);

	return faro;
}

void Coche::mover(float x) {
	float X = x * 0.2;
	desplazamiento += X;	// lo guardamos por "herencia" de cocheViejo
							// en realidad no hace falta porque TAfin acumula todos
							// los desplazamientos que realizamos

	for (int i = 0; i < 4; i++){ //las ruedas estan en elementos[posRuedas(i)] 
		elementos->at(posRuedas[i])->rota(-15.0*X, 0.0f, 0.0f, 1.0f); //at(i) == get(i) //java
	}
	
	float distCentro = sin(angRuedas)*X / (sin(180.0 - (angRuedas * 2)));
	//traslada(0.0f, 0.0f, distCentro);
	//rota(angRuedas, 0.0f, 1.0f, 0.0f);
//	traslada(0.0f, 0.0f, -1.0*distCentro);
	traslada(X*cos(-1.0*giro), 0.0f, X*sin(-1.0*giro));
	giro += angRuedas;
	
}

void Coche::girar(float x) {
	float X = x * 3;
	if (angRuedas < -29 && X < 0)
		return;
	if (angRuedas > 29 && X > 0)
		return;
	angRuedas += X;


	elementos->at(posRuedas[0])->rota(X, 0.0f, 1.0f, 0.0f);


	elementos->at(posRuedas[1])->traslada(0.0f, 0.0f, anchoRuedas);
	elementos->at(posRuedas[1])->rota(X, 0.0f, 1.0f, 0.0f);
	elementos->at(posRuedas[1])->traslada(0.0f, 0.0f, -1.0*anchoRuedas);
}


Coche::~Coche() {

}
