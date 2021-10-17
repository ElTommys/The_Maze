#include "maze.hpp"



void Maze::inicio()
{ 
	
	for(int i=0;i<f;i++)
	{ //ciclo para recorrer las filas
		for(int a=0;a<c;a++)
		{ //ciclo para recorrer las columnas
			if(i==0 || a==0 || i==f-1 || a==c-1) laberinto[i][a]='0'; // definimos margenes para "cercar" el laberinto
			else laberinto[i][a] =' '; // tenemos un cuadrado vacio por dentro (aun no esta el laberinto)
		}
	}	
}

void Maze::camino(int i, int a){
	while(a!=c-2){ // mientras que no estemos en el "cercado" de la izquierda del laberinto (dos espacios)
			int o=rand()%3; // definimos un numero aleatorio para entrar a 3 casos, este numero aleatorio, tomaria 0,1 o 2
			switch(o)// condicional switch que permite definir varios casos, tiene un parametro de entrada el cual seria el numero del caso al que entrar�
			{
				case 0:
					if(i+1!=f-1 && laberinto[i+1][a]!='O'){ //si no estamos en la ultima fila
						i++;
						laberinto[i][a]='O';
					}
					break;
				case 1:
					if(i-1!=0 && laberinto[i-1][a]!='O'){ //si no estamos en la primera fila
						i--;
						laberinto[i][a]='O';
					}
					break;
				case 2:
					if(a+1!=c-1 && laberinto[i][a+1]!='O'){//si no estamos en la ultima columna
						a++;
						laberinto[i][a]='O';
						if(a==c-2) laberinto[i][a]='F'; //si estamos en la penultima columna, definimos el final
					}
					break;
			}
		}
		//Todo esto fue para definir un camino que vaya desde inicio hasta el final, es decir, que el laberinto tenga soluci�n
}

void Maze::paredes(){
	int p=0;
	while(p<150){ //pusimos este rango para que rellene mas espacios, si no quedan espacios bastante grandes
			int x=rand()%f;//definimos un numero entero x aleatorio en el intervalo de numero de filas
			int y=rand()%c;//definimos un numero entero x aleatorio en el intervalo de numero de columnas
			if(laberinto[x][y]==' ')//si una posicion es un espacio
			{
				p++;
				int lim=1+rand()%10;//ponemos un limite de 10 para que no se llene el laberinto todo de paredes
				int g =0;//contador para definir cuando se llega al limite
				switch(rand()%4)// switch para 4 casos
				{
					case 0:
						while(laberinto[x][y]==' '){
							if(g==lim) break;
							g++;                       //se mueve hacia arriba
							laberinto[x][y]='0';       //lo iguala a cero (pared)
							x--;
						}
						break;
					case 1:
						while(laberinto[x][y]==' '){
							if(g==lim) break;
							g++;                       //se mueve hacia abajo
							laberinto[x][y]='0';       //lo iguala a cero (pared)
							x++;
						}
						break;
					case 2:
						while(laberinto[x][y]==' '){
							if(g==lim) break;
							g++;                      //se mueve hacia la izquierda
							laberinto[x][y]='0';      //lo iguala a cero (pared)
							y--;
						}
						break;
					case 3:
						while(laberinto[x][y]==' '){
							if(g==lim) break;
							g++;                     //se mueve hacia la derecha
							laberinto[x][y]='0';     //lo iguala a cero (pared)
							y++;
						}
						break;
			}
		}
}
}
void Maze::fin(){
	for(int i=0;i<f;i++){//ciclo para recorrer las filas
		for(int a=0;a<c-1;a++){//ciclo para recorrer las columnas
			if(laberinto[i][a]=='O') laberinto[i][a]=' ';//si la posicion es igual a 'O' (es decir, lo que definimos en camino()), creamos un espacio
			if(a==c-2 && laberinto[i][a]!='F') laberinto[i][a]='0';// si estamos en la penultima columna, (es decir, la colunma final del laberinto)
			if(laberinto[i][a]=='F')//si la posicion es igual a 'F'
			{
				laberinto[i][a+1]='F';
				laberinto[i][a]=' ';
			}
		}
	}
}

void Maze::imprimir() {
	for(int i=0;i<f;i++){ //ciclo para recorrer las filas
		for(int a=0;a<c;a++){//ciclo para recorrer las columnas
			if(laberinto[i][a]=='0') cout<<(char)219;// si una posicion en la matriz tiene un valor de 0, se imprimira el caracter 219 que en ASCII es
			else cout<<laberinto[i][a];//si no, queda vacio
		}
		cout<<endl;
	}
}
