#include "main.h"

/**
 * prompt - displays the prompt if interractive and reads the command
 * Return: the command if correct, null if nothing typed
*/
char *prompt(void)
{
	char *command = NULL;
	size_t n = 0;
	ssize_t size;

	if (isatty(STDIN_FILENO) == 1)
		printf("($) ");

	size = getline(&command, &n, stdin);
	if (feof(stdin) != 0)
	{
		free(command);
		return (NULL);
	}

	command[size - 1] = '\0';
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
 * free_array - frees an array of strings
 * @array: array to  be treated
*/
void free_array(char **array)
{
	int i = 0;

	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
