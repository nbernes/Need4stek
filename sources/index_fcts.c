/*
** EPITECH PROJECT, 2018
** need4stek
** File description:
** index functions
*/

#include "nfs.h"

int index_str_char(char *str, char c, int occur)
{
	int res;

	if (occur <= 0)
		return (-1);
	for (res = 0; str[res]; res++) {
		if (str[res] == c)
			occur--;
		if (occur == 0)
			return (res);
	}
	return (-1);
}

int index_lidar(char *line)
{
	if (line == NULL)
		return (-1);
	if (atoi(line) != 1 || strncmp(line, "1:OK:No errors so far:", 21) != 0)
		return (-1);
	return (22);
}
