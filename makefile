all: main.o
	gcc -o sixteen main.o

main.o: main.c
	gcc -c main.c

run:
	./sixteen
