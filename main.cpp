#include <iostream>
#include <ctime>
#include "GreatGraph.h"

using namespace std;

/**Màxim nombre d'arestes que pot tenir un Graph aleatori.*/
#define MAXNV 10
/**Màxim nombre d'arestes que pot tenir un Graph aleatori.*/
#define MINNV 1

/**
 * Retorna un valor aleatori entre minNV i maxNV.
 * @return  Valor aleatori entre minNV i maxNV.
 */
int randomNV(int minNV, int maxNV) {
	



    srand(time(0));
    int randnum = rand();

    	//cout << "En funcion randomNV del main:" << endl;
    	//cout << maxNV << ' ' << minNV << ' ' << maxNV - minNV + 1 << endl;
    	//cout << "VALOR DE RETORNO:" << minNV + (randnum % (maxNV - minNV + 1)) << endl;
    	//cout << "VALOR DE FUNC RAN(): " << randnum << endl;



    return minNV + (randnum % (maxNV - minNV + 1));
}



/**
 * Retorna un Graph Erdős-Rényi aleatori.
 * @return Graph Erdős-Rényi aleatori.
 */




int main(){
	GreatGraph GG;
	GG.Test();
}