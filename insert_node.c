#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <string.h>
#include "utilities.h"

int insert_node(ListNodePtr *__head, const char *__passwd)
{
    ListNodePtr new_node = malloc(sizeof(ListNode));

    if (new_node != NULL)
    {
        new_node->passwd = calloc(strlen(__passwd) + 1, sizeof(char));
        strcpy(new_node->passwd, __passwd);
        new_node->next = NULL;

        ListNodePtr curr = *__head;
        ListNodePtr prev = NULL;

        while (curr != NULL)
        {
            prev = curr;
            curr = curr->next;
        }

        if (prev == NULL)
        {
            *__head = new_node;
            new_node = *__head;
        }
        else
        {
            prev->next = new_node;
            new_node->next = curr;
        }
        
        list_size("inc");
        return 0;
    }

    return -1;
}