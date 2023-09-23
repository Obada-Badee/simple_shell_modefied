#include "main.h"

/**
 * handle_separator - It executes the function related to each Seperator
 * @commands: List of command to be executed
 * @separator: The separator to exexute a function based on  
 * Return: void
 */
void handle_separator(char **commands ,int code)
{
    switch (code)
    {
    case 1:
        handle_colon(commands);
        break;
    case 2:
        handle_anding(commands);
        break;
    case 3:
        handle_oring(commands);
        break;
    case -1:
        perror('Error');
    }
}

/**
 * check_separator - Searh a buffer for some seprator 
 * @buff: Buffer to be searched for a seprator
 * Return: Returns an int 
 */
int check_separator(char *buff)
{
    if (_strstr(buff,";'"))
        return (1);
    else if (_strstr(buff,"&&"))
        return (2);
    else if (_strstr(buff,"||"))
        return (3);
    else
        return(0);
}

/**
 * handle_anding - handles and Executes the command seperated by '&&'
 * @commands: List of command to be separated
 * Return: void
 */
void handle_anding(char **commands)
{
    int *last_exit_code;

    search_execute(*commands++);
    while (*commands)
    {
        *last_exit_code = get_exit_status;
        if (last_exit_code == EXIT_SUCCESS)
            search_execute(*commands++);
        else
            break;
    }
}

/**
 * handle_oring - handles and Executes the command seperated by '||'
 * @commands: List of command to be separated
 * Return: void
 */
void handle_oring(char **commands)
{
    int *last_exit_code;

    search_execute(*commands++);
    while (*commands)
    {
        last_exit_code = get_exit_status;
        if (last_exit_code == EXIT_SUCCESS)
            break;
        else
            search_execute(*commands++);
    }
}

/**
 * handle_colon - handles and Executes the command seperated by ';'
 * @commands: List of command to be separated
 * Return: void
 */
void handle_colon(char **commands)
{
    while (*commands)
        search_execute(*commands++);
}
