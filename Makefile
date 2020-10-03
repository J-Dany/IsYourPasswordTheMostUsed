main: main.o search.o
	gcc main.o search.o -g -o main

main.o: main.c
	gcc -c main.c

search.o: search.c
	gcc -c search.c

clean:
	rm -f *.o main