#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int trovata = 0;

void *search(void *__args)
{
    struct args arguments = *(struct args *)__args;
    pthread_mutex_lock(&lock);

    char buff[MAX_BUF] = {0};

    while (!feof(*arguments.file_passwd))
	{
        if (trovata)
        {
            break;
        }
		fscanf(*arguments.file_passwd, "%s", buff);
		fflush(*arguments.file_passwd);

		if (strcmp(buff, arguments.passwd) == 0)
		{
            trovata = 1;
			printf("%s\n", "Password trovata!");
			fflush(stdout);

            break;
		}
	}
    
    pthread_mutex_unlock(&lock);
    return NULL;
}