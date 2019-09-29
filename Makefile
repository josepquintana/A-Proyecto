main: main.cpp Graph.cpp
	g++ -o main main.cpp Graph.cpp -std=c++11

Graph: Graph.cpp
	g++ -o Graph Graph.cpp -std=c++11
