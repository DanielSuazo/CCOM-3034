all: main.o stack.o
	g++ main.o stack.o -o main; ./main
main.o: main.cpp
	g++ -c main.cpp
linkedList.o: stack.cpp
	g++ -c stack.cpp