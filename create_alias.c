#include "main.h"

/**
 * search_alias - search if the alias is in the aliases list
 * @alias: The alias to find
 *
 * Return: If the alias is found - pointer to the alias
 *	   otherwise - NULL
 */
alias_t *search_alias(char *alias)
{
	alias_t **h_ptr = get_head();

	while (*h_ptr)
	{
		if (_strcmp((*h_ptr)->name, alias) == 0)
			return (*h_ptr);

		*h_ptr = (*h_ptr)->next;
	}

	return (NULL);
}

/**
 * create_alias - Add the new alias to the aliases linked list
 * @alias: The alias to add
 *
 * Return: void
 */
void create_alias(char *alias)
{
	alias_t **head_ptr = get_head(), *alias_found;
	char **name_val_arr = split_string(alias, "=");

	alias_found = search_alias(name_val_arr[0]);

	if (alias_found)
	{
		printf("here");
		free(alias_found->value);
		alias_found->value = _strdup(name_val_arr[1]);
	}
	else
	{
		add_alias_end(head_ptr, name_val_arr[0], name_val_arr[1]);
	}
	clean(name_val_arr);
}
