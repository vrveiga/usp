all: ponto.o circulo.o main.o
	gcc main.o circulo.o ponto.o -o main -std=c99 -Wall -lm

ponto.o:
	gcc -c ponto.c

circulo.o:
	gcc -c circulo.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main
