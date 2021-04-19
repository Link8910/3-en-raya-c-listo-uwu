#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
//**************************************************************************************************************************************************************************************************************************************************************************************************
//**************************************************************************************************************************************************************************************************************************************************************************************************
// 									Nombre y apellido.- Justo Alfredo Perez Choque
//**************************************************************************************************************************************************************************************************************************************************************************************************
// 								Nota.- Ya aprendi a usar las matrices asi que mejore mis codigos anteriores, aun asi me complique en algunas partes(creo yo)
// 										todo funciona 100% le hize varias pruebas, aunque no me gusta en el aspecto estetico :,v en fin.
////**************************************************************************************************************************************************************************************************************************************************************************************************




using namespace std;

//**************************************************************************************************************************************************************************************************************************************************************************************************

char escoger() 																// Funcion para escoger el jugador(X ó O)							
{
  char opcion;																//Este lo hizo usted en su clase :) solo hice ctrl c + ctrl v y le modifique los returns jsjs
  
  while(true) {																	
    cout<<"Escoja ser X u O: ";
    cin>>opcion;
    if( opcion != 'X' && opcion != 'O' && opcion != 'x' && opcion != 'o' )	 
      cout << "\nDebe escoger X u O: " <<endl;
    else{																
      cout << "\nUsted ha elejido ser: " << opcion << "\n";
      if( opcion == 'X' || opcion=='x' )								
        return 'X';																
      else
        return 'O';
    }
  }
  
  return -1;
}




char iniciar(char matriz[3][3])												// Funcion que inicia la matriz 3x3
{
	int filas = 3;															//Simplemente unicia una matriz llenandola de espacios
	int columnas  = 3;	
	int o = 1;										
	
	
	for (int i = 0; i < filas; i ++)			
	{	
		for (int j = 0; j < columnas; j++)
		{
			matriz[i][j] = ' ';
			o ++;
			
		}
		
	}
	return matriz[3][3];	
}





void imprimir(char matriz[3][3])											// Funcion que imprime la matriz  3x3 
{
	int filas = 3;															// Imprime la matriz siguiendo la interfaz del tren es raya
	int columnas  = 3;	
	int o = 1; 	
	
	for (int i = 0; i < filas; i ++)					
	{	
		for (int j = 0; j < columnas; j++)			
		{	
			if (matriz[i][j]== ' ')
			{
				if (j == 2)							
				{
					cout<<matriz[i][j]<<o<<"     ";
				}
				else									
				{
					cout<<matriz[i][j]<<o<<"  | ";	
				}
				o++;
			}
			
			else if (matriz[i][j] != ' ')
			{
				if (j == 2)							
				{
					cout<<" "<<matriz[i][j]<<"     ";
				} 
				else									
				{
					cout<<" "<<matriz[i][j]<<"  | ";	
				}
				o++;
			}

		}
		if (i != 2)									
		{	
			cout <<endl;
			for (int i = 0 ;i < columnas; i ++)		
			{
				
				cout <<"-----";
				
			}
			
		}
		cout <<endl;
	}
	
	
	
	
	
}





char colocar(char matriz[3][3], int posicion, char jugador)					//	Funcion que coloca la posicion los parametros son: (tablero, la posicion, la maquina o el jugador)
{
	int filas = 3;															//  Coloca la posicion del jugador(o la maquina) en el tablero
	int columnas  = 3;	
	int o = 1;										
	
	
	for (int i = 0; i < filas; i ++)					
	{	
		for (int j = 0; j < columnas; j++)
		{
		 	if (o == posicion )//&& matriz[i][j] == ' ')
			 {
		 		matriz[i][j] = jugador;
			 }
			 o++;
		}
		
		
	
	}

	
	return matriz[3][3];	
}



