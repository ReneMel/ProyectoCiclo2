#include "dibujotablero.h" 
#include <opencv2/opencv.hpp>
#include <iostream>
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
//bool cerrar =false;
bool endgame=false;
bool orden=false;
bool turn=false;

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
Scalar verde (0, 255, 0);
Scalar rojo (0,0,255);
Scalar azul (255,0,26);	
//Scalar amarillo(204,255,255);
Scalar naranja(0,102,204);

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
	if(turn){
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
					DibujarTablero();
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

/*void Menu(){
	Mat Menu (400,400,CV_8UC3,Scalar(153,255,153));
	namedWindow("Ventana");
	int option=0;
	dibujarBmenu(Menu);
	setMouseCallback("Ventana", onMouse);


	while (m==1)
	{
		imshow("Ventana", Menu);
		if (waitKey(5) == 27) 
			break;
		if (cerrar)
			break;
		
	}
}*/
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
/*
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
*/