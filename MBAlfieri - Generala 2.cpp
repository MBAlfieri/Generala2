#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <stdio.h>
using namespace std;

//------------------------------------------------------------------------------Clase "Dado"
class Dado{
	
private:
	int numeroDado; //Valor de cada cara del dado
	
public:	
	Dado(){};
	Dado(int _numeroDado); //Constructor.
	void setDado(); //Le dará un valor al azar al dado.
	int getDado(); //Me permitirá ver el dado.
};


Dado::Dado(int _numeroDado){ //Constructor
	numeroDado = _numeroDado;
}


void Dado::setDado(){ //Le dará un valor al azar al dado.
	numeroDado = rand()%6+1;
}


int Dado::getDado(){ //Me permitirá ver el dado.
	return numeroDado;
}



//------------------------------------------------------------------------------Clase "Cubilete"
class Cubilete{
	
private:
	Dado Dado_en_cubilete[5]; //Se almacenarán los dados de la clase "Dado"	
	
public:
	Cubilete(){}; //Constructor. Son los dados que recibiré de la clase "Dado"
	void generarCubilete(Dado UnidadDado);//Carga los dados en el cubilete.
	void getDados();//Muestra los valores de los dados.
	void setOrden(); //Ordena el array de dados, de menor a mayor.
	void setCambioDados(); //Me permite decidir que dados voy a mantener y cuales voy a descartar.
	int getDadoIndividual1(int numDado); //Me permite obtener los dados individualmente para luego dárselos a la clase "Reglas"	
	int getDadoIndividual2(int numDado); // Idem
	int getDadoIndividual3(int numDado); // Idem
	int getDadoIndividual4(int numDado); //	Idem
	int getDadoIndividual5(int numDado); // Idem
	
};


void Cubilete::generarCubilete(Dado UnidadDado){ //Carga los dados en el cubilete.
	for(int i=0;i<5;i++){
		UnidadDado.setDado(); //Me da un dado al azar.
		Dado_en_cubilete[i] = UnidadDado; //Guardo el dado randomizado en el array.
	}	
}


void Cubilete::getDados(){ //Muestra los valores de los dados.
	for (int i = 0; i<5; i++){
		cout << "   Valor del Dado "<<i+1<<": "<<Dado_en_cubilete[i].getDado() << endl;
	}
}


void Cubilete::setCambioDados(){  //Me permite decidir que dados voy a mantener y cuales voy a descartar.
	for(int i = 0; i<5;i++){
		cout << endl;
		cout<<"   ¿Quieres quedarte con el Dado "<<i+1<<"? (Éste vale "<<Dado_en_cubilete[i].getDado()<< "): s/n" << endl;
		
		switch(getch()){
		case 's': case 'S':
			cout << endl;
			cout << "-->¡Te has quedado con el dado!" << endl;
			break;
			
		case 'n': case 'N':
			Dado_en_cubilete[i] = rand()%6+1;
			cout << endl;
			cout<<"-->¡Te has deshecho del dado!" << endl;
			break;
		}
	}	
}



void Cubilete::setOrden(){ //Ordena el array de dados, de menor a mayor.
	Dado min;
	Dado temp;
	
	for (int i = 0; i < 7 - 1; i++) {
		min = i;
		for (int j = i + 1; j < 5; j++)
			if (Dado_en_cubilete[j].getDado() < Dado_en_cubilete[min.getDado()].getDado())
				min = j;
		temp = Dado_en_cubilete[i].getDado();
		Dado_en_cubilete[i] = Dado_en_cubilete[min.getDado()].getDado();
		Dado_en_cubilete[min.getDado()] = temp;
	}
}



int Cubilete::getDadoIndividual1(int numDado){ //Me permite obtener los dados individualmente para luego dárselos a la clase "Reglas".
	numDado = Dado_en_cubilete[0].getDado(); //"Convierto" el Dado en un int, para luego poder pasarlo.
	return numDado;
}

int Cubilete::getDadoIndividual2(int numDado){ //Idem
	numDado = Dado_en_cubilete[1].getDado(); 
	return numDado;
}

int Cubilete::getDadoIndividual3(int numDado){ //Idem
	numDado = Dado_en_cubilete[2].getDado(); 
	return numDado;
}

int Cubilete::getDadoIndividual4(int numDado){ //Idem
	numDado = Dado_en_cubilete[3].getDado(); 
	return numDado;
}

