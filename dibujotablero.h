#include <opencv2/opencv.hpp>
#include "tablero.h"
//#include "menu.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
using namespace cv;



Scalar negro = Scalar(0, 0, 0);
Scalar celeste = Scalar(0, 150, 210);
Scalar blanco = Scalar(255, 255, 255);
Scalar amarillo= Scalar(204,255,255);
Scalar Color;
bool turno=true;
//int clicks=0;
bool moves=false;
bool Anillo5=false;
//Scalar rojo= Scalar (0,0,255);
//Scalar azul= Scalar (255,0,26);
Mat Game(600, 600, CV_8UC3, celeste);
int Anillo1X[15];
int Anillo1Y[15];

int Anillo2X[15];
int Anillo2Y[15];

int Anillo3X[15];
int Anillo3Y[15];

int Anillo4X[7];
int Anillo4Y[7];

int Anillo5X[3];
int Anillo5Y[3];
//int x1=1,y1=1;
//int Anillo4[16];
int i=0;
int Totalazul=0;
int Totalrojo=0;

void Dibujarsuma(){\
	ostringstream os;
	ostringstream os1;
	os<<Totalrojo;
	os1<<Totalazul;
	Rect Suma  (0,0,140,40);
	rectangle(Game, Suma ,celeste,CV_FILLED);
	putText(Game, "Piezas rojas: "+os.str(), Point(10, 16), FONT_HERSHEY_SIMPLEX, 0.4, negro);
	putText(Game, "Piezas azules: "+os1.str(), Point(10, 27), FONT_HERSHEY_SIMPLEX, 0.4, negro);
}

void contar(){
	Nodo*suma= pAnillo1;

	do{
		if (suma->ficha==1){
			Totalrojo++;
		}
		if(suma->ficha==2){
			Totalazul++;
		}
		suma=suma->sig;

	}while(suma!=pAnillo1);

	suma=pAnillo2;

	do{
		if (suma->ficha==1){
			Totalrojo++;
		}
		if(suma->ficha==2){
			Totalazul++;
		}
		suma=suma->sig;

	}while(suma!=pAnillo2);
	
	suma=pAnillo3;

	do{
		if (suma->ficha==1){
			Totalrojo++;
		}
		if(suma->ficha==2){
			Totalazul++;
		}
		suma=suma->sig;

	}while(suma!=pAnillo3);

	suma=pAnillo4;

	do{
		if (suma->ficha==1){
			Totalrojo++;
		}
		if(suma->ficha==2){
			Totalazul++;
		}
		suma=suma->sig;

	}while(suma!=pAnillo4);

	suma=pAnillo5;

	do{
		if (suma->ficha==1){
			Totalrojo++;
		}
		if(suma->ficha==2){
			Totalazul++;
		}
		suma=suma->sig;

	}while(suma!=pAnillo5);
	Dibujarsuma();

}

void revisar(){
	Nodo*revisar=pAnillo5;
	int valor=turno? 1:2;

	if (revisar->ficha==revisar->sig->ficha and revisar->sig->ficha==revisar->sig->sig->ficha and revisar->sig->sig->ficha==revisar->sig->sig->sig->ficha){
		cout<<"Hola, ganaste mahe "<<endl;
	}


}

void imprimir(){
	for (int i=0; i<=15; i++){
		cout<<"Puntox: "<<Anillo1X[i]<<endl;
		cout<<"Puntoy: "<<Anillo1Y[i]<<endl;
	}
}

void fill(){
	for (int i=0; i<=15; i++){
		Anillo1X[i]=0;
		Anillo1Y[i]=0;
	}
}

void GuardarcentrosX(int puntox, int radio){
	//	cout<<"Coordenadas en X del anillo 1"
	if (radio==250){
		for(int i=0; i<=15;i++){
			if (Anillo1X[i]==0){
				Anillo1X[i]=puntox;
				break;
			}
		}
	}
		if (radio==200){
		for(int i=0; i<=15;i++){
			if (Anillo2X[i]==0){
				Anillo2X[i]=puntox;
				break;
			}
		}
	}
		if (radio==150){
		for(int i=0; i<=15;i++){
			if (Anillo3X[i]==0){
				Anillo3X[i]=puntox;
				break;
			}
		}
	}
		if (radio==100){
		for(int i=0; i<=7;i++){
			if (Anillo4X[i]==0){
				Anillo4X[i]=puntox;
				break;
			}
		}
	}
		if (radio==50){
		for(int i=0; i<=4;i++){
			if (Anillo5X[i]==0){
				Anillo5X[i]=puntox;
				break;
			}
		}
	}
}

