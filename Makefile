main: main.o
	gcc main.o -g -o main

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o main