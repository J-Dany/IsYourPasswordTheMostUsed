main: main.o insert_node.o get_passwd_at.o delete_list.o list_size.o print_list.o search.o
	gcc main.o insert_node.o get_passwd_at.o delete_list.o list_size.o print_list.o search.o -g -o main

search.o: search.c
	gcc -c search.c

print_list.o: print_list.c
	gcc -c print_list.c

list_size.o: list_size.c
	gcc -c list_size.c

insert_node.o: insert_node.c
	gcc -c insert_node.c

get_passwd_at.o: get_passwd_at.c
	gcc -c get_passwd_at.c

delete_list.o: delete_list.c
	gcc -c delete_list.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o main