#include "main.h"

/**
	* main - int function
	* Description: simple shell
	* Return: int
	*/
int main(void)
{
	char *env_array[] = {NULL};
	char **arg_array;
	char *buffer;
	size_t buffsize = 100;
	size_t pid;
	size_t len_check;
	int i;

	arg_array = malloc(2 * sizeof(char *));
	while (1)
	{
		write(1, "$ ", 2);
		if ((len_check = getline(&buffer, &buffsize, stdin)) == -1)
		{
			printf("Getline failed - bad buffer or input");
			return (-1);
		}
		printf("\nAfter getlined has written the input to buffer\n");
		while (buffer[i] != '0')
			i++;
		arg_array[0] = malloc(i + 1);
		arg_array[0] = buffer;
		arg_array[1] = NULL;
		printf("After arg_array 0 and 1 has been set\n");
		if ((pid = fork()) == 0)
		{
			execve(buffer, arg_array, env_array);
			printf("Execve was unsuccessful");
		}
		else
			wait(NULL);
	}
}
