/*
** EPITECH PROJECT, 2018
** stay_in_the_center.c
** File description:
** ...
*/

#include "nfs.h"

int stay_in_center(values_t *val, float speed)
{
	char *line = NULL;
	size_t size = 0;
	float dir = (val->left - val->right) / (3010 * speed * 4);

	dprintf(1, "WHEELS_DIR:%.2f\n", dir);
	getline(&line, &size, stdin);
	my_free(line);
	return (EXIT_SUCCESS);
}

int steer_car(values_t *val, float speed)
{
	char *line = NULL;
	size_t size = 0;

	if (val->top > val->left && val->top > val->right)
		stay_in_center(val, speed);
	else {
		dprintf(1, "WHEELS_DIR:%.2f\n", val->dir);
		getline(&line, &size, stdin);
		my_free(line);
	}
	val->prev = NULL;
	val->prev = val;
	return (EXIT_SUCCESS);
}
