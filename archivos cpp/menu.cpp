#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
using namespace cv;

string J1nombre,J2nombre,J1alias,J2alias;
char aux;
int m=1;


Scalar negro(0, 0, 0);
Scalar blanco(255, 255, 255);
Scalar verde (0, 255, 0);
Scalar rojo (0,0,255);
Scalar azul (255,0,26);	
Scalar amarillo(204,255,255);
Scalar naranja(0,102,204);
bool bandera = false;
bool cerrar =false;
bool endgame=false;
bool orden=false;
Mat ventana(400, 400, CV_8UC3, amarillo);
Mat Ins(400,400, CV_8UC3, Scalar(204,204,255));
Mat Top(400,400, CV_8UC3, negro);

void dibujarBmenu(Mat Menu){
	putText(Menu, "-The right Move-", Point(10,50), FONT_HERSHEY_SCRIPT_SIMPLEX, 2, Scalar(0,128,255));
    //imshow("Empate", Menu);
	
	Rect recPlay (75,63,240,73); 
		rectangle(Menu, recPlay,rojo, CV_FILLED);
		putText(Menu,"Jugar!",Point(126,115), FONT_HERSHEY_SIMPLEX,1.5,blanco);
	Rect recScore (75,158,240,73);		rectangle(Menu, recScore,rojo,CV_FILLED); 
		putText(Menu,"Puntuacion",Point(81,210), FONT_HERSHEY_SIMPLEX,1.3,blanco);
	Rect Exit (75,251,240,73);
		rectangle(Menu,Exit,rojo,CV_FILLED); 
		putText(Menu,"Exit",Point(150,305), FONT_HERSHEY_SIMPLEX,1.5,blanco);	
}

void Menu(){
	Mat Menu (600,600,CV_8UC3,Scalar(153,255,153));
	namedWindow("Menu");
	int option=0;
	dibujarBmenu(Menu);
	//setMouseCallback("Ventana", onMouse);


	while (m==1)
	{
		imshow("Menu", Menu);
		if (waitKey(5) == 27) 
			break;
		if (cerrar)
			break;
		
	}
}
 int main(int argc, char const *argv[])
 {
 	Menu();
 	return 0;
 }