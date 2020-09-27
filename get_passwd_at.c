#include "utilities.h"

const char *get_passwd_at(ListNodePtr *__head, size_t __index)
{
    size_t i = 1;

    ListNodePtr curr = *__head;

    while (curr != NULL && i < __index)
    {
        curr = curr->next;
        ++i;
    }
    
    if (curr)
    {
        return curr->passwd;
    }

    return NULL;
}