void GuardarcentrosY(int puntoY, int radio){
	//	cout<<"Coordenadas en X del anillo 1"
	if (radio==250){
		for(int i=0; i<=15;i++){
			if (Anillo1Y[i]==0){
				Anillo1Y[i]=puntoY;
				break;
			}
		}
	}
		if (radio==200){
		for(int i=0; i<=15;i++){
			if (Anillo2Y[i]==0){
				Anillo2Y[i]=puntoY;
				break;
			}
		}
	}
		if (radio==150){
		for(int i=0; i<=15;i++){
			if (Anillo3Y[i]==0){
				Anillo3Y[i]=puntoY;
				break;
			}
		}
	}
		if (radio==100){
		for(int i=0; i<=7;i++){
			if (Anillo4Y[i]==0){
				Anillo4Y[i]=puntoY;
				break;
			}
		}
	}
		if (radio==50){
		for(int i=0; i<=4;i++){
			if (Anillo5Y[i]==0){
				Anillo5Y[i]=puntoY;
				break;
			}
		}
	}
}

void dibujarlineas(){
	Point inicio =Point(Game.rows/2,271);
	Point final = Point(Game.rows/2,332);
	line(Game, inicio,final,blanco,3);

	//cruz horizontal
	inicio=Point(271,301);
	final = Point(330,302);
	line(Game, inicio,final,blanco,3);

	//ultima pieza de cada lado
	inicio=Point(208,391);
	final = Point(215,385);
	line(Game, inicio,final,blanco,3);

	inicio=Point(208,209);
	final = Point(216,216);
	line(Game, inicio,final,blanco,3);

	inicio=Point(392,208);
	final = Point(385,215);
	line(Game, inicio,final,blanco,3);

	inicio=Point(385,385);
	final = Point(392,392);
	line(Game, inicio,final,blanco,3);

	//Dibujar lineas de la horizontal
	inicio=Point(72,300);
	final = Point(82,300);
	line(Game, inicio,final,blanco,3);

	inicio=Point(172,300);
	final = Point(182,300);
	line(Game, inicio,final,blanco,3);

	inicio=Point(222,300);
	final = Point(232,300);
	line(Game, inicio,final,blanco,3);

	inicio=Point(372,300);
	final = Point(382,300);
	line(Game, inicio,final,blanco,3);

	inicio=Point(422,300);
	final = Point(432,300);
	line(Game, inicio,final,blanco,3);

	inicio=Point(522,300);
	final = Point(532,300);
	line(Game, inicio,final,blanco,3);

	//dibujar lineas Vertical
	inicio=Point(300,72);
	final = Point(300,82);
	line(Game, inicio,final,blanco,3);

	inicio=Point(300,172);
	final = Point(300,182);
	line(Game, inicio,final,blanco,3);

	inicio=Point(300,222);
	final = Point(300,232);
	line(Game, inicio,final,blanco,3);

	inicio=Point(300,372);
	final = Point(300,382);
	line(Game, inicio,final,blanco,3);

	inicio=Point(300,422);
	final = Point(300,432);
	line(Game, inicio,final,blanco,3);

	inicio=Point(300,522);
	final = Point(300,532);
	line(Game, inicio,final,blanco,3);
}


