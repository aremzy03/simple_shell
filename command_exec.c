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
void change_dir(char **args)
{
	char *pwd, *home, *buff = NULL;

	home = getenv("HOME");
	if (args[1] == NULL)
		chdir(home);
	else
		chdir(args[1]);
	pwd = getcwd(buff, 0);
	setenv("PWD", pwd, 1);
	free(buff);
	free(pwd);
	free(home);
}
/**
 * command_exec - executes a command
 * @args: command and it's arguments
 * @prg_name: program name
 * @cmd_count: number of the command
 * @path_array: array of path variable directories
 * Return: nothing
 */
void command_exec(char **args, char *prg_name,
				  int cmd_count, char **path_array)
{
	char *full_path;
	pid_t child_pid;
	int status;

	if (strncmp(args[0], "cd", 2) == 0)
	{
		change_dir(args);
		return;
	}
	full_path = search_command(args[0], path_array);
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
}
/**
 * ptr_env - prints the current working environment
 * @env: thwe environment variable
 */
void ptr_env(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
