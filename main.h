#ifndef MAIN_H
#define MAIN_H

#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

struct arguments
{
	char *command_line;
	struct arguments *next;
} args;

#endif
