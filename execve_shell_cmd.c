#include "main.h"

int main(void)
{
	const char cmd_path[] = "C:/Program Files/Git/usr/bin/ls";
	const char *args_array[] = {"ls", "-l", NULL};
	const char *env_vars[] = {NULL};

	if (execve(cmd_path, args_array, env_vars) == -1);
		printf("Execution failed");
	return (0);
}
