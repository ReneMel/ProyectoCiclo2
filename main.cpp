#include "tablero.h"
#include "dibujotablero.h"
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
	Dibujarinic();
	


	return 0;
}