void dibujarAnillo(int radio, int casillas) {
	int r=1;
	Nodo*aux;

	if (radio==250){
		aux=pAnillo1;
	}
	else if (radio==200){
		aux=pAnillo2;
	}
	else if (radio==150){
		aux=pAnillo3;
	}
	else if (radio==100){
		aux=pAnillo4;
	}
	else if (radio==50){
		aux=pAnillo5;
	}

	Point centro = Point(Game.rows / 2, Game.cols / 2);
	circle(Game, centro, radio, blanco, 2);
	circle(Game, centro, radio+25, amarillo, 0.1);

	float angulo = 2 * 3.14159 / casillas;
	//cout << "Dibujando casillas..." << endl;
	for (float i = 0; i < 2 * 3.14159; i += angulo) {
		//cout << "angulo: " << i * 180 / 3.14159 << "\tgrados" << endl;
		Point casilla = Point(centro.x + radio*cos(i), centro.y + radio*sin(i));
		if (aux->ficha==0){
			Color=blanco;
		}
		else if (aux->ficha==1){
			Color=Scalar (0,0,255);
		}
		else if (aux->ficha==2){
			Color=Scalar (255,0,26);
		}


		GuardarcentrosX(casilla.x, radio);
		GuardarcentrosY(casilla.y, radio);
		//conecciones anillos 2 y 3
		Point l1=Point(centro.x+178*cos(i), centro.y+178*sin(i));
		Point l2=Point(centro.x+170*cos(i), centro.y+170*sin(i));
		line(Game,l1,l2,blanco,3);
		// Conecciones  anillos 3 y 4
		Point l3=Point(centro.x+178*cos(i), centro.y+178*sin(i));
		Point l4=Point(centro.x+162*cos(i), centro.y+162*sin(i));
		if (r%2!=0 ){
		line(Game,l3,l4,blanco,3);
		}
		circle(Game, casilla, 20, Color, CV_FILLED);
		dibujarlineas();
		r++;
		aux=aux->sig;
	}
}



void movimiento(Nodo*actual, Nodo*destino, int valor){
	int saltarinxd;
	string jugador;
	Scalar Color;
	if (actual->sig==destino or actual->ant== destino or actual->up==destino or actual->down==destino){
		if (actual->ficha==valor and actual!=destino and actual->ficha!=destino->ficha){
			saltarinxd=actual->ficha;
			destino->ficha= saltarinxd;
			actual->ficha=0;
		//	cout<<"Primer movimiento es..."<<Mov1->ficha<<endl;
		//	cout<<"El segundo movimiento es..."<<Mov2->ficha<<endl;
			turno=!turno;
		}
	}
	Mov1=NULL;
	Mov2=NULL;
	dibujarAnillo(250, 16);
	//imprimir();
	dibujarAnillo(200, 16);
	dibujarAnillo(150, 16);
	dibujarAnillo(100, 8);
	dibujarAnillo(50, 4);
	jugador=turno? "ROJO":"AZUL";
	Color= turno? Scalar (0,0,255): Scalar (255,0,26);
	Rect turno  (400,575,599,575);
	rectangle(Game, turno ,Color,CV_FILLED);
	putText(Game, "Es turno de "+jugador, Point(420, 595), FONT_HERSHEY_SIMPLEX, 0.6, negro);


	imshow("Tablero", Game);
	waitKey(0);
	//setMouseCallback("Tablero",Onmouse);
	revisar();

}

