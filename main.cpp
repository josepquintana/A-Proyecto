#include <iostream>
#include <ctime>
#include "GreatGraph.h"

using namespace std;

/**Màxim nombre d'arestes que pot tenir un Graph aleatori.*/
#define MAXNV 200
/**Màxim nombre d'arestes que pot tenir un Graph aleatori.*/
#define MINNV 25

/**
 * Retorna un valor aleatori entre minNV i maxNV.
 * @return  Valor aleatori entre minNV i maxNV.
 */
int randomNV(int minNV, int maxNV) {
    //cout << maxNV << ' ' << minNV << ' ' << maxNV - minNV + 1 << endl;
    return minNV + (rand() % (maxNV - minNV + 1));
}



/**
 * Retorna un Graph Erdős-Rényi aleatori.
 * @return Graph Erdős-Rényi aleatori.
 */




int main(){
	GreatGraph GG;
	GG.Test();
}