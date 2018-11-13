#include "tablero.h"
//#include "dibujotablero.h"
#include "menu.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
using namespace cv;


int main(int argc, char const *argv[])
{
	Tablero juego;
	juego.llenar();
	inic();

	return 0;
}