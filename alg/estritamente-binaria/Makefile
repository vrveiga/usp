all: item.o ab.o main.o
	gcc main.o ab.o item.o -o main -std=c99 -Wall

item.o:
	gcc -c item.c;

ab.o:
	gcc -c ab.c;

main.o:
	gcc -c main.c;

run:
	./main

clean:
	rm *.o main