CC = clang++
SANITIZER = -fsanitize=address -fsanitize=undefined

FLAGS = -std=c++17 -c $(SANITIZER) -g

# -fsanitize=address -fsanitize=undefined

all: compile

compile: FILEReader.o FILEWriter.o FILEReaderWriter.o StringReader.o StringWriter.o StringReaderWriter.o BufferedFILEReaderWriter.o BufferedStringReaderWriter.o tests.o main.o
	$(CC) $(SANITIZER) -o main *.o

FILEReader.o: FILEReader.cpp
	$(CC) $(FLAGS) FILEReader.cpp

FILEWriter.o: FILEWriter.cpp
	$(CC) $(FLAGS) FILEWriter.cpp

StringReader.o: StringReader.cpp
	$(CC) $(FLAGS) StringReader.cpp

StringWriter.o: StringWriter.cpp
	$(CC) $(FLAGS) StringWriter.cpp

FILEReaderWriter.o: FILEReaderWriter.cpp
	$(CC) $(FLAGS) FILEReaderWriter.cpp

StringReaderWriter.o: StringReaderWriter.cpp
	$(CC) $(FLAGS) StringReaderWriter.cpp

BufferedFILEReaderWriter.o: BufferedFILEReaderWriter.cpp
	$(CC) $(FLAGS) BufferedFILEReaderWriter.cpp

BufferedStringReaderWriter.o: BufferedStringReaderWriter.cpp
	$(CC) $(FLAGS) BufferedStringReaderWriter.cpp

tests.o: tests.cpp
	$(CC) $(FLAGS) tests.cpp

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

clean: 
	rm -f *.o main
