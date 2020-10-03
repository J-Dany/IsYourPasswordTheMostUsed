#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"

int main(int argc, char *arg[])
{
	int exit_error = 0;
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

	struct args arguments = 
	{
		.file_passwd = &fPtr,
		.passwd = passwd
	};

	if (pthread_mutex_init(&lock, NULL) != 0)
	{
		printf("%s\n", "Error init mutex");
		fflush(stdout);

		exit_error = ERROR_INIT_MUTEX;
		goto fine;
	}

	for(char i = 0; i < 2; ++i)
	{
		if (pthread_create(&(threads[i]), NULL, &search, (void *)&arguments) != 0)
		{
			printf("%s\n", "Error creating thread");
			fflush(stdout);

			exit_error = ERROR_CREATING_THREAD;
			goto fine;
		}
	}

	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);

fine:
	pthread_mutex_destroy(&lock);
	fclose(fPtr);
	return exit_error;
}