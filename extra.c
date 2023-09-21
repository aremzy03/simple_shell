#include "main.h"
/**
 * is_void - checks if the command is empty
 * @command: the command to be treated
 *
 * Return: 0 if void and 1 if not
 */
int is_void(char *command)
{
	int i;

	for (i = 0; command[i] != '\0'; i++)
	{
		if (isalnum(command[i]) != 0)
			return (1);
	}
	return (0);
}
/**
 * wait_pid - returns the exit status
 * @pid: the process id
 * @status: the status of the process
 *
 * Return: returns the exit_status on success
*/
int wait_pid(pid_t pid, int status)
{
	int ex_status = 0;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		ex_status = WEXITSTATUS(status);
		return (ex_status);
	}
	return (0);
}
