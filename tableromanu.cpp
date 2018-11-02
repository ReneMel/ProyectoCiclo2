// Tablero manera manual 
#include <iostream>
#include <stdlib.h>

using namespace std;

struct CasillaCard		//Casilla de puntos cardinales
{
	int color;
	CasillaCard*next=NULL;
	CasillaCard*prev=NULL;
	CasillaCard*up=NULL;
	CasillaCard*down=NULL;
};

struct Casilla
{
	int color;
	Casilla*next=NULL;
	Casilla*prev=NULL;
	Casilla*up=NULL;
	Casilla*down=NULL;
};

void inicanillo1(){
	Casilla*ANORTE=new Casilla;  	//Hacre referencia a la casilla Norte del anillo uno, afuera hacia adentro
	Casilla*AA=new Casilla;		
	Casilla*AB=new Casilla;
	Casilla*AC=new Casilla;
	
	Casilla*AOESTE=new Casilla;
	Casilla*AD=new Casilla;		
	Casilla*AE=new Casilla;
	Casilla*AF=new Casilla;
	
	Casilla*ASUR=new Casilla; 
	Casilla*AG=new Casilla;		
	Casilla*AH=new Casilla;
	Casilla*AI=new Casilla;
	
	Casilla*AESTE=new Casilla; 
	Casilla*AJ=new Casilla;		
	Casilla*AK=new Casilla;
	Casilla*AL=new Casilla;

	ANORTE->color=0;
	AA->color=1;
	AB->color=1;
	AC->color=1;

	ANORTE->next=AA;
	AA->prev=ANORTE;
	AA->next=AB;
	AB->prev=AA;
	AB->next=AC;
	AC->prev=AB;
//PUNTO OESTE
	AOESTE->color=0;
	AD->color=2;
	AE->color=2;
	AF->color=2;

	AC->next=AOESTE;
	
	AOESTE->prev=AC;
	AOESTE->next=AD;
	AD->prev=AOESTE;
	AD->next=AE;
	AE->prev=AD;
	AE->next=AF;
	AF->prev=AE;
// PUNTO SUR;
	ASUR->color=0;
	AJ->color=1;
	AK->color=1;
	AL->color=1;

	AF->next=ASUR;
	ASUR->prev=AF;
	ASUR->next=AJ;
	AG->prev=ASUR;
	AG->next=AH;
	AH->prev=AG;
	AH->next=AI;
	AI->prev=AH;

//PUNTO ESTE 
	AESTE->color=0;
	AJ->color=2;
	AK->color=2;
	AL->color=2;

	AI->next=AESTE;
	AESTE->prev=AI;
	AESTE->next=AJ;
	AJ->prev=AESTE;
	AJ->next=AK;
	AK->prev=AJ;
	AK->next=AL;
	AL->prev=AK;

	//ANILLO 1 FINALIZAR
	AK->next=ANORTE;
	ANORTE->prev=AK;

	//COMIENZA ANILLO 2
}

int main(int argc, char const *argv[])
{
	cout<<"Lista preparada"<<endl;
	inicanillo1();
	cout<<AA->dato;
	return 0;
}