#include <opencv2/opencv.hpp>
//#include "tablero.h"
#include <iostream>
#include <cmath>
using namespace std;
using namespace cv;


Scalar negro = Scalar(0, 0, 0);
Scalar blanco = Scalar(255, 255, 255);
Scalar amarillo(204,255,255);
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


void Onmouse(int event, int x, int y, int, void*){
	if (event==EVENT_LBUTTONUP){
		//PREPARANDO CIRCULOS DE EL SEGUNDO ANILLO 
		if (x >= Anillo1X[0]-20 && x < Anillo1X[0]+20 && y >= Anillo1Y[0]-20 && y <=Anillo1Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[1]-20 && x < Anillo1X[1]+20 && y >= Anillo1Y[1]-20 && y <=Anillo1Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[2]-20 && x < Anillo1X[2]+20 && y >= Anillo1Y[2]-20 && y <=Anillo1Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[3]-20 && x < Anillo1X[3]+20 && y >= Anillo1Y[3]-20 && y <=Anillo1Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[4]-20 && x < Anillo1X[4]+20 && y >= Anillo1Y[4]-20 && y <=Anillo1Y[4]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[5]-20 && x < Anillo1X[5]+20 && y >= Anillo1Y[5]-20 && y <=Anillo1Y[5]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[6]-20 && x < Anillo1X[6]+20 && y >= Anillo1Y[6]-20 && y <=Anillo1Y[6]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[7]-20 && x < Anillo1X[7]+20 && y >= Anillo1Y[7]-20 && y <=Anillo1Y[7]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[8]-20 && x < Anillo1X[8]+20 && y >= Anillo1Y[8]-20 && y <=Anillo1Y[8]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[9]-20 && x < Anillo1X[9]+20 && y >= Anillo1Y[9]-20 && y <=Anillo1Y[9]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[10]-20 && x < Anillo1X[10]+20 && y >= Anillo1Y[10]-20 && y <=Anillo1Y[10]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo1X[11]-20 && x < Anillo1X[11]+20 && y >= Anillo1Y[11]-20 && y <=Anillo1Y[11]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo1X[12]-20 && x < Anillo1X[12]+20 && y >= Anillo1Y[12]-20 && y <=Anillo1Y[12]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo1X[13]-20 && x < Anillo1X[13]+20 && y >= Anillo1Y[13]-20 && y <=Anillo1Y[13]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo1X[14]-20 && x < Anillo1X[14]+20 && y >= Anillo1Y[14]-20 && y <=Anillo1Y[14]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo1X[15]-20 && x < Anillo1X[15]+20 && y >= Anillo1Y[15]-20 && y <=Anillo1Y[15]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		//PREPARANDO CIRCULOS DE EL SEGUNDO ANILLO 
		if (x >= Anillo2X[0]-20 && x < Anillo2X[0]+20 && y >= Anillo2Y[0]-20 && y <=Anillo2Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[1]-20 && x < Anillo2X[1]+20 && y >= Anillo2Y[1]-20 && y <=Anillo2Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[2]-20 && x < Anillo2X[2]+20 && y >= Anillo2Y[2]-20 && y <=Anillo2Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[3]-20 && x < Anillo2X[3]+20 && y >= Anillo2Y[3]-20 && y <=Anillo2Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[4]-20 && x < Anillo2X[4]+20 && y >= Anillo2Y[4]-20 && y <=Anillo2Y[4]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[5]-20 && x < Anillo2X[5]+20 && y >= Anillo2Y[5]-20 && y <=Anillo2Y[5]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[6]-20 && x < Anillo2X[6]+20 && y >= Anillo2Y[6]-20 && y <=Anillo2Y[6]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[7]-20 && x < Anillo2X[7]+20 && y >= Anillo2Y[7]-20 && y <=Anillo2Y[7]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[8]-20 && x < Anillo2X[8]+20 && y >= Anillo2Y[8]-20 && y <=Anillo2Y[8]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[9]-20 && x < Anillo2X[9]+20 && y >= Anillo2Y[9]-20 && y <=Anillo2Y[9]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[10]-20 && x < Anillo2X[10]+20 && y >= Anillo2Y[10]-20 && y <=Anillo2Y[10]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo2X[11]-20 && x < Anillo2X[11]+20 && y >= Anillo2Y[11]-20 && y <=Anillo2Y[11]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo2X[12]-20 && x < Anillo2X[12]+20 && y >= Anillo2Y[12]-20 && y <=Anillo2Y[12]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo2X[13]-20 && x < Anillo2X[13]+20 && y >= Anillo2Y[13]-20 && y <=Anillo2Y[13]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo2X[14]-20 && x < Anillo2X[14]+20 && y >= Anillo2Y[14]-20 && y <=Anillo2Y[14]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo2X[15]-20 && x < Anillo2X[15]+20 && y >= Anillo2Y[15]-20 && y <=Anillo2Y[15]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		//ANILLO 3
		if (x >= Anillo3X[0]-20 && x < Anillo3X[0]+20 && y >= Anillo3Y[0]-20 && y <=Anillo3Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[1]-20 && x < Anillo3X[1]+20 && y >= Anillo3Y[1]-20 && y <=Anillo3Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[2]-20 && x < Anillo3X[2]+20 && y >= Anillo3Y[2]-20 && y <=Anillo3Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[3]-20 && x < Anillo3X[3]+20 && y >= Anillo3Y[3]-20 && y <=Anillo3Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[4]-20 && x < Anillo3X[4]+20 && y >= Anillo3Y[4]-20 && y <=Anillo3Y[4]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[5]-20 && x < Anillo3X[5]+20 && y >= Anillo3Y[5]-20 && y <=Anillo3Y[5]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[6]-20 && x < Anillo3X[6]+20 && y >= Anillo3Y[6]-20 && y <=Anillo3Y[6]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[7]-20 && x < Anillo3X[7]+20 && y >= Anillo3Y[7]-20 && y <=Anillo3Y[7]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[8]-20 && x < Anillo3X[8]+20 && y >= Anillo3Y[8]-20 && y <=Anillo3Y[8]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[9]-20 && x < Anillo3X[9]+20 && y >= Anillo3Y[9]-20 && y <=Anillo3Y[9]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[10]-20 && x < Anillo3X[10]+20 && y >= Anillo3Y[10]-20 && y <=Anillo3Y[10]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo3X[11]-20 && x < Anillo3X[11]+20 && y >= Anillo3Y[11]-20 && y <=Anillo3Y[11]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo3X[12]-20 && x < Anillo3X[12]+20 && y >= Anillo3Y[12]-20 && y <=Anillo3Y[12]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo3X[13]-20 && x < Anillo3X[13]+20 && y >= Anillo3Y[13]-20 && y <=Anillo3Y[13]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo3X[14]-20 && x < Anillo3X[14]+20 && y >= Anillo3Y[14]-20 && y <=Anillo3Y[14]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}
		if (x >= Anillo3X[15]-20 && x < Anillo3X[15]+20 && y >= Anillo3Y[15]-20 && y <=Anillo3Y[15]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
		
		}

		// ANILLO 4

		if (x >= Anillo4X[0]-20 && x < Anillo4X[0]+20 && y >= Anillo4Y[0]-20 && y <=Anillo4Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo4X[1]-20 && x < Anillo4X[1]+20 && y >= Anillo4Y[1]-20 && y <=Anillo4Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo4X[2]-20 && x < Anillo4X[2]+20 && y >= Anillo4Y[2]-20 && y <=Anillo4Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo4X[3]-20 && x < Anillo4X[3]+20 && y >= Anillo4Y[3]-20 && y <=Anillo4Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo4X[4]-20 && x < Anillo4X[4]+20 && y >= Anillo4Y[4]-20 && y <=Anillo4Y[4]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo4X[5]-20 && x < Anillo4X[5]+20 && y >= Anillo4Y[5]-20 && y <=Anillo4Y[5]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo4X[6]-20 && x < Anillo4X[6]+20 && y >= Anillo4Y[6]-20 && y <=Anillo4Y[6]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo4X[7]-20 && x < Anillo4X[7]+20 && y >= Anillo4Y[7]-20 && y <=Anillo4Y[7]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}

		//ANILLO 5
		if (x >= Anillo5X[0]-20 && x < Anillo5X[0]+20 && y >= Anillo5Y[0]-20 && y <=Anillo5Y[0]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo5X[1]-20 && x < Anillo5X[1]+20 && y >= Anillo5Y[1]-20 && y <=Anillo5Y[1]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo5X[2]-20 && x < Anillo5X[2]+20 && y >= Anillo5Y[2]-20 && y <=Anillo5Y[2]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			
		}
		if (x >= Anillo5X[3]-20 && x < Anillo5X[3]+20 && y >= Anillo5Y[3]-20 && y <=Anillo5Y[3]+20){
			cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
	}
}
}


void dibujarAnillo(int radio, int casillas) {
	int r=1;
	Point centro = Point(Game.rows / 2, Game.cols / 2);
	circle(Game, centro, radio, blanco, 2);
	circle(Game, centro, radio+25, amarillo, 0.1);

	float angulo = 2 * 3.14159 / casillas;
	cout << "Dibujando casillas..." << endl;
	for (float i = 0; i < 2 * 3.14159; i += angulo) {
		cout << "angulo: " << i * 180 / 3.14159 << "\tgrados" << endl;
		Point casilla = Point(centro.x + radio*cos(i), centro.y + radio*sin(i));
		circle(Game, casilla, 20, blanco, CV_FILLED);
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
		r++;

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
//1 3 5 7 9 11 13 15
}

int DibujarTablero(){
	
	fill();
	dibujarAnillo(250, 16);
	//imprimir();
	dibujarAnillo(200, 16);
	dibujarAnillo(150, 16);
	dibujarAnillo(100, 8);
	dibujarAnillo(50, 4);
	dibujarlineas();


	imshow("Tablero", Game);
	waitKey(0);
	setMouseCallback("Tablero",Onmouse);

	//return 0;
}

