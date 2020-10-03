#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main(int argc, char *arg[])
{
	FILE *fPtr;
	char passwd[MAX_BUF] = {0};

	if ((fPtr = fopen("file_passwd.txt", "r")) == NULL)
	{
		return ERROR_OPENING_FILE;
	}

	printf("%s", "Inserisci la password da cercare: ");
	fflush(stdout);
	scanf("%256s", passwd);
	fflush(stdin);

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("%s\n", "Error init mutex");
		fflush(stdout);
		fclose(fPtr);
		
		return ERROR_INIT_MUTEX;
	}

	pthread_mutex_destroy(&lock);
	fclose(fPtr);
	return 0;
}