all: main.o cache.o
	g++ main.o cache.o -o main; ./main
main.o: main.cpp
	g++ -c main.cpp
linkedList.o: queue.cpp
	g++ -c queue.cpp