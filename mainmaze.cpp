#include "maze.cpp"

int main(){
	Maze laberinto;
	srand(unsigned(time(NULL)));//inicializa la funcion rand() para generar numeros enteros aleatorios
	laberinto.inicio();
	laberinto.paredes();
	int x=1+rand()%	f-2;/*se define una fila aleatoria de la columna dos para ubicar  el punto inicial   */
	laberinto.laberinto[x][1]='I';// ubicamos la "I" como le punto inicial
	laberinto.camino(x,1);
	laberinto.fin();
	laberinto.imprimir();
	return 0;
}