int escogerposicion(char opcion, char matriz[3][3])							// Funcion que hace que el jugador elija la posicion			
{
	int filas = 3;																					// Esta funcion hace que el jugador elija una posicion correcta 
	int columnas  = 3;	
	int o =1;	
	int posicion;
	
																
	cout<<"\nColoque la posicion(del 0 al 9) de la "<< opcion <<": ";cin >> posicion;
										
	
	
	for (int i = 0; i < filas; i ++)	//Este for es por si elije una posicion que ya esa en uso		
	{	
		for (int j = 0; j < columnas; j++)
		{
		 
			if (o == posicion && matriz[i][j] != ' ')
			{
				while (posicion == o)
				{
					cout<<"\nLa posicion que ingresaste ya esta en uso, ingrese otra posicion para "<< opcion <<": ";cin >> posicion;
				}
			}
		 	o++;	
		}
	}
	

	while (posicion < 1 or posicion > 9)
	{
		cout<<"\n---------------------------->Elija un valor desde (1 a 9) para "<< opcion <<": ";cin >> posicion;
	}
	return posicion;
	
	
	
	
}




bool verificaro(char matriz[3][3])											// Funcion que verifica si la O hizo 3 en raya
{
																		//unos if con todos los casos donde gane la O
	bool ygana = false;									
	
	if ( matriz[0][0] == 'O' and matriz[1][1] == 'O' and matriz[2][2]== 'O')
	{
		ygana = true;
	}
	else if ( matriz[1][0] == 'O' and matriz[1][1] == 'O' and matriz[1][2]== 'O')
	{
		ygana = true;
	}
	else if ( matriz[2][0] == 'O' and matriz[2][1] == 'O' and matriz[2][2]== 'O')
	{
		ygana = true;
	}
	
	else if ( matriz[0][0] == 'O' and matriz[1][0] == 'O' and matriz[2][0]== 'O')
	{
		ygana = true;
	}

	else if ( matriz[0][2] == 'O' and matriz[1][2] == 'O' and matriz[2][2]== 'O')
	{
		ygana = true;
	} 
	else if ( matriz[0][0] == 'O' and matriz[0][1] == 'O' and matriz[0][2]== 'O')
	{
		ygana = true;
	}	
	
	else if ( matriz[0][2] == 'O' and matriz[1][1] == 'O' and matriz[2][0]== 'O')
	{
		ygana = true;
	}
	else if ( matriz[0][1] == 'O' and matriz[1][1] == 'O' and matriz[2][1]== 'O')
	{
		ygana = true;
	}
	return ygana;
}
	



bool verificarx(char matriz[3][3])											// Funcion que verifica si la X hizo 3 en raya
{
																//unos if con todos los casos donde gane las X
	bool xgana = false;
		
	if ( matriz[0][0] == 'X' and matriz[1][1] == 'X' and matriz[2][2]== 'X')
	{
		xgana = true;
	}
	else if ( matriz[1][0] == 'X' and matriz[1][1] == 'X' and matriz[1][2]== 'X')
	{
		xgana = true;
	}
	else if ( matriz[2][0] == 'X' and matriz[2][1] == 'X' and matriz[2][2]== 'X')
	{
		xgana = true;
	}
	
	else if ( matriz[0][0] == 'X' and matriz[1][0] == 'X' and matriz[2][0]== 'X')
	{
		xgana = true;
	}
	else if ( matriz[0][0] == 'X' and matriz[0][1] == 'X' and matriz[0][2]== 'X')
	{
		xgana = true;
	}
	else if ( matriz[0][2] == 'X' and matriz[1][2] == 'X' and matriz[2][2]== 'X')
	{
		xgana = true;
	}
		
	else if ( matriz[0][1] == 'X' and matriz[1][1] == 'X' and matriz[2][1]== 'X')
	{
		xgana = true;
	}
	else if ( matriz[0][2] == 'X' and matriz[1][1] == 'X' and matriz[2][0]== 'X')
	{
		xgana = true;
	}
	
	
	
	
	
	
	
	
	return xgana;
}





char personajemaquina(char opcion)											// Funcion que elije el personaje de la maquina (X ó O)
{
	char persomaquina;				// lo unico que hace es elejir lo contrario al jugador para la maquina jsjs
																		
	
	if (opcion == 'X')
	{
		
		persomaquina = 'O';
		
	}
	else
	{
		persomaquina = 'X';
	}
	return persomaquina;
}	
	





