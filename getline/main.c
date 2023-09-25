#include "main2.h"

/**
 * main - Super simple shell
 *
 * Return: Always 0.
 */
int main(int argc, char* argv[]) {
    char **commands = malloc(MAX_COMMANDS * sizeof(char *));
    int commandCount = 0;

    /*write(STDOUT_FILENO, "$ ", 2);
    _getlines(commands, &commandCount);
    process_lines(commands, commandCount);*/

    for (int i = 0; i < argc; i++) 
    {
        printf("%s\n", argv[i]);
    }

    return 0;
}