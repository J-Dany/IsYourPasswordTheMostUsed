#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utilities.h"

#define THREAD

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

	clock_t start = clock();

	#ifdef SEQUENTIAL
		while (!feof(fPtr))
		{
			char buff[MAX_BUF] = {0};
			fscanf(fPtr, "%s", buff);
			fflush(fPtr);

			if (strcmp(buff, passwd) == 0)
			{
				printf("%s\n", "Password trovata!");
				fflush(stdout);

				break;
			}
		}
	#endif
	
	#ifdef THREAD

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
	#endif 

	printf("Execution time: %f\n", (double)(clock() - start) / CLOCKS_PER_SEC);
	fflush(stdout);

	return exit_error;
}