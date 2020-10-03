#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

void search(FILE **__f, const char *__passwd)
{
    pthread_mutex_lock(&lock);

    char buff[MAX_BUF] = {0};

    while (!feof(*__f))
	{
		fscanf(*__f, "%s", buff);
		fflush(*__f);

		if (strcmp(buff, __passwd) == 0)
		{
			printf("%s\n", "Password trovata!");
			fflush(stdout);

            pthread_mutex_unlock(&lock);
			return;
		}
	}

    pthread_mutex_unlock(&lock);
}