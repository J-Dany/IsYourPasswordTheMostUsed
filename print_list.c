#include "utilities.h"

int print_list(ListNodePtr __head)
{
    ListNodePtr curr = __head;

    printf("%s -> ", "Head");

    while (curr != NULL)
    {
        printf("%s -> ", curr->passwd);
        curr = curr->next;
    }

    printf("%s\n", "NULL");
    return 0;
}