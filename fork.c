#include "main.h"

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
		printf("May I please have a piece of bread sir?");
	else if (pid > 0)
	{
		printf("Begone vagabond!");
		wait(NULL);
	}
	else
	{
		printf("fork failed");
		return -1;
	}
	return 0;
}
