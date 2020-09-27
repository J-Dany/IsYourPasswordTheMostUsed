#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utilities.h"

int main(int argc, char *arg[])
{
	FILE *fPtr;
	ListNodePtr lista_password = NULL;
	char passwd_choosen[MAX_BUF] = {0};
	
	printf("%s", "Inserisci la password da cercare: ");
	fflush(stdout);
	scanf("%s", passwd_choosen);
	while(getchar() != 10);

	if ((fPtr = fopen("file_passwd.txt", "r")) == NULL)
	{
		fprintf(stderr, "%s\n", "Error: file non found.");
		return 1;
	}

	printf("%s\n", "Inizio la ricerca...");
	search(&lista_password, &fPtr, passwd_choosen);

	delete_list(&lista_password);
	fclose(fPtr);
	return 0;
}