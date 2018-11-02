#include <iostream>
#include <stdlib.h>

using namespace std;

struct Casilla			//Casilla norte
{
	int color; 			//COLOR 0 ES IGUAL A NO COLOR  COLOR 1 ES IGUAL A ROJO  COLOR 2 IGUAL AZUL
	Casilla*sig;
	Casilla*ant;
	Casilla*up;
	Casilla*down;
}*lsinicio, *lsfinal, 
*NorteA, *OesteA, *SurA, *EsteA,
*NorteB, *OesteB, *SurB, *EsteB,
*NorteC, *OesteC, *SurC, *EsteC,
*NorteD, *OesteD, *SurD, *EsteD,
*NorteE, *OesteE, *SurE, *EsteE;

 

void crearTablero(){
	//CREANDO ANILLOS DEL UNO AL 3 CON 16 CASILLAS 
	for (int k=0; k<3; k++){
		for (int i=0; i<16; i++){
			Casilla*novo= new Casilla;
			if (lsinicio==NULL){
				lsinicio=novo;
				lsinicio->sig=lsinicio;
				lsinicio->ant=lsinicio;
				lsfinal= lsinicio;
				lsinicio->color=0;
				if (k==0){
					NorteA=novo;
				}
				else if (k==1){
					NorteB=novo;
				}
				else if (k==2){
					NorteC=novo;
				}
			}
			else {
				lsfinal->sig=novo;
				novo->sig=lsinicio;
				novo->ant=lsfinal;
				lsfinal=novo;
				lsinicio->ant=lsfinal;
				if (i==4 and k==0){
					OesteA=novo;
					OesteA->color=0;
				}
				else if (i==8 and k==0){
					SurA=novo;
					SurA->color=0;
				}
				else if (i==12 and k==0){
					EsteA=novo;
					EsteA->color=0;
				}
				else if (i==4 and k==1){
					OesteB=novo;
					OesteB->color=0;
				}
				else if (i==8 and k==1){
					SurB=novo;
					SurB->color=0;
				}
				else if (i==12 and k==1){
					EsteB=novo;
					EsteB->color=0;
				}
				else if (i==4 and k==2){
					OesteC=novo;
					OesteC->color=0;
				}
				else if (i==8 and k==2){
					SurC=novo;
					SurC->color=0;
				}
				else if (i==12 and k==2){
					EsteC=novo;
					EsteC->color=0;
				}
			}
		}
		lsinicio=NULL;
	}
	lsinicio=NULL;

	for (int i=0; i<8;i++){
		Casilla*novo= new Casilla;
		if (lsinicio==NULL){
				lsinicio=novo;
				lsinicio->sig=lsinicio;
				lsinicio->ant=lsinicio;
				lsfinal=lsinicio;
				NorteD=novo;
				
			}
		else {
			lsfinal->sig=novo;
			novo->sig=lsinicio;
			novo->ant=lsfinal;
			lsfinal=novo;
			lsinicio->ant=lsfinal;

			if (i==2){
				OesteD=novo;
				OesteD->color=0;
			}
			else if (i==4){
				SurD=novo;
				SurD->color=0;
			}
			else if (i==6){
				EsteD=novo;
				EsteD->color=0;
			}
		}

	}
	lsinicio=NULL;
	//Creando anillo ultimo E

	for (int i=0;i<4;i++){
		Casilla*novo= new Casilla;
		if (lsinicio==NULL){
				lsinicio=novo;
				lsinicio->sig=lsinicio;
				lsinicio->ant=lsinicio;
				lsfinal=lsinicio;
				NorteE=novo;
				
			}
		else {
			lsfinal->sig=novo;
			novo->sig=lsinicio;
			novo->ant=lsfinal;
			lsfinal=novo;
			lsinicio->ant=lsfinal;

			if (i==1){
				OesteE=novo;
				OesteE->color=0;
			}
			else if (i==2){
				SurE=novo;
				SurE->color=0;
			}
			else if (i==3){
				EsteE=novo;
				EsteE->color=0;
			}
		}
	}
}

