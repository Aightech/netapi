all: test clean

test: main.o netapi.o
	g++ -o test main.o netapi.o -lpthread

main.o: main.cpp 
	g++ -c main.cpp -std=c++0x -lpthread -o main.o
	
netapi.o: netapi.cpp netapi.hpp
	g++ -c netapi.cpp -std=c++0x -lpthread -o netapi.o

clean:
	rm -f *.o
	

