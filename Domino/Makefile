all: main.o game.o
	g++ main.o game.o -o main; ./main
main.o: main.cpp
	g++ -c main.cpp
game.o: game.cpp
	g++ -c game.cpp