#ifndef UTILITIES_H
#define UTILITIES_H
#include <stdio.h>

#define MAX_BUF 256

struct list_node
{
	char *passwd;
	struct list_node *next;
};

typedef struct list_node ListNode;
typedef ListNode *ListNodePtr;

extern int insert_node(ListNodePtr *__head, const char *__passwd);

extern const char *get_passwd_at(ListNodePtr *__head, size_t __index);

extern int delete_list(ListNodePtr *__head);

/**
 * __act can be:
 * - "dec"        -> decrement list size number
 * - "inc"        -> increment list size number
 * - "get" / NULL -> get list's size
 */
extern size_t list_size(const char *__act);

extern int print_list(ListNodePtr __head);

int search(ListNodePtr *__head, FILE **__f, const char *__passwd);

#endif // UTILITIES_H