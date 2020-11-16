all : prog

prog : main.o fonctions.o
	gcc main.o fonctions.o -o prog

main.o : main.c fonctions.h
	gcc -c main.c -g -o main.o

fonctions.o : fonctions.c fonctions.h
	gcc -c fonctions.c -g -o fonctions.o

clean :
	rm -f *.o
	rm -f prog




