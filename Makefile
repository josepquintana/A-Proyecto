all: main_gg.x main_pc.x

main_gg.x: main_gg.o  Graph.o Find.o Union.o GreatGraph.o
	g++ -o main_gg.x main_gg.o  Graph.o Find.o Union.o GreatGraph.o

main_pc.x: main_pc.o  Graph.o Find.o Union.o probConnex.o 
	g++ -o main_pc.x main_pc.o  Graph.o Find.o Union.o probConnex.o 

main_gg.o: main_gg.cpp
	g++ -c main_gg.cpp -std=c++11

main_pc.o: main_pc.cpp
	g++ -c main_pc.cpp -std=c++11

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