void conectar(){
	//UNIENDO LINEA NORTE **VER IMAGEN DEL ESQUEMA 
	NorteA->up=NULL;
	NorteA->down=NorteB;
	NorteB->up=NorteA;
	NorteB->down=NorteC;
	NorteC->up= NorteB;
	NorteC->down=NorteD;
	NorteD->up=NorteC;
	NorteD->down=NorteE;
	NorteE->up=NorteD;

	//UNIENDO PARTE SUR
	NorteE->down=SurE;
	SurE->up=NorteE;
	SurE->down=SurD;
	SurD->up= SurE;
	SurD->down=SurC;
	SurC->up=SurD;
	SurC->down=SurB;
	SurB->up=SurC;
	SurB->down=SurA;
	SurA->up=SurB;
	SurA->down=NULL;

	//Uniendo parte ESTE
	EsteA->up=NULL;
	EsteA->down=EsteB;
	EsteB->up=EsteA;
	EsteB->down=EsteC;
	EsteC->up=EsteB;
	EsteC->down=EsteD;
	EsteD->up= EsteC;
	EsteD->down=EsteE;
	EsteE->up=EsteD;
	// pARTE OESTE
	EsteE->down=OesteE;
	OesteE->up= EsteE;
	OesteE->down= OesteD;
	OesteD->up=	OesteE;
	OesteD->down=OesteC;
	OesteC->up=OesteD;
	OesteC->down=OesteB;
	OesteB->up= OesteC;
	OesteB->down= OesteA;
	OesteA->up=OesteB;
	OesteA->down=NULL;

	// CONECIONES VERGONAS DE LOS DEMAS PUNTOS
	(NorteC->sig)->up=(NorteB->sig);
	(NorteB->sig)->down=(NorteC->sig);

	((NorteC->sig)->sig)->up=((NorteB->sig)->sig);
	((NorteB->sig)->sig)->down=((NorteC->sig)->sig);

	(((NorteC->sig)->sig)->sig)->up=(((NorteB->sig)->sig)->sig);
	(((NorteB->sig)->sig)->sig)->down=(((NorteC->sig)->sig)->sig);

//CONECCIONES COLOR AZUL OESTE
	(OesteC->sig)->up=(OesteB->sig);
	(OesteB->sig)->down=(OesteC->sig);

	((OesteC->sig)->sig)->up=((OesteB->sig)->sig);
	((OesteB->sig)->sig)->down=((OesteC->sig)->sig);

	(((OesteC->sig)->sig)->sig)->up=(((OesteB->sig)->sig)->sig);
	(((OesteB->sig)->sig)->sig)->down=(((OesteC->sig)->sig)->sig);

//CONECCIONES COLOR ROJO  SUR
	(SurC->sig)->up=(SurB->sig);
	(SurB->sig)->down=(SurC->sig);

	((SurC->sig)->sig)->up=((SurB->sig)->sig);
	((SurB->sig)->sig)->down=((SurC->sig)->sig);

	(((SurC->sig)->sig)->sig)->up=(((SurB->sig)->sig)->sig);
	(((SurB->sig)->sig)->sig)->down=(((SurC->sig)->sig)->sig);
//CONECCIONES COLOR AZUL ESTE

	(EsteC->sig)->up=(EsteB->sig);
	(EsteB->sig)->down=(EsteC->sig);

	((EsteC->sig)->sig)->up=((EsteB->sig)->sig);
	((EsteB->sig)->sig)->down=((EsteC->sig)->sig);

	(((EsteC->sig)->sig)->sig)->up=(((EsteB->sig)->sig)->sig);
	(((EsteB->sig)->sig)->sig)->down=(((EsteC->sig)->sig)->sig);

	//CONECCIONES CON EL ANILLO 5

	(NorteD->sig)->up=((NorteC->sig)->sig);
	((NorteC->sig)->sig)->down=(NorteD->sig);

	(OesteD->sig)->up=((OesteC->sig)->sig);
	((OesteC->sig)->sig)->down=(OesteD->sig);

	(SurD->sig)->up=((SurC->sig)->sig);
	((SurC->sig)->sig)->down=(SurD->sig);

	(EsteD->sig)->up=((EsteC->sig)->sig);
	((EsteC->sig)->sig)->down=(EsteD->sig);
}


