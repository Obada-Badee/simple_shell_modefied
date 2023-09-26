#include "main2.h"

/**
 * _getlines - Super simple shell
 * @commands: The list were commands will be stored
 * @lines_count: An integer pointer to the number of lines/commands
 * Return: Always 0.
 */
void _getlines(char **commands, int *lines_count)
{
    char page[MAX_LINE_LENGTH];
    char *trimmed_line;
    char *end;
    char *line;
    ssize_t bytes_read;
    char ch;
    int i;     /* to go through buffer */
    int j = 0; /*to got through lines */

    line = (char *)malloc(MAX_LINE_LENGTH * sizeof(page));

    bytes_read = read(STDIN_FILENO, page, sizeof(page));
    page[bytes_read] = '\0';

    for (i = 0; i < bytes_read; i++)
    {
        ch = page[i];
        if (ch == '\n')
        {
            line[j] = '\0';
            j = 0;
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
        }
        else
        {
            line[j++] = ch;
        }
    }
    free(line);
}