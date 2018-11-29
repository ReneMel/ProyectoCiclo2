#include <opencv2/opencv.hpp>
#include "tablero.h"
//#include "menu.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;
using namespace cv;

struct Jugador
{
	string name[200];
	string aka[200];
	int win[200];
	int lost[200];
	int Game[200];
}player;

string J1nombre,J2nombre,J1alias,J2alias;
char aux;
int m=1;
bool cerrar = false;
int tempW, tempLost, tempGame;
string tempN,Njugador,Ajugador;
string tempA;
int posicion;
String diez[10];
bool anillo5=false;
bool orden=false;
//bool turn=false;

Scalar negro = Scalar(0, 0, 0);
Scalar celeste = Scalar(0, 150, 210);
Scalar blanco = Scalar(255, 255, 255);
Scalar amarillo= Scalar(204,255,255);
Scalar verde (0, 255, 0);
Scalar rojo (0,0,255);
Scalar azul (255,0,26);
Scalar naranja(0,102,204);
Scalar Color;
bool turno=true;
bool restart=true;
bool endgame=false;
//int clicks=0;
bool moves=false;
bool Anillo5=false;
//Scalar rojo= Scalar (0,0,255);
//Scalar azul= Scalar (255,0,26);
Mat Rules(400,400, CV_8UC3, Scalar(204,204,255));
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
void llenarname();

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
	Totalazul=0;
	Totalrojo=0;

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

void kakuempate(){
	Mat Empate(200, 500, CV_8UC3, Scalar(51,255,255));
    putText(Empate, "-Empate-", Point(5, 100), FONT_HERSHEY_SIMPLEX, 3, verde);
    imshow("Empate", Empate);

    endgame = true;
}


//GANADOR NO FUNCIONA... ESTE ES DESVERGUE DE PEDRO...
void ganador(){

		string winner="";
		winner=(turno? J1nombre:J2nombre);
	       Mat ganador(200, 600, CV_8UC3, Scalar(51,255,255));
	    putText(ganador, "El ganador es: "+winner, Point(5, 100), FONT_HERSHEY_SIMPLEX, 1.6, rojo);
	    imshow("Ganador", ganador);
	    endgame=true;
	    llenarname();

}

