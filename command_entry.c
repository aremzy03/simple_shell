#include "main.h"

/**
 * prompt - displays the shell
 * and allows the user to enter the command
 * Return: a pointer to the command string
*/
char *prompt(void)
{
	char *command = NULL;
	size_t size = 0;
	ssize_t size2;

	printf("($) ");
	size2 = getline(&command, &size, stdin);
	command[size2 - 1] = '\0';
	if (feof(stdin) != 0)
	{
		free(command);
		exit(0);
	}
	return (command);
}

/**
 * split_command - splits the command parts and stores them
 * in an array of strings
 * @command: command to be treated
 * Return: a pointer to the array of strings
*/
char **split_command(char *command)
{
	char *token = NULL, **array = NULL;
	int i = 0;

	command = command;
	token = strtok(command, " ");
	while (token != NULL)
	{
		array = realloc(array, sizeof(char *) * (i + 1));
		array[i] = strdup(token);
		token = strtok(NULL, " ");
		i++;
	}
	array = realloc(array, sizeof(char *) * (i + 1));
	array[i] = NULL;

return (array);
}
/**
 *shell_exit - exit the program with a specified status
 *@argv: the status
 */
void shell_exit(char **argv)
{
	int status = 0;

	if (argv[1] != NULL)
	{
		if (is_num(argv[1]) == 0)
		{
			status = atoi(argv[1]);
			string_array_free(argv);
			exit(status);
		}
		else
			printf("Error: ");
	}
	else
	{
		exit(status);
	}
}
/**
 *ptrenv - prints the current working environment
 */
void ptrenv(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}
