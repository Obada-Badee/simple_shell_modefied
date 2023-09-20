#include "main.h"

/**
 * changeDirectory - Change the current directory 
 * @newpwd: The path pf the new Directory 
 * Return: Nothing
 */
void changeDirectory(const char *newpwd) 
{   
    int retunstate, home_offset, oldpwd_offset;
    char buffer[1024];
    char *cwd;
    char *home = _getenv("HOME",&home_offset);
    char *oldpwd = _getenv("PWD",&oldpwd_offset);

    if (newpwd == NULL || strstr(newpwd, "") == 0)
    {
        newpwd = home;
    }
    else if (strstr(newpwd, "-") == 0)
    {
        newpwd = oldpwd;
    }

    retunstate = chdir(newpwd);
    if (retunstate != 0)
    {
        perror("Error");
        return;
    }

    cwd = getcwd(buffer, sizeof(buffer));
    if (cwd == NULL)
    {
        perror("Error");
        return;
    }

    _setenv("PWD", cwd, oldpwd_offset);
}
