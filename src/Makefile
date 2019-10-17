<<<<<<< HEAD:src/Makefile
OUT = A-Proyecto
OBJECTS = main.o Graph.o UnionFind.o probConnex.o GreatGraph.o
=======
all: main.x
>>>>>>> development-jordi:Makefile

main.x: main.o  Graph.o  UnionFind.o GreatGraph.o probConnex.o
	g++ -o main.x main.o  Graph.o  UnionFind.o GreatGraph.o probConnex.o

main.o: main.cpp
	g++ -c main.cpp -std=c++11

Graph.o: Graph.h Graph.cpp
	g++ -c Graph.cpp -std=c++11

UnionFind.o: UnionFind.h UnionFind.cpp
	g++ -c UnionFind.cpp -std=c++11

GreatGraph.o: GreatGraph.h GreatGraph.cpp
	g++ -c GreatGraph.cpp -std=c++11

probConnex.o: probConnex.h probConnex.cpp
	g++ -c probConnex.cpp -std=c++11

clean:
	rm -f $(OBJECTS) $(OUT)

run: $(OUT)
	./$(OUT)