void revisar(){
	Nodo*revisar=pAnillo5;
	int valor=turno? 1:2;

	if (revisar->ficha==revisar->sig->ficha and revisar->sig->ficha==revisar->sig->sig->ficha and revisar->sig->sig->ficha==revisar->sig->sig->sig->ficha){
		//cout<<"Hola, ganaste mahe "<<endl;
		//endgame=true;
		ganador();
	}
	else{
		contar();
		if (Totalazul==0 and Totalrojo==0){
			kakuempate();
		}
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



/*void movimiento(Nodo*actual, Nodo*destino, int valor){
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
	else if (destino->up==actual->down and destino->up->ficha!=0 and actual->ficha!=destino->up->ficha and actual->ficha==valor){
		saltarinxd=actual->ficha;
		actual->down->ficha=0;
		actual->ficha=0;
		destino->ficha=saltarinxd;
		if (destino->down->ficha==0){
			turno=!turno;
		}

	}
	//kakuempate();
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
	contar();


	imshow("Tablero", Game);
	waitKey(0);
	//setMouseCallback("Tablero",Onmouse);
	revisar();


}*/

void movimiento(Nodo*actual, Nodo*destino, int valor){
	int saltarinxd;
	string jugador;
	Scalar Color;

	if (actual->sig==destino or actual->ant==destino or actual->up==destino or actual->down==destino)
	{
		if (actual->ficha==valor and actual!=destino and actual->ficha!=destino->ficha)
		{
			saltarinxd=actual->ficha;
			destino->ficha=saltarinxd;
			actual->ficha=0;
		//	cout<<"Primer movimiento es..."<<Mov1->ficha<<endl;
		//	cout<<"El segundo movimiento es..."<<Mov2->ficha<<endl;
			turno=!turno;
		}
	}

	else if (destino->up==actual->down and destino->up->ficha!=0 and actual->ficha!=destino->up->ficha and actual->ficha==valor)
	{
		saltarinxd=actual->ficha;
		actual->down->ficha=0;
		actual->ficha=0;
		destino->ficha=saltarinxd;
		if (destino->down->ficha==0 and destino->down->ficha!=valor)
		{
			turno=!turno;
		}
	}
	//kakuempate();
	Mov1=NULL;
	Mov2=NULL;
	dibujarAnillo(250,16);
	//imprimir();
	dibujarAnillo(200,16);
	dibujarAnillo(150,16);
	dibujarAnillo(100,8);
	dibujarAnillo(50,4);
	jugador=turno? "ROJO":"AZUL";
	Color=turno? Scalar(0,0,255): Scalar(255,0,26);
	Rect turno (400,575,599,575);
	rectangle(Game,turno,Color,CV_FILLED);
	putText(Game, "Es turno de "+jugador, Point(420,595), FONT_HERSHEY_SIMPLEX, 0.6, negro);
	contar();

	imshow("Tablero", Game);
	waitKey(0);
	//setMouseCallback("Tablero",Onmouse);
	revisar();
}

void Reiniciar(){

	turno=true;
	restart=true;

	Tablero juego;

	juego.llenar();
	contar();
	fill();


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

	Rect restart(0,575,115,575);
	rectangle(Game, restart, Scalar(0,255,0), CV_FILLED);
	putText(Game, "Reiniciar", Point(15, 595), FONT_HERSHEY_SIMPLEX, 0.6, negro);

	imshow("Tablero", Game);
	waitKey(0);
	//setMouseCallback("Tablero",Onmouse);

}

void Onmouse(int event, int x, int y, int, void*){
	  Nodo*aux=NULL;
	 int valor=0;
	 valor = turno? 1:2;

	 if (endgame)return;

		if (event==EVENT_LBUTTONUP){
		//PREPARANDO CIRCULOS DE EL SEGUNDO ANILLO
		if (x >= Anillo1X[0]-20 && x < Anillo1X[0]+20 && y >= Anillo1Y[0]-20 && y <=Anillo1Y[0]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[2]-20 && x < Anillo1X[2]+20 && y >= Anillo1Y[2]-20 && y <=Anillo1Y[2]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[3]-20 && x < Anillo1X[3]+20 && y >= Anillo1Y[3]-20 && y <=Anillo1Y[3]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[4]-20 && x < Anillo1X[4]+20 && y >= Anillo1Y[4]-20 && y <=Anillo1Y[4]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[5]-20 && x < Anillo1X[5]+20 && y >= Anillo1Y[5]-20 && y <=Anillo1Y[5]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[6]-20 && x < Anillo1X[6]+20 && y >= Anillo1Y[6]-20 && y <=Anillo1Y[6]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[7]-20 && x < Anillo1X[7]+20 && y >= Anillo1Y[7]-20 && y <=Anillo1Y[7]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[8]-20 && x < Anillo1X[8]+20 && y >= Anillo1Y[8]-20 && y <=Anillo1Y[8]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[9]-20 && x < Anillo1X[9]+20 && y >= Anillo1Y[9]-20 && y <=Anillo1Y[9]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[10]-20 && x < Anillo1X[10]+20 && y >= Anillo1Y[10]-20 && y <=Anillo1Y[10]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[11]-20 && x < Anillo1X[11]+20 && y >= Anillo1Y[11]-20 && y <=Anillo1Y[11]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[12]-20 && x < Anillo1X[12]+20 && y >= Anillo1Y[12]-20 && y <=Anillo1Y[12]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[13]-20 && x < Anillo1X[13]+20 && y >= Anillo1Y[13]-20 && y <=Anillo1Y[13]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[14]-20 && x < Anillo1X[14]+20 && y >= Anillo1Y[14]-20 && y <=Anillo1Y[14]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo1 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo1X[15]-20 && x < Anillo1X[15]+20 && y >= Anillo1Y[15]-20 && y <=Anillo1Y[15]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[2]-20 && x < Anillo2X[2]+20 && y >= Anillo2Y[2]-20 && y <=Anillo2Y[2]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[3]-20 && x < Anillo2X[3]+20 && y >= Anillo2Y[3]-20 && y <=Anillo2Y[3]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[4]-20 && x < Anillo2X[4]+20 && y >= Anillo2Y[4]-20 && y <=Anillo2Y[4]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[5]-20 && x < Anillo2X[5]+20 && y >= Anillo2Y[5]-20 && y <=Anillo2Y[5]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[6]-20 && x < Anillo2X[6]+20 && y >= Anillo2Y[6]-20 && y <=Anillo2Y[6]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[7]-20 && x < Anillo2X[7]+20 && y >= Anillo2Y[7]-20 && y <=Anillo2Y[7]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[8]-20 && x < Anillo2X[8]+20 && y >= Anillo2Y[8]-20 && y <=Anillo2Y[8]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[9]-20 && x < Anillo2X[9]+20 && y >= Anillo2Y[9]-20 && y <=Anillo2Y[9]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[10]-20 && x < Anillo2X[10]+20 && y >= Anillo2Y[10]-20 && y <=Anillo2Y[10]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[11]-20 && x < Anillo2X[11]+20 && y >= Anillo2Y[11]-20 && y <=Anillo2Y[11]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[12]-20 && x < Anillo2X[12]+20 && y >= Anillo2Y[12]-20 && y <=Anillo2Y[12]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[13]-20 && x < Anillo2X[13]+20 && y >= Anillo2Y[13]-20 && y <=Anillo2Y[13]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[14]-20 && x < Anillo2X[14]+20 && y >= Anillo2Y[14]-20 && y <=Anillo2Y[14]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo2 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo2X[15]-20 && x < Anillo2X[15]+20 && y >= Anillo2Y[15]-20 && y <=Anillo2Y[15]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[2]-20 && x < Anillo3X[2]+20 && y >= Anillo3Y[2]-20 && y <=Anillo3Y[2]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[3]-20 && x < Anillo3X[3]+20 && y >= Anillo3Y[3]-20 && y <=Anillo3Y[3]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[4]-20 && x < Anillo3X[4]+20 && y >= Anillo3Y[4]-20 && y <=Anillo3Y[4]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[5]-20 && x < Anillo3X[5]+20 && y >= Anillo3Y[5]-20 && y <=Anillo3Y[5]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[6]-20 && x < Anillo3X[6]+20 && y >= Anillo3Y[6]-20 && y <=Anillo3Y[6]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[7]-20 && x < Anillo3X[7]+20 && y >= Anillo3Y[7]-20 && y <=Anillo3Y[7]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[8]-20 && x < Anillo3X[8]+20 && y >= Anillo3Y[8]-20 && y <=Anillo3Y[8]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[9]-20 && x < Anillo3X[9]+20 && y >= Anillo3Y[9]-20 && y <=Anillo3Y[9]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[10]-20 && x < Anillo3X[10]+20 && y >= Anillo3Y[10]-20 && y <=Anillo3Y[10]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
			if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[11]-20 && x < Anillo3X[11]+20 && y >= Anillo3Y[11]-20 && y <=Anillo3Y[11]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[12]-20 && x < Anillo3X[12]+20 && y >= Anillo3Y[12]-20 && y <=Anillo3Y[12]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[13]-20 && x < Anillo3X[13]+20 && y >= Anillo3Y[13]-20 && y <=Anillo3Y[13]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[14]-20 && x < Anillo3X[14]+20 && y >= Anillo3Y[14]-20 && y <=Anillo3Y[14]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo3 -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo3X[15]-20 && x < Anillo3X[15]+20 && y >= Anillo3Y[15]-20 && y <=Anillo3Y[15]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[2]-20 && x < Anillo4X[2]+20 && y >= Anillo4Y[2]-20 && y <=Anillo4Y[2]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[3]-20 && x < Anillo4X[3]+20 && y >= Anillo4Y[3]-20 && y <=Anillo4Y[3]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[4]-20 && x < Anillo4X[4]+20 && y >= Anillo4Y[4]-20 && y <=Anillo4Y[4]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[5]-20 && x < Anillo4X[5]+20 && y >= Anillo4Y[5]-20 && y <=Anillo4Y[5]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[6]-20 && x < Anillo4X[6]+20 && y >= Anillo4Y[6]-20 && y <=Anillo4Y[6]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo4 -> sig -> sig -> sig -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo4X[7]-20 && x < Anillo4X[7]+20 && y >= Anillo4Y[7]-20 && y <=Anillo4Y[7]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
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
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo5 -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo5X[2]-20 && x < Anillo5X[2]+20 && y >= Anillo5Y[2]-20 && y <=Anillo5Y[2]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo5 -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL){
				Mov2=aux;
			}

		}
		if (x >= Anillo5X[3]-20 && x < Anillo5X[3]+20 && y >= Anillo5Y[3]-20 && y <=Anillo5Y[3]+20){
			//cout<<"Click detectado en el punto ("<<x<<","<<y<<")"<<endl;
			aux=pAnillo5 -> sig -> sig -> sig;
						if (Mov1==NULL){
				Mov1=aux;
			}
			else if (Mov2==NULL and Mov1!=NULL ){
				Mov2=aux;
			}
		}
		/*if (aux!=NULL){
			cout<<aux->ficha<<endl;
			cout<<aux->num<<endl;
			if (aux->sig!=NULL){
				cout<<"Conectado en sig con"<<aux->sig->num<<endl;
			}
			if (aux->ant!=NULL){
				cout<<"Conectado en ant con"<<aux->ant->num<<endl;
			}
			if (aux->up!=NULL){
				cout<<"Conectado en up con"<<aux->up->num<<endl;
			}
			if (aux->down!=NULL){
				cout<<"Conectado en dow con"<<aux->down->num<<endl;
			}



		}*/

		if (Mov1!=NULL and Mov2!=NULL and Mov1->ficha!=0 ){
			//cout<<"Primer movimiento es..."<<Mov1->ficha<<endl;
			//cout<<"El segundo movimiento es..."<<Mov2->ficha<<endl;
			movimiento(Mov1, Mov2, valor);
		}

		if(0<=x && x<=115 && 575<=y && y<=599){
			Reiniciar();
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

	Rect restart(0,575,115,575);
	rectangle(Game, restart, Scalar(0,255,0), CV_FILLED);
	putText(Game, "Reiniciar", Point(15, 595), FONT_HERSHEY_SIMPLEX, 0.6, negro);

	imshow("Tablero", Game);
	waitKey(0);
	setMouseCallback("Tablero",Onmouse);

	//return 0;
}

void tableroinic(){
	Tablero juego;
	juego.llenar();
	juego.comprobar();
	contar();


	fill();
	DibujarTablero();
}

void llenar(){
	for (int i =0; i<200; i++){
		player.win[i]=0;
		player.name[i]= "";
		player.aka[i]= "";
	}
}

void Menu();


//Scalar negro(0, 0, 0);
//Scalar blanco(255, 255, 255);


Mat Ins(400,400, CV_8UC3, Scalar(204,204,255));
Mat Top(400,400, CV_8UC3, negro);
void Top10();

void leerDatos(){
	int win,loss,juegos, r=0;
	char c[5],d[5],f[5];
	string score;
	ifstream Datos("Datos.txt");
	while(!Datos.eof()){
		getline(Datos,score);
		diez[r]=score;
		r++;
		if(score.length()>=12) {
			//cout<<score<<endl;

			for (int i=0; i<5;i++){
				Njugador+=score.at(i);
			}
			for (int i=6; i<11;i++){
				Ajugador+=score.at(i);
			}
			for (int i=12; i<14;i++){
				c[i-12]=score.at(i);
				win=atoi(c);
			}
			for (int i=15; i<17;i++){
				d[i-15]=score.at(i);
				loss=atoi(d);
			}
			for (int i=17; i<20;i++){
				f[i-17]=score.at(i);
				juegos=atoi(f);
			}
				for (int i =0; i<200;i++){

					if (player.name[i].length()==0){
						player.name[i]=Njugador;
						player.aka[i]=Ajugador;
						player.win[i]=win;
						player.lost[i]=loss;
						player.Game[i]=win+loss;
						//cout <<player.win[i]<<endl;cout <<player.aka[i]<<endl;cout <<player.name[i]<<endl;
						Njugador="";
						Ajugador="";

						break;
					}
				}
		}
	}
}
void datostxt(){
	int n=0;
	//MostratTop():
	ofstream Datos ("Datos.txt");
	for (int i=0; i<200; i++){
		if (player.name[i].length()!=0){
			ostringstream os;
			os<<player.win[n];

			Datos<<player.name[n]+"|"<<player.aka[n]+"|"<<os.str()+"\r\n";
			n++;}

	}
	orden=false;
	//Nombre|AKA|wins|lost|Game
	Datos.close();
}


void ordenTop(){


	for (int i=0; i<=200; i++){
		for (int j=0; j<=199; j++){
			if (player.win[j]<player.win[j+1]){
			//ESTE CODIGO ES PARA ORDENAR EL WINS
				tempW=player.win[j];
				player.win[j]=player.win[j+1];
				player.win[j+1]=tempW;
			//ORDENAR EL NOMBRE
				tempN=player.name[j];
				player.name[j]=player.name[j+1];
				player.name[j+1]=tempN;
			// ORDENAR EL ALIAS
				tempA=player.aka[j];
				player.aka[j]=player.aka[j+1];
				player.aka[j+1]=tempA;
			//ORDENAR LOST
				tempLost=player.lost[j];
				player.lost[j]=player.lost[j+1];
				player.lost[j+1]=tempLost;
			//ORDENAR Game
				tempGame=player.Game[j];
				player.Game[j]=player.Game[j+1];
				player.Game[j+1]=tempGame;


		}
	}
	}
	orden=true;
	if (orden){
	datostxt();}
}

void llenarname(){
	string apodo="",namae="";
	if(turno){
		namae=J1nombre;
		apodo=J1alias;
	}
	else{
		namae=J2nombre;
		apodo=J2alias;
	}

	for(int i =0; i<200;i++){
		if (player.name[i]==namae && player.aka[i]==apodo){
			player.win[i]++;
			//cout<<player.win[i];
			ordenTop();
			break;
		}
		else if (player.name[i]==""){
				player.name[i]=namae;
				player.aka[i]=apodo;
				player.win[i]++;
				ordenTop();
				break;
		}
	}

}


void DibujarTop(){
	Rect  titulo (90,10,210,30);
	rectangle (Top,titulo,verde,CV_FILLED);
	putText(Top, "-TOP 10-", Point(125,32), FONT_HERSHEY_TRIPLEX, 0.8, azul);

	Rect mune(140,345,100,30);
	rectangle(Top,mune,rojo,CV_FILLED);
	putText(Top,"Menu",Point(170,370), FONT_HERSHEY_SIMPLEX, 0.8, blanco);
	putText(Top,"A.K.A.",Point(55,70), FONT_HERSHEY_TRIPLEX, 0.8, Scalar(51,255,255));
	putText(Top,"Lost",Point(210,70), FONT_HERSHEY_TRIPLEX, 0.8, Scalar(51,255,255));
	putText(Top,"Wins",Point(140,70), FONT_HERSHEY_TRIPLEX, 0.8, Scalar(51,255,255));
	putText(Top,"Game",Point(275,70), FONT_HERSHEY_TRIPLEX, 0.8, Scalar(51,255,255));





	int y=95;
	for (int i=0; i<11; i++){
		if (player.name[i].length()>=0){
			ostringstream os;
			os<<player.win[i];
		putText(Top, player.aka[i], Point(55,y),FONT_HERSHEY_PLAIN, 1.1, blanco);
		//putText(Top, os.str()+" pts.", Point(90,y), FONT_HERSHEY_PLAIN, 1.1, blanco);
		y+=25;
	}
	}
	int y2=95;
	for (int i=0; i<10; i++){
		ostringstream os;
		os<<player.win[i];
		putText(Top, os.str()+" wins.", Point(140,y2), FONT_HERSHEY_PLAIN, 1.1, blanco);
		y2+=25;
	}
	y=95;
	for (int i=0; i<10; i++){
		ostringstream os;
		os<<player.lost[i];
		putText(Top, os.str()+" loss", Point(210,y), FONT_HERSHEY_PLAIN, 1.1, blanco);
		y+=25;
	}
	y=95;
	for (int i=0; i<10; i++){
		ostringstream os;
		os<<player.Game[i];
		putText(Top, os.str()+" games.", Point(275,y), FONT_HERSHEY_PLAIN, 1.1, blanco);
		y+=25;
	}
	y=95;
	for (int i=1; i<=10; i++){
		ostringstream os;
		os<<i;
		putText(Top, os.str()+".", Point(15,y), FONT_HERSHEY_PLAIN, 1.1, blanco);
		y+=25;
	}


}

void Dibujarinscrip(Mat Ins){

	//Rect Hola()
	putText(Ins,"Jugador 1", Point(10,30), FONT_HERSHEY_SIMPLEX,0.7,azul);

	putText(Ins,"Nombre: ", Point(10,85), FONT_HERSHEY_SIMPLEX,0.7,azul);
		Rect recNamae1 (110,65,275,30);
		rectangle(Ins, recNamae1,blanco,CV_FILLED);
	putText(Ins,"Alias: ", Point(10,145), FONT_HERSHEY_SIMPLEX,0.7,azul);
		Rect recAlias1 (110,125,275,30);
		rectangle(Ins,recAlias1,blanco,CV_FILLED);

	putText(Ins,"Jugador 2", Point(10,210), FONT_HERSHEY_SIMPLEX,0.7,naranja);

	putText(Ins,"Nombre: ", Point(10,265), FONT_HERSHEY_SIMPLEX,0.7,naranja);
		Rect recNamae2 (110,245,275,30);
		rectangle(Ins, recNamae2,blanco,CV_FILLED);
	putText(Ins,"Alias: ", Point(10,325), FONT_HERSHEY_SIMPLEX,0.7,naranja);
		Rect recAlias2 (110,305,275,30);
		rectangle(Ins,recAlias2,blanco,CV_FILLED);

		Rect Juego(120,355,155,35);
		rectangle(Ins,Juego,rojo,CV_FILLED);
	putText(Ins, "Iniciar Juego!",Point(125,380), FONT_HERSHEY_SIMPLEX, 0.7, verde);
}


void datos(){

	namedWindow("Ventana");
	Dibujarinscrip(Ins);

	while(true){
		imshow("Ventana",Ins);
			if((waitKey(1)& 0XFF)==27)
			break;
				if (cerrar)
			break;
	}
}
void returnMenu();



void Dibujarreglas(Mat Rules){
	Point punto(10, 30);
	Point punto1(10, 70);
	Point punto1a(10, 85);
	Point punto1b(10, 100);
	Point punto1c(10, 115);
	Point punto2(10,145 );
	Point punto3(10, 180);
	Point punto4(10, 210);
	Point punto4a(10, 225);
	Point punto4b(10, 240);
	Point punto5(10, 285);
	Point punto5a(35, 300);
	Scalar negro = Scalar(0, 0, 0);
	float scala=0.5;
	putText(Rules,  "OBJETIVO DEL JUEGO:", punto, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "Puedes Ganar llenando los cuatro espacios del  ", punto1, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "medio con tus piezas o eliminando las piezas ", punto1a, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "de tu oponente, lo suficiente para que el ", punto1b, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "no pueda completar  el circulo de en medio.", punto1c, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "REGLAS:", punto2, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "1) Las piezas rojas siempre mueven primero.", punto3, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "2)Las piezas pueden moverse solo alrededor del", punto4, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "circulo (con las agujas del reloj o encontra de", punto4a, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "las agujas del reloj) y hacia dentro del circulo.", punto4b, FONT_HERSHEY_SIMPLEX, scala, negro);
	putText(Rules,  "3) Las piezas solo pueden moverse", punto5, FONT_HERSHEY_SIMPLEX, scala, negro);
		putText(Rules,"una vez por turno.", punto5a, FONT_HERSHEY_SIMPLEX, scala, negro);
	Rect mune(140,345,100,30);
	rectangle(Rules,mune,rojo,CV_FILLED);
	putText(Rules,"Menu",Point(170,370), FONT_HERSHEY_SIMPLEX, 0.8, blanco);

}

void reglas(){

	//Mat

	namedWindow("Ventana");
	Dibujarreglas(Rules);

	while(true){
		imshow("Ventana",Rules);
			if((waitKey(1)& 0XFF)==27)
			break;
				if (cerrar)
			break;
	}
}



//void Top10();

void Oldmouse(int event, int x, int y, int, void*){
	if (m==1){
		if (event==EVENT_LBUTTONUP){

				if (x >= 75 && x < 314 && y >= 75 && y <=147) {
					m=2;
					datos();
				}
				else if(x>=75 && x< 314 && y>=155 && y <=230){
					m=3;
					Top10();
				}
				else if (x>=75 && x< 314 && y>=250 && y <=324){
					cerrar=true;

				}
				else if (x>=75 && x< 314 && y>=335 && y <=395){
					m=3;
					reglas();
					
				}
		}
	}
	else if(m==2){
		if (event==EVENT_LBUTTONUP){
			if(x>=110 && x<383 && y>=65 && y<=95){
				//cout<<"cuadro de nombre"<<endl;
				int cont1=0,cont2=0,cont3=0,cont4=0;
				if (waitKey()){


					while (true && cont1==0){
						aux=waitKey();
						if(J1nombre.length()==5 or aux==13){
							break;}

							//aux=waitKey();
							J1nombre+=putchar(toupper(aux));
							putText(Ins,"-"+J1nombre,Point(115,90), FONT_HERSHEY_SIMPLEX,1,negro);
							//cout<<J1nombre<<endl;
						}

					}
				}
			else if (x>=110 && x<383 && y>=125 && y<=155 && J1nombre.length()!=0)	{
				//cout<<"cuadro de alias"<<endl;

					if (waitKey()){
						while (true){
							aux=waitKey();
							if(J1alias.length()==5 or aux==13)break;

							//aux=waitKey();
							J1alias+=putchar(toupper(aux));
							putText(Ins,"-"+J1alias,Point(115,150), FONT_HERSHEY_SIMPLEX,1,negro);
							//cout<<J1alias<<endl;



				}
				}
							}
			else if(x>=110 && x<383 && y>=245 && y<=275 && J1nombre.length()!=0 && J1alias.length()!=0){
				//cout<<"cuadro de nombre"<<endl;

				if (waitKey()){
					while (true){
						aux=waitKey();
						if(J2nombre.length()==5 or aux==13)break;


							J2nombre+=putchar(toupper(aux));
							putText(Ins,"-"+J2nombre,Point(115,270), FONT_HERSHEY_SIMPLEX,1,negro);
							//cout<<J2nombre<<endl;

					}}}
			else if (x>=110 && x<383 && y>=305 && y<=335 && J1nombre.length()!=0 && J1alias.length()!=0 && J2nombre.length())	{
				//cout<<"cuadro de alias"<<endl;

					if (waitKey()){
						while (true){
							aux=waitKey();
							if(J2alias.length()==5 or aux==13)break;


							J2alias+=putchar(toupper(aux));
							putText(Ins,"-"+J2alias,Point(115,330), FONT_HERSHEY_SIMPLEX,1,negro);
							//cout<<J1alias<<endl;


				}
				}
				}
		else if (x>=120 && x<=355 && y>=355 && y<=390 && J1nombre.length()!=0 && J2nombre.length()!=0 && J1alias.length()!=0 && J2alias.length()!=0 )
			{
					m=0;
					//cerrar=true;
					//DibujarTablero();
					tableroinic();
			}
		}
	}
	else if (m==3){
	if (event==EVENT_LBUTTONUP){
		if (x>=140 && x<238 && y>=345 && y<=375){
			m=1;
			Menu();}}
	}
}

void dibujarBmenu(Mat Menu){
	putText(Menu, "The Right Moves", Point(30,50), FONT_HERSHEY_SCRIPT_SIMPLEX, 1.5, Scalar(0,128,255));
    //imshow("Empate", Menu);

	Rect recPlay (75,75,240,73);
		rectangle(Menu, recPlay,rojo, CV_FILLED);
		putText(Menu,"Jugar!",Point(126,120), FONT_HERSHEY_SIMPLEX,1.5,blanco);
	Rect recScore (75,158,240,73);		rectangle(Menu, recScore,rojo,CV_FILLED);
		putText(Menu,"Puntuacion",Point(81,210), FONT_HERSHEY_SIMPLEX,1.3,blanco);
	Rect Exit (75,251,240,73);
		rectangle(Menu,Exit,rojo,CV_FILLED);
		putText(Menu,"Exit",Point(150,305), FONT_HERSHEY_SIMPLEX,1.5,blanco);
	Rect Help (75,336,240,60);
		rectangle(Menu,Help,rojo,CV_FILLED);
		putText(Menu,"Help",Point(150,380), FONT_HERSHEY_SIMPLEX,1.5,blanco);
}

void Menu(){
	Mat Menu (400,400,CV_8UC3,Scalar(153,255,153));
	namedWindow("Ventana");
	int option=0;
	dibujarBmenu(Menu);
	setMouseCallback("Ventana", Oldmouse);


	while (m==1)
	{
		imshow("Ventana", Menu);
		if (waitKey(5) == 27)
			break;
		if (cerrar)
			break;

	}
}


void inic()
{
	llenar();
	leerDatos();
	Menu();
	//return 0;
}

void Top10(){
	namedWindow("Ventana");

	setMouseCallback("Ventana", Oldmouse);
	DibujarTop();

	while (true )
	{
		imshow("Ventana", Top);
		if (waitKey(10) == 27) {break;
		break;}
				if (cerrar)
			break;
	}
}
