#include <stdlib.h>
#include <malloc.h>
#include "utilities.h"

int delete_list(ListNodePtr *__head)
{
    while (*__head != NULL)
    {
        ListNodePtr curr = *__head;
        *__head = (*__head)->next;

        free(curr->passwd);
        free(curr);
        list_size("dec");
    }

    return 0;
}