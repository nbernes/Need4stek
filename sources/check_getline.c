/*
** EPITECH PROJECT, 2018
** n4s : check_getline
** File description:
** check the getline
*/

#include "nfs.h"

char *check_getline(char *str, data_t *data)
{
	char *line = NULL;
	size_t size = 0;

	dprintf(1, str);
	if (getline(&line, &size, stdin) == -1) {
		if (getline(&line, 0, stdin) == -1) {
			dprintf(2, "nothing to read\n");
			free(line);
			free_data(data);
			dprintf(2, "nothing to read\n");
			exit(84);
		}
	} else
		return (line);
	return (NULL);
}
