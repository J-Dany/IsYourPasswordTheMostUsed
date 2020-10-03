#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	return exit_error;
}