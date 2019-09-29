CC=g++
CFLAGS=-I
main: main.cpp	*.h
	$(CC) -o main main.cpp *.h