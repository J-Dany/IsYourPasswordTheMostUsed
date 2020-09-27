#include <string.h>
#include "utilities.h"

size_t list_size(const char *__act)
{
    static int size_of_the_list = 0;

    if (!__act)
    {
        goto ret;
    }

    if (strcmp(__act, "dec") == 0)
    {
        size_of_the_list--;
    }
    else if (strcmp(__act, "inc") == 0)
    {
        size_of_the_list++;
    }
    
ret:
    return size_of_the_list;
}