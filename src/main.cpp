#include <iostream>
#include "probConnex.h"  
#include "GreatGraph.h"
using namespace std;

int main()
{
    cout << "Testing connectivity probability..." << endl;
 	probConnex pC;
    pC.Experiment();
    cout << "Testing giant connected components..." << endl;
    GreatGraph GG;
	GG.Test();
}