/**
 * _strstr - Locate a substring
 * @haystack: The string to be searched
 * @needle: The substring that should be located
 *
 * Return: A pointer to the beginning of the located
 *	   substring, or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int index;

	if (*needle == 0)
	{
		return (haystack);
	}
	while (*haystack)
	{
		index = 0;

		while (*(haystack + index) == needle[index] && needle[index])
		{
			if (needle[index + 1] == '\0')
			{
				return (haystack);
			}
			index++;
		}
		haystack++;

	}

	return (0);
}