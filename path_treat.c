#include "main.h"

/**
 * search_command - searches for a command in the path variable
 * @command: is the command we are looking for
 * @directories: array of path variable directories
 * Return: path to the full command or null if not found
 */
char *search_command(char *command, char **directories)
{
	char *full_path;
	size_t commandsize = strlen(command), arraysize;
	int i = 0;

	if (access(command, X_OK) == 0)
	{
		return (command);
	}

	while (directories[i] != NULL)
	{
		arraysize = strlen(directories[i]);
		full_path = malloc(sizeof(char) * (commandsize + arraysize + 2));
		strcpy(full_path, directories[i]);
		strcat(full_path, "/");
		strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		i++;
	}
	return (NULL);
}

/**
 * split_path - splits the path string into directories
 * Return: an array of directories of the path variable
 */
char **split_path(void)
{
	int count = 1, i = 0;
	char *path, **directories, *token = NULL;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);
	while (path[i] != '\0')
	{
		if (path[i] == ':')
			count++;
		i++;
	}

	directories = malloc(sizeof(char *) * (count + 1));
	i = 0;
	token = strtok(path, ":");
	while (token != NULL)
	{
		directories[i] = strdup(token);
		token = strtok(NULL, ":");
		i++;
	}
	directories[i] = NULL;
	return (directories);
}
