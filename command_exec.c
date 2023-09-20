#include "main.h"
/**
 * replac_arg0 - replaces the first element of the args array
 * with the full command path
 * @args: the array of the command and it's arguments
 * @full_path: string of the full path of the command
 * Return: the arrayw of the command with the full path
*/
char **replac_arg0(char **args, char *full_path)
{
	free(args[0]);
	args[0] = full_path;

	return (args);
}

/**
 * command_exec - executes a command
 * @args: command and it's arguments
 * @prg_name: program name
 * @cmd_count: number of the command
 * Return: nothing
*/
void command_exec(char **args, char *prg_name, int cmd_count)
{
	char *full_path;
	pid_t child_pid;
	int status;

	full_path = search_command(args[0]);
	if (full_path != NULL)
	{
		if (args[0] != full_path)
			replac_arg0(args, full_path);

		child_pid = fork();

		if (child_pid == 0)
		{
			execve(args[0], args, environ);
		}
		else if (child_pid < 0)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	else
		fprintf(stderr, "%s: %d: %s: not found\n", prg_name, cmd_count, args[0]);
	
	free(full_path);
}
