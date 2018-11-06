#include "dibujotablero.h" 
#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace cv;

string J1nombre,J2nombre,J1alias,J2alias;
char aux;
int m=1;
bool cerrar = false; 


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




void DibujarTop(){
	Rect  titulo (90,10,210,30);
	rectangle (Top,titulo,verde,CV_FILLED);
	putText(Top, "-TOP 10-", Point(125,32), FONT_HERSHEY_TRIPLEX, 0.8, azul);

	Rect mune(140,345,100,30);
	rectangle(Top,mune,rojo,CV_FILLED);
	putText(Top,"Menu",Point(150,370), FONT_HERSHEY_SIMPLEX, 0.8, blanco);
	putText(Top,"A.K.A.",Point(90,70), FONT_HERSHEY_TRIPLEX, 0.8, Scalar(51,255,255));
	putText(Top,"Wins",Point(225,70), FONT_HERSHEY_TRIPLEX, 0.8, Scalar(51,255,255));


	int y=95;
	for (int i=0; i<11; i++){
		//if (player.name[i].length()>=0){
		//	ostringstream os;
		//	os<<player.win[i];
		//putText(Top, player.aka[i], Point(90,y),FONT_HERSHEY_PLAIN, 1.1, blanco);
		//putText(Top, os.str()+" pts.", Point(230,y), FONT_HERSHEY_PLAIN, 1.1, blanco);
		y+=25;
	//}	
	}
	int y2=95;
	for (int i=0; i<10; i++){
		//ostringstream os;
		//os<<player.win[i];
		//putText(Top, os.str()+" pts.", Point(230,y2), FONT_HERSHEY_PLAIN, 1.1, blanco);
		y2+=25;
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

void onMouse(int event, int x, int y, int, void*){
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
					cerrar=true;
					DibujarTablero();
			}
		}
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
	setMouseCallback("Ventana", onMouse);


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

	setMouseCallback("Ventana", onMouse);
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