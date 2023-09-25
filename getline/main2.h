#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1000

/**
 * _getlines - Super simple shell
 * @commands: The list were commands will be stored
 * @command_count: An integer pointer to the number of lines/commands
 * Return: Always 0.
 */
void _getlines(char **commands, int *lines_count);

/**
 * process_lines - Super simple shell
 * @commands: The list were commands to be executed
 * @command_count: The number of lines/commands
 * Return: Always 0.
 */
void process_lines(char **commands, int command_count);

/**
 * free_lines - Frees the lines 
 * @commands: The list were commands to be executed
 * @command_count: The number of lines/commands
 * Return: Always 0.
 */
void free_lines(char **commands, int command_count);


#endif /* MAIN_H */