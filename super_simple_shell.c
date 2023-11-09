#include "main.h"

int main()
{
	char *base;
	env_array = {NULL}
	char **args_array;
	char *buffer;
	size_t buffsize = 1024;
	size_t gen_check;
	size_t child_pid;

	args_array = malloc(10 * 8);
	buffer = malloc(buffsize);
	while (true)
	{
		write(1, "$ ", 2);
		gen_check = getline(buffer, buffsize, stdin);
		if (getline >= 0)
		{
			child_pid = fork();
			if (child_pid == 0)
			{
				base = strrchr(buffer, '/');
				if (base != NULL)
				{
					*args_array = malloc(sizeof(*base));
					*args_array++;
					*args_array = NULL;
					execve(buffer, args_array, env_array);
				}
				write(1, "Something went wrong", 20);
			}
			else
				wait();
		}
	}
}
