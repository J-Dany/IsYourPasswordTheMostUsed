#include <string.h>
#include "utilities.h"

int search(ListNodePtr *__head, FILE **__f, const char *__passwd)
{
	if (feof(*__f))
	{
		printf("%s\n", "Password non trovata.");
		return -1;
	}

	char buff[MAX_BUF] = {0};

	size_t i = 0;
	while(!feof(*__f) && i < 64)
	{
		fscanf(*__f, "%s", buff);
		fflush(stdin);
		
		if (buff[0] != '\n')
		{
			insert_node(__head, buff);
		}
		++i;
	}

	for (size_t i = 1; i <= list_size(NULL); ++i)
	{
		const char *passwd_at = get_passwd_at(__head, i);
		
		if (passwd_at && strcmp(passwd_at, __passwd) == 0)
		{
			printf("%s\n", "Password trovata!");
			return 0;
		}
	}

	delete_list(__head);
	return search(__head, __f, __passwd);
}