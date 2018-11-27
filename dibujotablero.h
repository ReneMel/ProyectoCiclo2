#include <opencv2/opencv.hpp>
#include "tablero.h"
#include <iostream>
#include <cmath>
using namespace std;
using namespace cv;



Scalar negro = Scalar(0, 0, 0);
Scalar blanco = Scalar(255, 255, 255);
Scalar amarillo= Scalar(204,255,255);
Scalar Color;
bool turno=true;
//int clicks=0;
bool moves=false;
//Scalar rojo= Scalar (0,0,255);
//Scalar azul= Scalar (255,0,26);
Mat Game(600, 600, CV_8UC3, negro);
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
	Point inicio =Point(Game.rows/2,50);
	Point final = Point(Game.rows/2,550);
	line(Game, inicio,final,blanco,3);
	inicio=Point(50,300);
	final = Point(550,300);
	line(Game, inicio,final,blanco,3);

	inicio=Point(115,224);
	final = Point(160,240);
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
		Point l1=Point(centro.x+200*cos(i), centro.y+200*sin(i));
		Point l2=Point(centro.x+150*cos(i), centro.y+150*sin(i));
		line(Game,l1,l2,blanco,3);
		// Conecciones  anillos 3 y 4
		Point l3=Point(centro.x+150*cos(i), centro.y+150*sin(i));
		Point l4=Point(centro.x+100*cos(i), centro.y+100*sin(i));
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
	if (actual->ficha==valor){
		saltarinxd=actual->ficha;
		destino->ficha= saltarinxd;
		actual->ficha=0;
		cout<<"Primer movimiento es..."<<Mov1->ficha<<endl;
		cout<<"El segundo movimiento es..."<<Mov2->ficha<<endl;
		turno=!turno;
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

}

void Onmouse(int event, int x, int y, int, void*){
	  Nodo*aux=NULL;
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
			else if (Mov2==NULL and Mov1!=NULL){
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

	fill();
	DibujarTablero();
}