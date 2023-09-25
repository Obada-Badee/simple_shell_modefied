#include "main2.h"

/**
 * _getlines - Super simple shell
 * @commands: The list were commands will be stored
 * @lines_count: An integer pointer to the number of lines/commands
 * Return: Always 0.
 */
void _getlines(char **commands, int *lines_count)
{
    char line[MAX_LINE_LENGTH];
    char *trimmed_line;
    char *end;
    ssize_t bytes_read;

    while ((*lines_count < MAX_COMMANDS) && (bytes_read = read(STDIN_FILENO, line, sizeof(line))) > 0)
    {
        line[bytes_read] = '\0'; /*Null-terminate the line*/

        /*Remove leading and trailing whitespace*/
        trimmed_line = line;
        while (*trimmed_line && (*trimmed_line == ' ' || *trimmed_line == '\t'))
            trimmed_line++;

        end = trimmed_line + strlen(trimmed_line) - 1;
        while (end > trimmed_line && (*end == ' ' || *end == '\t'))
            end--;
        *(end + 1) = '\0';

        /*Skip empty lines*/
        if (strlen(trimmed_line) == 0)
            continue;

        commands[*lines_count] = strdup(trimmed_line);
        (*lines_count)++;
        free(trimmed_line);
        free(end);
    }
}