int posmaquina(char matriz[3][3])											// Funcion que elije una posicion para la maquina (la que mas me dolio)
{

	bool a  = true;					//Fua aqui me demore, bueno simplemente elije una posicion cualquiera para la maquina, pero el problema es que a veces elijia posiciones ya usadas, lo arregle 				
	bool b = false;					// con 2 booleanos y un if en la linea 343
	int posicion;
	srand(time(NULL));

	int o = 1 ;
	
	
	while (a == true)
	{	
		posicion = 1 + rand()%9;
		o = 1 ;
		b = false;
		for (int i = 0; i < 3; i ++)					
		{	
			for (int j = 0; j < 3; j++)
			{
		 		if (posicion == o && (matriz[i][j] != ' '))//simplemente  si la posicion de el  numero aleatorio ya tiene un valor, elije otro, y asi un bule infinito hasta que no pase
					{
						b = true;
					}
				
				o++;	
			}
		 		
		}
		if (b == false)
		{
			a = false;
		}
	}	
	
	return posicion;
}	
		
	
	
	
	
void final(char jugador,bool ogana,bool xgana,char matriz[3][3])			//Funcion que se muestra al final mostrando los resultados
{
	if (xgana == true and jugador == 'X')						//muestra los resultados
	{
		cout<< "\nX gano la partida, Ganaste :)";
	}
	else if (xgana == true and jugador != 'X')	
	{
		cout<< "\nX gano la partida, Perdiste :(";
	}
	else if (ogana == true and jugador == 'O')	
	{
		cout<< "\nO gano la partida, Ganaste :)";
	}
	else if (ogana == true and jugador != 'O')	
	{
		cout<< "\nO gano la partida, Perdiste :(";
	}
	else
	{
		cout<<"EL tablero se lleno :v";
	}
}	
	




int main()



{			
									//		Primera parte : variables que se necesitaran
	char tablero[3][3];					//El tablero
	
	char jugador;						//El jugador (X ó O)
	int posicionjugador;				//Posicion del jugador				
	char jugadormaquina;				//EL jugador de la maquina(X ó O)
	int posicionmaquina;				//Posicion de la maquina
	bool xgana;							//Bool que indica si gana X
	bool ogana;							//Bool que indica si gana O
//**************************************************************************************************************************************************************************************************************************************************************************************************

													// Segunda Parte: Eleccion del jugador y de la maquina
	jugador = escoger();							// El jugador escoge su personaje
	jugadormaquina = personajemaquina(jugador);		// EL personaje de la maquina respecto al del jugador
	cout<<"\n";

	iniciar(tablero);								// Inicia el tablero

	
//**************************************************************************************************************************************************************************************************************************************************************************************************
													//Tercera Parte : La partida
	int i = 0 ;	
	while ( (i < 5))                                // un while que hara que se repitan los turnos
	{
		cout<<"\n";
		
		
		imprimir(tablero);										// Imprime el tablero
		posicionjugador = escogerposicion(jugador,tablero);		// Le pide una posicion al jugador
		colocar(tablero,posicionjugador, jugador);				// La coloca
		
		xgana = verificarx(tablero);							// Comprueba si x hizo 3 en raya
		ogana = verificaro(tablero);							// Comprueba si O hizo 3 en raya
		
		
		if (i == 4 or xgana == true or ogana == true)			// este if es por si alguien gana, salga del while y muestre los resultados
		{
			break;
		}
		
		
		
		posicionmaquina = posmaquina(tablero);					// Genera una posicion para la maquina
		colocar(tablero,posicionmaquina,jugadormaquina);		// La coloca
		
		xgana = verificarx(tablero);							//Compeuba si gano la X
		ogana = verificaro(tablero);							//Comprueba si gano la O
			
		
		if ( xgana == true or ogana == true)					// este if es por si alguien gana, salga del while y muestre los resultados
		{
			break;
		}
		
		
		system("cls");											//Limpia la pantalla
		i++;
	}
	
	cout<<"\n";
	system("cls");
	
	imprimir(tablero);											//Imprime el tablero
	final(jugador,ogana,xgana,tablero);							//Presenta los resultados
		
	
//*************************************************************************************************************************************************
	
	
	
}
