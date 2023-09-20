#include "main.h"

/**
 * command_exec - executes a command
 * @args: command and it's arguments
 * @prg_name: program name
 * Return: nothing
*/
void command_exec(char **args, char *prg_name, int cmd_count)
{
	/*char *envp[] = {NULL};*/
	pid_t child_pid;
	int status;

	if (access(args[0], X_OK) == 0)
	{
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
	
}