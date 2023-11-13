#include "main.h"

int main()
{
	char **args_array;
	char *buffer;
	char *token;
	size_t buffsize = 1024;
	size_t len_check;
	int i;
	int len;

	len = 0;
	buffer = malloc(1024);
	token = malloc(100);
	args_array = malloc(10 * sizeof(char *));
	write(1, "$ ", 2);
	len_check = getline(&buffer, &buffsize, stdin);
	if (len_check > 0)
	{
		printf("after input is taken in\n");
		token = strtok(buffer, " ");
		for (i = 0; token != NULL; i++)
		{
			while (token[len] !=  '\0')
				len++;
			args_array[i] = malloc(len + 1);
			args_array[i] = token;
			token = strtok(NULL, " ");
		}
		args_array[i] = NULL;
		printf("after args_array has been assigned\n");
		for (i = 0; args_array[i] != NULL; i++)
		{
			len = 0;
			while (args_array[i][len] != '\0')
				len++;
			write(1, args_array[i], len + 1);
			if (args_array[i + 1] != NULL)
				write(1, "\n", 1);
		}
		for (i = 0; args_array[i] != NULL; i++)
			free(args_array[i]);
		free(args_array);
		free(token);
		free(buffer);
	}
	return (0);
}
