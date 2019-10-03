all: main.o BST.o
	g++ main.o BST.o -o main; ./main
main.o: main.cpp
	g++ -c main.cpp
linkedList.o: BST.cpp
	g++ -c BST.cpp