#include "main.h"

int main (void)
{
	char command[] = "/bin/ls";
	char *cmd_args[] = {"ls", "-l", "/tmp", NULL};
	char *env_vars[] = {NULL};
	pid_t pid;
	int i;

	i = 0;
	while (i < 5)
	{
		pid = fork();
		if (pid == 0)
			execve(command, cmd_args, env_vars);
		else
			wait(NULL);
		i++;
	}
	return 0;
}