void Onmouse(int event, int x, int y, int, void*){
	  Nodo*aux=NULL;
	  	//Mov1=NULL;
		//Mov2=NULL;

	  int valor=0;
	  	valor = turno? 1:2;
		if (event==EVENT_LBUTTONUP){
		//PREPARANDO CIRCULOS DE EL SEGUNDO ANILLO
		if (x >= Anillo1X[0]-20 && x < Anillo1X[0]+20 && y >= Anillo1Y[0]-20 && y <=Anillo1Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux= pAnillo1;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}
			if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[1]-20 && x < Anillo1X[1]+20 && y >= Anillo1Y[1]-20 && y <=Anillo1Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[2]-20 && x < Anillo1X[2]+20 && y >= Anillo1Y[2]-20 && y <=Anillo1Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[3]-20 && x < Anillo1X[3]+20 && y >= Anillo1Y[3]-20 && y <=Anillo1Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[4]-20 && x < Anillo1X[4]+20 && y >= Anillo1Y[4]-20 && y <=Anillo1Y[4]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[5]-20 && x < Anillo1X[5]+20 && y >= Anillo1Y[5]-20 && y <=Anillo1Y[5]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[6]-20 && x < Anillo1X[6]+20 && y >= Anillo1Y[6]-20 && y <=Anillo1Y[6]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[7]-20 && x < Anillo1X[7]+20 && y >= Anillo1Y[7]-20 && y <=Anillo1Y[7]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[8]-20 && x < Anillo1X[8]+20 && y >= Anillo1Y[8]-20 && y <=Anillo1Y[8]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[9]-20 && x < Anillo1X[9]+20 && y >= Anillo1Y[9]-20 && y <=Anillo1Y[9]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[10]-20 && x < Anillo1X[10]+20 && y >= Anillo1Y[10]-20 && y <=Anillo1Y[10]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[11]-20 && x < Anillo1X[11]+20 && y >= Anillo1Y[11]-20 && y <=Anillo1Y[11]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[12]-20 && x < Anillo1X[12]+20 && y >= Anillo1Y[12]-20 && y <=Anillo1Y[12]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[13]-20 && x < Anillo1X[13]+20 && y >= Anillo1Y[13]-20 && y <=Anillo1Y[13]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[14]-20 && x < Anillo1X[14]+20 && y >= Anillo1Y[14]-20 && y <=Anillo1Y[14]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[15]-20 && x < Anillo1X[15]+20 && y >= Anillo1Y[15]-20 && y <=Anillo1Y[15]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		//PREPARANDO CIRCULOS DE EL SEGUNDO ANILLO
		if (x >= Anillo2X[0]-20 && x < Anillo2X[0]+20 && y >= Anillo2Y[0]-20 && y <=Anillo2Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			//Nodo*aux;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}
			aux = pAnillo2;

		}
		if (x >= Anillo2X[1]-20 && x < Anillo2X[1]+20 && y >= Anillo2Y[1]-20 && y <=Anillo2Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[2]-20 && x < Anillo2X[2]+20 && y >= Anillo2Y[2]-20 && y <=Anillo2Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[3]-20 && x < Anillo2X[3]+20 && y >= Anillo2Y[3]-20 && y <=Anillo2Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[4]-20 && x < Anillo2X[4]+20 && y >= Anillo2Y[4]-20 && y <=Anillo2Y[4]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[5]-20 && x < Anillo2X[5]+20 && y >= Anillo2Y[5]-20 && y <=Anillo2Y[5]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[6]-20 && x < Anillo2X[6]+20 && y >= Anillo2Y[6]-20 && y <=Anillo2Y[6]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[7]-20 && x < Anillo2X[7]+20 && y >= Anillo2Y[7]-20 && y <=Anillo2Y[7]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[8]-20 && x < Anillo2X[8]+20 && y >= Anillo2Y[8]-20 && y <=Anillo2Y[8]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[9]-20 && x < Anillo2X[9]+20 && y >= Anillo2Y[9]-20 && y <=Anillo2Y[9]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[10]-20 && x < Anillo2X[10]+20 && y >= Anillo2Y[10]-20 && y <=Anillo2Y[10]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[11]-20 && x < Anillo2X[11]+20 && y >= Anillo2Y[11]-20 && y <=Anillo2Y[11]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[12]-20 && x < Anillo2X[12]+20 && y >= Anillo2Y[12]-20 && y <=Anillo2Y[12]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[13]-20 && x < Anillo2X[13]+20 && y >= Anillo2Y[13]-20 && y <=Anillo2Y[13]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[14]-20 && x < Anillo2X[14]+20 && y >= Anillo2Y[14]-20 && y <=Anillo2Y[14]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[15]-20 && x < Anillo2X[15]+20 && y >= Anillo2Y[15]-20 && y <=Anillo2Y[15]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		//ANILLO 3
		if (x >= Anillo3X[0]-20 && x < Anillo3X[0]+20 && y >= Anillo3Y[0]-20 && y <=Anillo3Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			//Nodo*aux;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}
			aux = pAnillo3;

		}
		if (x >= Anillo3X[1]-20 && x < Anillo3X[1]+20 && y >= Anillo3Y[1]-20 && y <=Anillo3Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[2]-20 && x < Anillo3X[2]+20 && y >= Anillo3Y[2]-20 && y <=Anillo3Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[3]-20 && x < Anillo3X[3]+20 && y >= Anillo3Y[3]-20 && y <=Anillo3Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[4]-20 && x < Anillo3X[4]+20 && y >= Anillo3Y[4]-20 && y <=Anillo3Y[4]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[5]-20 && x < Anillo3X[5]+20 && y >= Anillo3Y[5]-20 && y <=Anillo3Y[5]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[6]-20 && x < Anillo3X[6]+20 && y >= Anillo3Y[6]-20 && y <=Anillo3Y[6]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[7]-20 && x < Anillo3X[7]+20 && y >= Anillo3Y[7]-20 && y <=Anillo3Y[7]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[8]-20 && x < Anillo3X[8]+20 && y >= Anillo3Y[8]-20 && y <=Anillo3Y[8]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[9]-20 && x < Anillo3X[9]+20 && y >= Anillo3Y[9]-20 && y <=Anillo3Y[9]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[10]-20 && x < Anillo3X[10]+20 && y >= Anillo3Y[10]-20 && y <=Anillo3Y[10]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
			if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[11]-20 && x < Anillo3X[11]+20 && y >= Anillo3Y[11]-20 && y <=Anillo3Y[11]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[12]-20 && x < Anillo3X[12]+20 && y >= Anillo3Y[12]-20 && y <=Anillo3Y[12]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[13]-20 && x < Anillo3X[13]+20 && y >= Anillo3Y[13]-20 && y <=Anillo3Y[13]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[14]-20 && x < Anillo3X[14]+20 && y >= Anillo3Y[14]-20 && y <=Anillo3Y[14]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[15]-20 && x < Anillo3X[15]+20 && y >= Anillo3Y[15]-20 && y <=Anillo3Y[15]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}

		// ANILLO 4

		if (x >= Anillo4X[0]-20 && x < Anillo4X[0]+20 && y >= Anillo4Y[0]-20 && y <=Anillo4Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			//Nodo*aux;
			aux = pAnillo4;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}


		}
		if (x >= Anillo4X[1]-20 && x < Anillo4X[1]+20 && y >= Anillo4Y[1]-20 && y <=Anillo4Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[2]-20 && x < Anillo4X[2]+20 && y >= Anillo4Y[2]-20 && y <=Anillo4Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[3]-20 && x < Anillo4X[3]+20 && y >= Anillo4Y[3]-20 && y <=Anillo4Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[4]-20 && x < Anillo4X[4]+20 && y >= Anillo4Y[4]-20 && y <=Anillo4Y[4]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[5]-20 && x < Anillo4X[5]+20 && y >= Anillo4Y[5]-20 && y <=Anillo4Y[5]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[6]-20 && x < Anillo4X[6]+20 && y >= Anillo4Y[6]-20 && y <=Anillo4Y[6]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[7]-20 && x < Anillo4X[7]+20 && y >= Anillo4Y[7]-20 && y <=Anillo4Y[7]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}

		//ANILLO 5
		if (x >= Anillo5X[0]-20 && x < Anillo5X[0]+20 && y >= Anillo5Y[0]-20 && y <=Anillo5Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			//Nodo*aux;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}
			aux = pAnillo5;
		}
		if (x >= Anillo5X[1]-20 && x < Anillo5X[1]+20 && y >= Anillo5Y[1]-20 && y <=Anillo5Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo5 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo5X[2]-20 && x < Anillo5X[2]+20 && y >= Anillo5Y[2]-20 && y <=Anillo5Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo5 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo5X[3]-20 && x < Anillo5X[3]+20 && y >= Anillo5Y[3]-20 && y <=Anillo5Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo5 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL ){
				Mov2=aux;
			}
		}
		if (aux!=NULL){
			cout<<aux->ficha<<endl;
			

		}

		if (Mov1!=NULL and Mov2!=NULL and Mov1->ficha!=0 ){
			cout<<"Primer movimiento es..."<<Mov1->ficha<<endl;
			cout<<"El segundo movimiento es..."<<Mov2->ficha<<endl;
			movimiento(Mov1, Mov2, valor);
		}		
	}
}



void  DibujarTablero(){

	//dibujarlineas();

	dibujarAnillo(250, 16);
	//imprimir();
	dibujarAnillo(200, 16);
	dibujarAnillo(150, 16);
	dibujarAnillo(100, 8);
	dibujarAnillo(50, 4);
	//PutText
	string jugador;
	jugador=turno? "ROJO":"AZUL";
	Color= turno? Scalar (0,0,255): Scalar (255,0,26);
	Rect turno  (400,575,599,575);
	rectangle(Game, turno ,Color,CV_FILLED);
	putText(Game, "Es turno de "+jugador, Point(420, 595), FONT_HERSHEY_SIMPLEX, 0.6, negro);
	
	imshow("Tablero", Game);
	waitKey(0);
	setMouseCallback("Tablero",Onmouse);

	//return 0;
}

void tableroinic(){
	Tablero juego;
	juego.llenar();
	contar();


	fill();
	DibujarTablero();
}
