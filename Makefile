OUT = A-Proyecto
OBJECTS = main.o Graph.o Find.o Union.o probConnex.o GreatGraph.o

$(OUT): $(OBJECTS)
	g++ -o $(OUT) -std=c++11 $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(OUT)

run: $(OUT)
	./$(OUT)