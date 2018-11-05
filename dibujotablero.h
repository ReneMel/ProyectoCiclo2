#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
using namespace std;
using namespace cv;

Scalar negro = Scalar(0, 0, 0);
Scalar blanco = Scalar(255, 255, 255);
Mat ventana(600, 600, CV_8UC3, negro);

void dibujarAnillo(int radio, int casillas) {
	Point centro = Point(ventana.rows / 2, ventana.cols / 2);
	circle(ventana, centro, radio, blanco, 2);

	float angulo = 2 * 3.14159 / casillas;
	cout << "Dibujando casillas..." << endl;
	for (float i = 0; i < 2 * 3.14159; i += angulo) {
		cout << "angulo: " << i * 180 / 3.14159 << "\tgrados" << endl;
		Point casilla = Point(centro.x + radio*cos(i), centro.y + radio*sin(i));
		circle(ventana, casilla, 20, blanco, CV_FILLED);
	}
}

void Dibujarinic(){
	//Anillos de prueba
	//dibujarAnillo(200, 8);
	//dibujarAnillo(100, 4);

	//Dibujar Tableron
	dibujarAnillo(250, 16);
	dibujarAnillo(200, 16);
	dibujarAnillo(150, 16);
	dibujarAnillo(100, 8);
	dibujarAnillo(50, 4);

	imshow("Tablero", ventana);
	waitKey(0);

}