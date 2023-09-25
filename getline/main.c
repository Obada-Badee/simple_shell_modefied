#include "main2.h"

/**
 * main - Super simple shell
 *
 * Return: Always 0.
 */
int main() {
    char **commands = NULL;
    int commandCount = 0;

    printf("$ ");

    _getlines(commands, &commandCount);
    process_lines(commands, commandCount);
    free_lines(commands, commandCount);

    return 0;
}