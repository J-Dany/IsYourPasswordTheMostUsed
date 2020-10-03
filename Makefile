main: main.o search.o
	gcc main.o search.o -g -o main

search.o: search.c
	gcc -c search.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o main