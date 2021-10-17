#ifndef _MAZE_HPP
#define _MAZE_HPP

#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

const int f=20;
const int c=50;
class Maze{

    public:
    char laberinto[f][c];//matriz que crea el laberinto
    void inicio();//funcion que inicializa el laberinto
    void imprimir();// funcion para ver en pantalla
    void camino(int i, int a);// funcion para que le laberinto tenga salida
    void paredes();//funcion que ubica un caracter que simula una pared en punto aleatorio
    void fin();// funcion que ubica el punto final.
    
};













#endif
