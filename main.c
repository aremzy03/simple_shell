#include "main.h"

/**
 * main - main program where the magic happens
 * Return: 0 on sucess -1 on errors
*/
int main(void)
{
	char *command, **argv = NULL, **path_array;

	path_array = split_path();
	while (1)
	{
		command = prompt();
		argv = split_command(command);
		free(command);
		command_exec(argv, path_array);
		string_array_free(argv);
	}
	string_array_free(path_array);
	free(command);
	return (0);
}
