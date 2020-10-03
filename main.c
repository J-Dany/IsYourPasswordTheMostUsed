#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main(int argc, char *arg[])
{
	FILE *fPtr;
	char passwd[MAX_BUF] = {0};
	char buff[MAX_BUF] = {0};

	if ((fPtr = fopen("file_passwd.txt", "r")) == NULL)
	{
		return EOF;
	}

	while (!feof(fPtr))
	{
		fscanf(fPtr, "%s", buff);
		fflush(fPtr);

		if (strcmp(buff, passwd) == 0)
		{
			printf("%s\n", "Password trovata!");
			fflush(stdout);
			break;
		}
	}

	fclose(fPtr);
	return 0;
}