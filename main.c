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
	int cmd_count = 1;
	char **directories = split_path();
	/*prevent the unused variable error temporarly*/
	ac = ac;
	av = av;
	env = env;

	while (1)
	{
		command = prompt();
		if (command == NULL)
			break;
		if (command[0] != '\0')
		{
			args = split_command(command);
			command_exec(args, av[0], cmd_count, directories);
			free(command);
			cmd_count++;
			free_array(args);
		}
		else
			free(command);
	}
	free(command);
	free_array(directories);
return (0);
}