int Cubilete::getDadoIndividual5(int numDado){ //Idem
	numDado = Dado_en_cubilete[4].getDado();
	return numDado;
}




//------------------------------------------------------------------------------Clase "Reglas"
class Reglas{
private: 
	int PuntosTotales;//Son los puntos que se ganan en cada jugada individual.
	
public:
	int Dados_en_Reglas[5];
	Reglas(int aux[5]); //Constructor para los dados
	Reglas(int puntos_aux); //Constructor para los puntos
	void DadosReglas(int aux[5]); //Recibo los Dados.
	void setNumeroUno(int aux[5]); //Jugada del Uno.
	void setNumeroDos(int aux[5]); // Jugada del Dos.	
	void setNumeroTres(int aux[5]); // Jugada del Tres.
	void setNumeroCuatro(int aux[5]); // Jugada del Cuatro.
	void setNumeroCinco(int aux[5]); // Jugada del Cinco.
	void setNumeroSeis(int aux[5]); // Jugada del Seis.
	void setFull(int aux[5]); // Jugada del Full.
	void setEscalera(int aux[5]); // Jugada de la Escalera.
	void setPoker(int aux[5]); // Jugada del Poker.
	void setGenerala(int aux[5]); // Jugada de la Generala.
	int getpuntos(); //Me permite guardar los puntos entre cada juego.
	void setpuntos(); //Me permite dejar en 0 los puntos una vez que se realizó la jugada.
	
};

Reglas::Reglas(int aux[5]){ //Constructor 1.
	Dados_en_Reglas[5] = aux[5];
}

Reglas::Reglas(int puntos_aux){ //Constructor 2.
	PuntosTotales = puntos_aux;
}


void Reglas::DadosReglas(int aux[5]){ //Recibo los Dados.
	for (int i = 0; i<5; i++){
		cout << "   Valor del Dado "<<i+1<<": "<<aux[i]<< endl;
	}
}

void Reglas::setNumeroUno(int aux[5]){ //Jugada del Uno.
	for(int i=0;i<5;i++){
		if(aux[i]==1){
			PuntosTotales++;
		}
	}
}

void Reglas::setNumeroDos(int aux[5]){ //Jugada del Dos.
	for(int i=0;i<5;i++){
		if(aux[i]==2){
			PuntosTotales += 2;
		}
	}
}


void Reglas::setNumeroTres(int aux[5]){ //Jugada del Tres.
	for(int i=0;i<5;i++){
		if(aux[i]==3){
			PuntosTotales += 3;
		}
	}
}


void Reglas::setNumeroCuatro(int aux[5]){ //Jugada del Cuatro.
	for(int i=0;i<5;i++){
		if(aux[i]==4){
			PuntosTotales += 4;
		}
	}
}


void Reglas::setNumeroCinco(int aux[5]){ //Jugada del Cinco.
	for(int i=0;i<5;i++){
		if(aux[i]==5){
			PuntosTotales += 5;
		}
	}
}

void Reglas::setNumeroSeis(int aux[5]){ //Jugada del Seis.
	for(int i=0;i<5;i++){
		if(aux[i]==6){
			PuntosTotales += 6;
		}
	}
}


void Reglas::setFull(int aux[5]){ //Jugada del Full.
	if( ((aux[0] == aux[1]) && (aux[2] == aux[3]) && (aux[3] == aux[4])) || ((aux[0] == aux[1]) && (aux[1] == aux[2]) && (aux[3] == aux[4])))
	{
		PuntosTotales = 30;
	}
	else {
		PuntosTotales = 0;
	}
}


void Reglas::setEscalera(int aux[5]){ //Jugada de la Escalera.
	if( ((aux[0]== 1) && (aux[1]== 2) && (aux[2]== 3) && (aux[3]== 4) && (aux[4]== 5)) || ((aux[0]== 2) && (aux[1]== 3) && (aux[2]== 4) && (aux[3]== 5) && (aux[4]== 6))){
		PuntosTotales += 40;
	}
	else {
		PuntosTotales = 0;
	}	
}

void Reglas::setPoker(int aux[5]){ //Jugada del Poker.
	if( ((aux[0] == aux[1]) && (aux[1] == aux[2]) && (aux[2] == aux[3])) || ((aux[1] == aux[2]) && (aux[2] == aux[3]) && (aux[3] == aux[4]))){
		PuntosTotales += 50;
	}
	else {
		PuntosTotales = 0;
	}	
}


