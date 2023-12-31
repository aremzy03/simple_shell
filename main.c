#include "main.h"

/**
 * main - main program
 * @ac: arguments count
 * @av: arguments array
 * @env: environment vaiables array
 * Return: 0 if succes -1 if error
 */
int main(int ac, char **av, char **env)
{
	char *command = NULL, **args;
	int cmd_count = 0, exec_stat = 0;
	char **directories = split_path();
	/*prevent the unused variable error temporarly*/
	ac = ac;

	while (1)
	{
		command = prompt();
		if (command == NULL)
			break;
		if (is_void(command) == 0)
		{
			free(command);
			continue;
		}
		if (strncmp(command, "env", 3) == 0)
		{
			ptr_env(env);
			free(command);
			continue;
		}
		if (command[0] != '\0')
		{
			args = split_command(command);
			exec_stat = command_exec(args, av[0], cmd_count, directories);
			free(command);
			cmd_count++;
			free_array(args);
		}
		else
			free(command);
	}
	free(command);
	free_array(directories);
	if (exec_stat != 0 && isatty(STDIN_FILENO) == 0)
		exit(exec_stat);
	else
		exit(0);
	return (0);
}
