#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
using namespace std;
using namespace cv;


Scalar negro = Scalar(0, 0, 0);
Scalar blanco = Scalar(255, 255, 255);
Scalar amarillo(204,255,255);
Mat ventana(600, 600, CV_8UC3, negro);

void MouseTab(int event, int x, int y, int, void*){

}

void dibujarAnillo(int radio, int casillas) {
	int r=1;
	Point centro = Point(ventana.rows / 2, ventana.cols / 2);
	circle(ventana, centro, radio, blanco, 2);
	circle(ventana, centro, radio+25, amarillo, 0.1);

	float angulo = 2 * 3.14159 / casillas;
	cout << "Dibujando casillas..." << endl;
	for (float i = 0; i < 2 * 3.14159; i += angulo) {
		cout << "angulo: " << i * 180 / 3.14159 << "\tgrados" << endl;
		Point casilla = Point(centro.x + radio*cos(i), centro.y + radio*sin(i));
		circle(ventana, casilla, 20, blanco, CV_FILLED);
		//conecciones anillos 2 y 3 
		Point l1=Point(centro.x+200*cos(i), centro.y+200*sin(i));
		Point l2=Point(centro.x+150*cos(i), centro.y+150*sin(i));
		line(ventana,l1,l2,blanco,3);
		// Conecciones  anillos 3 y 4
		Point l3=Point(centro.x+150*cos(i), centro.y+150*sin(i));
		Point l4=Point(centro.x+100*cos(i), centro.y+100*sin(i));
		if (r%2!=0 ){
		line(ventana,l3,l4,blanco,3);
	}
		r++;

	}
}

void dibujarlineas(){
	Point inicio =Point(ventana.rows/2,50);
	Point final = Point(ventana.rows/2,550);
	line(ventana, inicio,final,blanco,3);
	inicio=Point(50,300);
	final = Point(550,300);
	line(ventana, inicio,final,blanco,3);
	
	inicio=Point(115,224);
	final = Point(160,240);
	line(ventana, inicio,final,blanco,3);
//1 3 5 7 9 11 13 15
}

int main(){
	//Anillos de prueba
	//dibujarAnillo(200, 8);
	//dibujarAnillo(100, 4);

	//Dibujar Tableron
	dibujarAnillo(250, 16);
	dibujarAnillo(200, 16);
	dibujarAnillo(150, 16);
	dibujarAnillo(100, 8);
	dibujarAnillo(50, 4);
	dibujarlineas();

	imshow("Tablero", ventana);
	waitKey(0);
	setMouseCallback("Tablero",MouseTab);

	return 0;
}

