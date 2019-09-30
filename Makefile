main.x: main.o  Graph.o Find.o Union.o probConnex.o GreatGraph.o
	g++ -o main.x *.o 

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Graph.o: Graph.h Graph.cpp
	g++ -c Graph.cpp -std=c++11


Find.o: Find.h Find.cpp
	g++ -c Find.cpp -std=c++11


Union.o: Union.h Union.cpp
	g++ -c Union.cpp -std=c++11

GreatGraph.o: GreatGraph.h GreatGraph.cpp
	g++ -c GreatGraph.cpp -std=c++11

probConnex.o: probConnex.h probConnex.cpp
	g++ -c probConnex.cpp -std=c++11

clean:
	rm *.o *.x