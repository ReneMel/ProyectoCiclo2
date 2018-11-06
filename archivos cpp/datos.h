struct Jugador
{
	string name[200];
	string aka[200];
	int win[200];
}player;

void leerDatos(){
	int pt, r=0;
	char c[5];
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
			for (int i=12; i<score.length();i++){
				c[i-12]=score.at(i);
				pt=atoi(c);
			}
				for (int i =0; i<200;i++){ 

					if (player.name[i].length()==0){
						player.name[i]=Njugador;
						player.aka[i]=Ajugador;
						player.win[i]=pt;
						//cout <<player.win[i]<<endl;cout <<player.aka[i]<<endl;cout <<player.name[i]<<endl;
						Njugador="";
						Ajugador="";
						
						break;
					}
				}
		}
	}
	Datos.close();
	//cout<<"Orden de Leer Datos: "<<endl;
	//MostratTop();// lol
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
	//Nombre|AKA|puntaje
	Datos.close();
}


void ordenTop(){


	for (int i=0; i<=200; i++){
		for (int j=0; j<=199; j++){
			if (player.win[j]<player.win[j+1]){
			//ESTE CODIGO ES PARA ORDENAR EL WINS
				temp1=player.win[j];
				player.win[j]=player.win[j+1];
				player.win[j+1]=temp1;
			//ORDENAR EL NOMBRE
				tempN=player.name[j];
				player.name[j]=player.name[j+1];
				player.name[j+1]=tempN;
			// ORDENAR EL ALIAS
				tempA=player.aka[j];
				player.aka[j]=player.aka[j+1];
				player.aka[j+1]=tempA;
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

//CODIGO DE AQUÍ EN ADELANTE ES ACERCA DEL JUEGO CONECT4 
void llenar(){
	for (int i =0; i<200; i++){
		player.win[i]=0;
		player.name[i]= "";
		player.aka[i]= "";
	}              
}