void Reglas::setGenerala(int aux[5]){ //Jugada de la Generala.
	if( ((aux[0] == aux[1]) && (aux[1] == aux[2]) && (aux[2] == aux[3])&& (aux[3] == aux[4]))){
		PuntosTotales += 60;
	}
	else {
		PuntosTotales = 0;
	}
	
}


int Reglas::getpuntos(){ //Me devuelve los puntos de cada Jugada invidivual.
	return PuntosTotales;
}

void Reglas::setpuntos(){ //Una vez que hice una jugada, dejo los puntos ganados en cero, para no acarrearlos en la próxima ronda.
	PuntosTotales = 0;
}




//------------------------------------------------------------------------------Clase "Jugador"
class Jugador{
private:
	string Nombre_Jugador; //Guarda el nombre del Jugador
	int Puntos; //Los puntos del jugador
	
public:
	Jugador(){};
	Cubilete cubi;/*El cubilete del jugador. De todos modos, es un poco redundante en mi código, en el sentido de
	que el Cubilete solo es necesario para la clase "Reglas", considerando que es la encargada de revisarlo en búsqueda
	de jugadas. De todos modos, si este razonamiento está mal, me hago cargo de mi error.*/
	void setNombreJugador(); //Define el nombre del Jugador.
	string getNombreJugador();	 //Me muestra el nombre del Jugador.
	int setPuntosJugador();
};


void Jugador::setNombreJugador(){ //Me permite ingresar el nombre del jugador.
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;	
	cout << "                      ¡Ingrese el nombre del Jugador!    " << endl << endl;
	cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;	
	cout << "-->";
	cin >> Nombre_Jugador;
	
}


string Jugador::getNombreJugador(){ //Muestra el nombre del jugador.
	return Nombre_Jugador;
}



//------------------------------------------------------------------------------Bool
//Bool para el funcionamiento del juego.
bool juego = true; //Define si el juego continúa o no.
bool bnumerouno = false; //Estos Bool me permiten revisar si es que un juego ya se ha realizado o no. 
bool bnumerodos = false; //Idem
bool bnumerotres = false; //Idem
bool bnumerocuatro = false; //Idem
bool bnumerocinco = false;  //Idem
bool bnumeroseis = false; //Idem
bool bfull = false; //Idem
bool bescalera = false; //Idem
bool bpoker = false; //Idem
bool bgenerala = false; //Idem


//------------------------------------------------------------------------------Variables
//Variables del Main.
int numeroJugadores; // Indica la cantidad de jugadores. En este caso el límite será 2 jugadores.
int mano; //Define la cantidad de manos que tendrá el juego, en total.
int Dados_J1[5]; //Dados del primer Jugador. Más que nada es una variable auxiliar.
int PuntosJugador; //Son los puntos del jugador. Idem al caso anterior.




//------------------------------------------------------------------------------Clases
//Clases.
Jugador Jugador_J1;	//Primer Jugador.
Dado Dado_J1; //Dados del Primer Jugador.
Cubilete Cubilete_J1; //Cubilete del Primer Jugador.
Reglas Reglas_J1(Dados_J1); //Reglas para el Primer Jugador.


