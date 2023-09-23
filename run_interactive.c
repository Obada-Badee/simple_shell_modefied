#include "main.h"

/**
 * run_interactive - Execute the shell commands in the interactive mode
 *
 * Return: void
 */
void run_interactive(void)
{
    char *buff = NULL ,**commands;
    int is_seperator;
    size_t n;
    while (1)
	{
        write(STDOUT_FILENO, "$ ", 2);
        
	    if (getline(&buff, &n, stdin) == -1)
		    exit(1);
        
        is_seperator = check_separator(buff,commands);

        if (separator)
        {
            continue;
        }
        else
        {
            search_execute(buff);
        }
        free(buff);
        free_tokens(commands);
    }
}
