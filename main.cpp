#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#include "papitolindo.h"
#include "funcione.h"

#define MAX_PAPUCHOS 25

int main(int argc,char **argv){
    struct PapitoLindo papuchos[MAX_PAPUCHOS];

    int cantPapu; 
    double probabilida[MAX_PAPUCHOS];
    
    llenaPapucho(papuchos,cantPapu);
    calculaProbabilidaDeQueterobe(papuchos,cantPapu,probabilida);
    crearReporte(papuchos, cantPapu,probabilida);
}

//Implementation de estructuras
//Extraccion de datos
//Paso por referencia a funciones
//Consejo: const cuando no se altera el struct en una funcion
//Implementacion dinamica: Estructuras en punteros...xD
//Lamamadelamamadelamamadelamadelamadelamadelamadelamadelamadelamadelamamadelamadelamadelamadelamadelamadelamadel
//Arreglos y cadenas de caracteres en estructuras
//Algoritmo de ordenacion de estructuras