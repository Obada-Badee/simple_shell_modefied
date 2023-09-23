#include "main.h"

/**
 * search_execute - Serach for the command and execute it if found
 *
 * Return: void
 */
void search_execute(char *command)
{
	char **args, *full_path;

	args = split_string(*command, " \n");

	if (search_builtins(args[0], args))
	{
		free_tokens(args);
	}

	full_path = find_file(args[0]);

	if (full_path == NULL)
	{
		free_tokens(args);
		perror("Error");
	}
	execute(args, full_path);
	free_tokens(args);
}