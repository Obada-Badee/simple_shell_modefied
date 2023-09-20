#include "main.h"

/**
 * main - Super simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	copy_to_heap();

	if (!isatty(STDIN_FILENO))
		run_non_interactive();
	else
		run_interactive();

	clean(environ);

	return (0);
}
