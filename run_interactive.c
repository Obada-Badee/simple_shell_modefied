#include "main.h"

/**
 * run_interactive - Execute the shell commands in the interactive mode
 *
 * Return: void
 */
void run_interactive(void)
{
    char *separator ,*buff = NULL ,**commands;
    size_t n;
    while (1)
	{
        write(STDOUT_FILENO, "$ ", 2);
        
	    if (getline(&buff, &n, stdin) == -1)
		    exit(1);
        
        separator = check_separator(buff);

        if (separator)
        {
            commands = split_string(buff,separator);
            handle_separator(commands,separator);
        }
        else
        {
            search_execute(buff);
        }
        free(buff);
        free_tokens(commands);
    }
}
