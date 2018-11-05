#include <cstdlib>
#include <iostream>

using namespace std;

struct Nodo {
	// Cuarto punteros: hacia upera, hacia downntro,
	// hacia el siguiente y hacia el anterior.
	Nodo *up, *down, *sig, *ant;
	// Otros campos, podr�an ser, por ejemplo: campo
	// para la ficha y coordenadas de cada nodo.
};

// Punteros auxiliares para crear cada anillo del tablero.
// Luego se har� que pInicio apunte a "toda" la estructura.
Nodo *pAnillo1 = NULL;
Nodo *pAnillo2 = NULL;
Nodo *pAnillo3 = NULL;
Nodo *pAnillo4 = NULL;
Nodo *pAnillo5 = NULL;

class Tablero {
private:
	Nodo *pInicio;
public:
	Tablero();
	void crearAnillo(Nodo **, int);
	void verificar();
};

Tablero::Tablero()
{
	pInicio = NULL;
	// Primero se crean los cinco anillos
	// doblemente enlazados:
	crearAnillo(&pAnillo1, 16);
	crearAnillo(&pAnillo2, 16);
	crearAnillo(&pAnillo3, 16);
	crearAnillo(&pAnillo4, 8);
	crearAnillo(&pAnillo5, 4);
	// Luego se unen los anillos entre s�, con
	// dobles enlaces, de acuerdo a como se unen
	// los c�rculos en el tablero del juego:
	Nodo *s1 = pAnillo1;
	Nodo *s2 = pAnillo2;
	// Este lazo une el anillo m�s externo con el segundo
	// por medio de 4 enlaces:
	for (int i = 1; i <= 4; i++) {
		s1->down = s2;
		s2->up = s1;
		s1 = s1->sig->sig->sig->sig;
		s2 = s2->sig->sig->sig->sig;
	}
	// Este lazo une el segundo anillo con el tercero
	// por medio de 16 enlaces:
	s2 = pAnillo2;
	Nodo *s3 = pAnillo3;
	for (int i = 1; i <= 16; i++) {
		s2->down = s3;
		s3->up = s2;
		s2 = s2->sig;
		s3 = s2->sig;
	}
	// Este lazo une el tercer anillo con el cuarto
	// por medio de 8 enlaces:
	s3 = pAnillo3;
	Nodo *s4 = pAnillo4;
	for (int i = 1; i <= 8; i++) {
		s3->down = s4;
		s4->up = s3;
		s3 = s3->sig->sig;
		s4 = s4->sig;
	}
	
	// Conecciones anillo5 con anillo 4
	s4=pAnillo4;
	Nodo*s5=pAnillo5;
	for (int i=1; i<=4;i++){
		s5->up=s4;
		s4->down=s5;
		s4= s4->sig->sig;
		s5= s5->sig;
	}

	// Finalmente se hace que pInicio sea el
	// puntero base de la estructura ya armada:
	pInicio = pAnillo1;
}

void Tablero::crearAnillo(Nodo **p, int numNodos)
{
	int i;
	*p = new Nodo;
	Nodo *nuevo;
	Nodo *s = *p;

	for (i = 2; i <= numNodos; i++) {
		nuevo = new Nodo;
		s->sig = nuevo;
		s->sig->ant = s;
		s = s->sig;
	}
	s->sig = *p;
	s->sig->ant = s;
}

int main(void)
{
	Tablero tableroJuego;

	return 0;
}