//------------------------------------------------------------------------------Main
int main(int argc, char *argv[]) {
	srand (time(NULL));
	
	system("Color 0B"); // Cambia el color de la Consola.
	
	
	while((juego == true)){ //Menú principal del juego.
		
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;	//Introducción	
		cout << "                 ¡¡Bienvenido a la Generala Virtual 2.0!!                       " << endl;
		cout << "                            ¿Que desea hacer?                                   " << endl << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;	
		cout << endl;
		cout << "            ¡Presione la tecla -A- para iniciar una partida!                    " << endl;
		cout << "            ¡Presione la tecla -B- para leer las reglas!                        " << endl;
		cout << "            ¡Presione la tecla -C- para ver los créditos                        " << endl;
		cout << "            ¡Presione la tecla -D- para salir!                                  " << endl << endl;
		cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;	
		
		switch(getch()){
			
		case 'a': case 'A':
			system ("CLS"); //"Limpia" la pantalla.
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
			cout << "                       ¡Ha iniciado una partida!                                " << endl << endl;
			cout << "         ¡Por favor, ingrese con números la cantidad de jugadores!              " << endl << endl;
			cout << "          (Esta versión de la generala solo acepta -1- sólo jugador)            " << endl << endl;
			cout << "(¡Si desea jugar con sus amigos, por favor, descargue la versión 1.0 del juego!)" << endl << endl;
			cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
			cout << "-->";
			
			cin >> numeroJugadores; //Guarda el número de jugadores.
			
			if(numeroJugadores>1){ //En caso de que el jugador ingrese un número de participantes mayor a 1.
				system ("CLS");
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                                     ...                                        " << endl;
				cout << "                       ¿No ha leído las instrucciones? :(                       " << endl;
				cout << "             La Generala Virtual 2.0 no es un juego multijugador...             " << endl;
				cout << "   Si desea jugar con sus amigos, por favor, descargue la Generala Virtual 1.0  " << endl;
				cout << "               Es más, le daré un Link de descarga a la misma.                  " << endl;
				cout << "https://drive.google.com/file/d/1XxmLOmC8gaJMMgoGsj5qyIEzEouOJbGn/view?usp=sharing" << endl << endl;
				cout << "                          ¿Bien? ¡Que lo disfrute! :)                        " << endl;
				//Esto es un chiste, cabe aclarar. Y si, el link realmente funciona.
				/*De todos modos, me he tomado el atrevimiento de dejarlo para 1 solo jugador. Si esto no correspondía, entonces
				Me hago cargo de mi error, y pido disculpas.*/
				cout << "                         Volvamos al menú principal...                          " << endl << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
				system("pause");
				system ("CLS");
				break;}
			
			system ("CLS");
			
			if(numeroJugadores==1){ //En caso de ser 1 solo Jugador.
				
				Jugador_J1.setNombreJugador(); //Define el nombre del jugador número 1.
				
				system ("CLS");
				
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;		
				cout << "                       Su nombre es " << Jugador_J1.getNombreJugador() << " ¿Cierto? " << endl << endl; //Muestra el nombre del Jugador.
				cout << "                             ¡Mucho gusto!                                     " << endl << endl;
				cout << "                      Entonces, ¡Empecemos el juego!                            " << endl;
				cout << "                            ¡¡Buena Suerte!!                                    " << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl;
				system ("pause");
				system ("CLS");
				
				while(mano<10){ //Define la duración del juego.
					cout << endl;
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl << endl; //Inicia la partida.
					cout << "                      ¡Procederé a tirar los dados!                             " << endl;
					cout << "                                   ...                                          " << endl;
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
					
					Cubilete_J1.generarCubilete(Dado_J1); //Genero el Cubilete con sus respectivos dados.
					
					for(int i=0;i<3;i++)//Con ésto hago que el jugador lanze/cambie los dados solo 3 veces por ronda.	
					{ 
						cout << "   Entonces, tus Dados son: " << endl << endl;	
						Cubilete_J1.getDados(); //Muestro los dados.
						Cubilete_J1.setCambioDados(); //Permite decidir que dados mantener, y cuales descartar.
						system ("CLS");
					}
					
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
					cout << "                      ¡Es hora de elegir tu juego!                              " << endl << endl;
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
					
					Cubilete_J1.setOrden(); //Ordeno los dados de menor a mayor. Útil para facilitar la detección de jugadas.
					
					Dados_J1[0] = Cubilete_J1.getDadoIndividual1(0); //Deposito los dados en un array para luego pasarlos a la clase "Reglas"
					Dados_J1[1] = Cubilete_J1.getDadoIndividual2(1);
					Dados_J1[2] = Cubilete_J1.getDadoIndividual3(2);
					Dados_J1[3] = Cubilete_J1.getDadoIndividual4(3);
					Dados_J1[4] = Cubilete_J1.getDadoIndividual5(4);
					
					Reglas_J1.DadosReglas(Dados_J1); //Le paso los dados a las Reglas;
					
					
					cout << endl << endl;
					
					//Las opciones serán visibles siempre y cuando no se las haya usado anteriormente.
					if(bnumerouno == false){
						cout <<"   Presiona la tecla -1- para el Uno!" << endl;}
					if(bnumerodos == false){
						cout <<"   Presiona la tecla -2- para el Dos!" << endl;}
					if(bnumerotres== false){
						cout <<"   Presiona la tecla -3- para el Tres!" << endl;}
					if(bnumerocuatro == false){
						cout <<"   Presiona la tecla -4- para el Cuatro!" << endl;}
					if(bnumerocinco == false){
						cout <<"   Presiona la tecla -5- para el Cinco!" << endl;}
					if(bnumeroseis == false){
						cout <<"   Presiona la tecla -6- para el Seis!" << endl;}
					if(bfull == false){
						cout <<"   Presiona la tecla -F- para el Full!" << endl;}
					if(bescalera == false){
						cout <<"   Presiona la tecla -E- para la Escalera!" << endl;}
					if(bpoker == false){
						cout <<"   Presiona la tecla -P- para el Poker!" << endl;}
					if(bgenerala == false){
						cout <<"   Presiona la tecla -G- para la Generala!" << endl;}
					
					
					switch(getch()){
					case '1': //El Uno
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Uno!!" << endl << endl ;
						
						Reglas_J1.setNumeroUno(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos(); //Deposito los puntos en el Main, para verificar si se ha ganado algo o no.
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!! "<< endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bnumerouno = true; //Como ya se ha utilizado esta jugada, se vuelve true
						break;
						
					case '2': //El Dos
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Dos!!" << endl << endl ;
						
						Reglas_J1.setNumeroDos(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bnumerodos = true; //Como ya se ha utilizado esta jugada, se vuelve true
						break;
						
					case '3': //El tres
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Tres!!" << endl << endl ;
						
						Reglas_J1.setNumeroTres(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bnumerotres = true;
						
						break;
						
					case '4': //El cuatro
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Cuatro!!" << endl << endl ;
						
						Reglas_J1.setNumeroCuatro(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						bnumerocuatro = true;
						break;
						
					case '5': //El Cinco
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Cinco!!" << endl << endl ;
						
						Reglas_J1.setNumeroCinco(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl << endl;
						}
						
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						bnumerocinco = true;
						break;
						
					case '6': //El Seis.
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Seis!!" << endl << endl ;
						
						Reglas_J1.setNumeroSeis(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bnumeroseis = true;
						break;
						
					case 'f': case 'F': //Full
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Full!!" << endl << endl ;
						
						Reglas_J1.setFull(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bfull = true;
						break;
						
					case 'e': case 'E': //Escalera
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado la Escalera!!" << endl << endl ;
						
						Reglas_J1.setEscalera(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bescalera = true;
						break;
						
					case 'p': case 'P': //Poker
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado el Poker!!" << endl << endl ;
						
						Reglas_J1.setPoker(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						
						bpoker = true;
						break;
						
					case 'g': case 'G': //Generala
						system ("CLS");
						cout << endl;
						cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
						cout << "   ¡¡Has jugado la Generala!!" << endl << endl ;
						
						Reglas_J1.setGenerala(Dados_J1);
						
						PuntosJugador += Reglas_J1.getpuntos();
						
						if(PuntosJugador>1){
							cout << "   ¡¡¡Has ganado " << Reglas_J1.getpuntos() <<" puntos!!!" << endl;
							cout << "   ¡¡¡¡¡¡¡¡¡Felicitaciones!!!!!!!!!!           " << endl << endl;
						}
						else{
							cout << endl;
							cout << "   ¡Espera! ¡No has cumplido con los requerimientos de éste juego!" << endl;
							cout << "   ¡No ganas puntos! " << endl;
						}
						bgenerala = true;
						break;
						
					}
					
					system("pause");
					Reglas_J1.setpuntos(); //Dejo los puntos recien ganados 0, así no los acarreo en la próxima ronda.
					mano++; // Cuenta cada mano que se realiza. Cuando éste llega a 9, se termina la mano del jugador.
					cout << endl;
					cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
					cout << "                          Fin de la ronda número "<< mano << endl;
					cout << "                    ¡Tus puntos totales hasta ahora son: " << PuntosJugador << "!" << endl << endl;
					
					system("pause");	
					system ("CLS");
				}
				
				//En caso de que arranque otro jugador o se quiera iniciar otra partida, inicializo todos los valores así se pueden usar de nuevo.
				mano = 0;
				bnumerouno = false;
				bnumerodos = false; 
				bnumerotres = false; 
				bnumerocuatro = false;
				bnumerocinco = false;
				bnumeroseis = false; 
				bfull = false; 
				bescalera = false; 
				bpoker = false; 
				bgenerala = false;
				
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                       ¡¡¡¡Se ha terminado el juego!!!!                         " << endl;
				cout << "                   ¡" << Jugador_J1.getNombreJugador() <<", tu puntaje final es : " << PuntosJugador <<" puntos!" << endl;
				cout << "                               ¡¡Muy Bien!!                                      " << endl;
				cout << "                       ¿Te ha resultado divertido?                              " << endl;
				cout << "               ¡Puedes volver a jugar cuantas veces quieras!                    " << endl;
				cout << "               ¿Que tal si la próxima invitas a unos amigos? ;)                  " << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                        Volvamos al menú principal...                           " << endl << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				system("pause");
				
				PuntosJugador = 0; //Se terminó el juego. Por lo tanto, dejo los puntos totales en 0, por si se desea seguir jugando.
				break;	
				
				
				
			case 'b': case 'B': //Reglas del juego.
				system ("CLS");
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                                  Reglas                                        " << endl << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << " ¡Muchas gracias por jugar a la Generala Virtual!                               " << endl;
				cout << " Primero, deberá ingresar cuántas personas van a jugar. Luego, escriba el nombre" << endl;
				cout << " del jugador. (El límite en esta version de -1- jugador)            " << endl;
				cout << " La Generala se juega con 5 dados. Cada jugador puede lanzarlos hasta 3 veces   " << endl; 
				cout << " por mano, pudiendo guardar o dejar los dados que se deseen.                    " << endl;	
				cout << " El juego dura 9 rondas en total por jugador.                                   " << endl;
				cout << " En el transcurso, se deben formar los siguientes juegos:                       " << endl;
				cout << " --> Número 1: se suman todos dados con 1. El puntaje es la sumatoria.          " << endl;
				cout << " --> Número 2, 3, 4, 5, 6: Idem al juego 1.                                     " << endl;
				cout << " --> Full: 3 Dados iguales y 2 dados iguales.                                   " << endl;
				cout << " --> Escalera: 1, 2, 3, 4, 5 o bien 2, 3, 4, 5, 6.                              " << endl;			
				cout << " --> Poker: 4 Dados iguales.                                                    " << endl;
				cout << " --> Generala: Todos los dados iguales:                                         " << endl;
				cout << " A medida que se van realizando los juegos, éstos no se pueden repetir.         " << endl;
				cout << " Si no se cumple con ningún juego, se debe elegir un juego cualquiera,  y en ese" << endl;
				cout << " se le asignan cero puntos.                                                     " << endl;
				cout << " El ganador será aquel que poseea la mayor cantidad de puntos, en caso de ser   " << endl;
				cout << " más de un jugador.                                                             " << endl;
				cout << "              ¡¡Anímese a jugar!! ¡¡Es más fácil de lo que parece!!             " << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                        Volvamos al menú principal...                           " << endl << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				system ("pause");
				system ("CLS");
				break;
				
				
			case 'c': case 'C': //Créditos
				system ("CLS");
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                                 Créditos                                       " << endl << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "--> Alumna: Micaela B. Alfieri                                                  " << endl;
				cout << "--> Carrera: TEC en Diseño y Programación de Videojuegos.                       " << endl;
				cout << "--> Materia: Introducción a la Programación.                                    " << endl;
				cout << "--> Institución: Universidad Nacional del Litoral.                              " << endl;
				cout << "--> Año: 2019                                                                   " << endl;
				cout << "--> Agradecimientos especiales: a la rata Marta, que se encuentra en el cielo <3" << endl;
				cout << "    QEPD, Martita <3                                                            " << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                        Volvamos al menú principal...                           " << endl << endl; 
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				system ("pause");
				system ("CLS");
				break;	
				
				
			case 'd': case 'D':
				system ("CLS");
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				cout << "                                 ¿Quieres salir?                                " << endl;
				cout << "          ¡¡¡Muchas gracias por haber jugado a la Generala Virtual 2.0!!!        " << endl;
				cout << "                            ¡¡¡Nos vemos la próxima!!!                          " << endl;
				cout << "                                    (^_°)/                                      " << endl << endl;
				cout << "*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl;
				return 0;	
			}
		}
	}
	return 0;
}
