CC = clang++
FLAGS = -std=c++17 -Wall -c


all: FILEReader FILEWriter main
	$(CC) -o main FILEReader.o FILEWriter.o main.o

FILEReader: FILEReader.cpp
	$(CC) $(FLAGS) FILEReader.cpp

FILEWriter: FILEWriter.cpp
	$(CC) $(FLAGS) FILEWriter.cpp

main: main.cpp
	$(CC) $(FLAGS) main.cpp

clean: 
	rm -f *.o main