void ver_conecciones(){
	Casilla*aux=new Casilla;
	aux= NorteA;
	int i=100;
	cout<<"Dato:  ANILLO 1:"<<endl;

	do{
		aux->color=i;
		i++;
		cout<<aux->color<<endl;
		aux=aux->sig;

	}while (aux!=NorteA);

	aux= NorteB;
	i=200;
	cout<<"Dato:  ANILLO 2:"<<endl;

	do{
		aux->color=i;
		i++;
		cout<<aux->color<<endl;
		aux=aux->sig;

	}while (aux!=NorteB);

	aux= NorteC;
	i=300;
	cout<<"Dato:  ANILLO 3:"<<endl;
	do{
		aux->color=i;
		i++;
		cout<<aux->color<<endl;
		aux=aux->sig;

	}while (aux!=NorteC);

	aux= NorteD;
	i=400;

	cout<<"Dato:  ANILLO 4:"<<endl;

	do{
		aux->color=i;
		i++;
		cout<<aux->color<<endl;
		aux=aux->sig;

	}while (aux!=NorteD);

	aux= NorteE;
	i=500;
	cout<<"Dato:  ANILLO 5:"<<endl;

	do{
		aux->color=i;
		i++;
		cout<<aux->color<<endl;
		aux=aux->sig;

	}while (aux!=NorteE);

}

void con_entreanillos(){
	cout<<"COMPROBANDO CONECCIONES DE CASILLAS!!!!!!!!!!"<<endl;
	Casilla*aux=new Casilla;
	aux=NorteA;
	do{
		cout<<"Nodo: "<<aux->color<<endl;
		if((aux->up)!=NULL){
			cout<<"TAmbien esta conectada hacia arriba: "<<(aux->up)->color<<endl;
		}
		if (aux->down!=NULL){
				cout<<" Conectado hacia abajo con:  "<<(aux->down)->color<<endl;
			}
		aux=aux->sig;

	}while (aux!=NorteA);
	aux=NorteB;
	do{
		cout<<"Nodo: "<<aux->color<<endl;
		if((aux->up)!=NULL){
			cout<<"TAmbien esta conectada hacia arriba: "<<(aux->up)->color<<endl;
		}
		if (aux->down!=NULL){
				cout<<" Conectado hacia abajo con:  "<<(aux->down)->color<<endl;
			}
		aux=aux->sig;

	}while (aux!=NorteB);

aux=NorteC;
	do{
		cout<<"Nodo: "<<aux->color<<endl;
		if((aux->up)!=NULL){
			cout<<"TAmbien esta conectada hacia arriba: "<<(aux->up)->color<<endl;
		}
		if (aux->down!=NULL){
				cout<<" Conectado hacia abajo con:  "<<(aux->down)->color<<endl;
			}
		aux=aux->sig;

	}while (aux!=NorteC);

aux=NorteD;
	do{
		cout<<"Nodo: "<<aux->color<<endl;
		if((aux->up)!=NULL){
			cout<<"TAmbien esta conectada hacia arriba: "<<(aux->up)->color<<endl;
		}
		if (aux->down!=NULL){
				cout<<" Conectado hacia abajo con:  "<<(aux->down)->color<<endl;
			}
		aux=aux->sig;

	}while (aux!=NorteD);

aux=NorteE;
	do{
		cout<<"Nodo: "<<aux->color<<endl;
		if((aux->up)!=NULL){
			cout<<"TAmbien esta conectada hacia arriba: "<<(aux->up)->color<<endl;
		}
		if (aux->down!=NULL){
				cout<<" Conectado hacia abajo con:  "<<(aux->down)->color<<endl;
			}
		aux=aux->sig;

	}while (aux!=NorteE);


}

int main(int argc, char const *argv[])
{
	crearTablero();
	conectar();
	ver_conecciones();
	con_entreanillos();
	return 0;
}