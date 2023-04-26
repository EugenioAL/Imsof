CC = g++
CFLAGS = -c -W -Wall -ansi -pedantic
 
all: main
 
main: main.o hello.o bye.o
	$(CC) -o main main.o hello.o bye.o

main.o: main.cpp hello.cpp bye.cpp
	$(CC) -o main.o main.cpp $(CFLAGS)

hello.o: hello.cpp c_libs.h
	$(CC) -o hello.o hello.cpp $(CFLAGS)

bye.o: bye.cpp c_libs.h
	$(CC) -o bye.o bye.cpp $(CFLAGS)

run:
	./main

clear:
	rm -rf *.o *~ prog