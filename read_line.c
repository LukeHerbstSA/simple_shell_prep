#include "main.h"

int main(int ac, char **argv)
{
	char *holder = NULL;
	int buffsize = 1024;
	int chars;

	write(1, "$ ", 2);
	chars = getline(&holder, &buffsize, stdin);
	if (chars != -1)
		write(1, holder, chars);
	return (0);
}
