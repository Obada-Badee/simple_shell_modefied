#include "main.h"
#include <stdlib.h>

#define BUFFER_SIZE 256
/**
 * _gtline - gets a line from standrad input
 * @lineptr: Pointer to char
 * @fd: file discriptor to read from
 * Return: Number of Bits read
 **/
int _gtline(char **lineptr, int fd)
{   
    static char buffer[BUFFER_SIZE];
    static int buffer_index = 0 , bytes_read = 0;
    int line_index = 0, line_size = BUFFER_SIZE;

    *lineptr = (char *) malloc(BUFFER_SIZE * sizeof(char));

    if (*lineptr == NULL)
    {
        free(*lineptr);
        return -1;
    }
    bytes_read = read(fd, buffer, BUFFER_SIZE);
    if (bytes_read <= 0)
    {   
        free(*lineptr);
        return -1;
    }
    while(1)
    {
        while (buffer_index < bytes_read) 
        {
            char ch = buffer[buffer_index++];
            if (ch == '\n' || ch == '#') {
                (*lineptr)[line_index] = '\0';
                return line_index;
            }
            if (line_index >= line_size - 1) 
            {
                free(*lineptr);
                return -1;
            }
            (*lineptr)[line_index++] = ch;
        }
    }
    free(*lineptr);
    return -1;
}
