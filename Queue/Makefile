all: main.o queue.o
	g++ main.o queue.o -o main; ./main
main.o: main.cpp
	g++ -c main.cpp
linkedList.o: queue.cpp
	g++ -c queue.cpp