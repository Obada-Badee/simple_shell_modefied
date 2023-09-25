#include "main2.h"

/**
 * process_lines - The function to execute what commands
 * @commands: The list were commands to be executed
 * @command_count: The number of lines/commands
 * Return: Always 0.
 */
void process_lines(char **commands, int command_count)
{
    int i;
    for (i = 0; i < command_count; i++)
    {
        printf("Command %d: %s\n", i + 1, commands[i]);
    }
}

/**
 * free_lines - Frees the lines 
 * @commands: The list were commands to be executed
 * @command_count: The number of lines/commands
 * Return: Always 0.
 */
void free_lines(char **commands, int command_count)
{
    int i;
    for (i = 0; i < command_count; i++)
    {
        free(commands[i]);
    }
    free(commands);
}