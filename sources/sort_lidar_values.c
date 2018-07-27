/*
** EPITECH PROJECT, 2018
** sort_lidar_values.c
** File description:
** ...
*/

#include "nfs.h"

void get_biggest_value(char **array, values_t *val)
{
	int cnt = 0;
	float value = 0;
	float tmp = 0;
	float index = 0;

	for (; cnt < 32; cnt++) {
		tmp = strtof(array[cnt], NULL);
		if (tmp > value) {
			value = tmp;
			index = cnt + 1 - 16;
		}
	}
	index *= 0.69;
	val->dir = -index / 15 * 0.3;
}

int get_landmark_values(char **array, values_t *val)
{
	val->left = strtof(array[0], NULL);
	val->right = strtof(array[31], NULL);
	val->top = strtof(array[15], NULL);
	return (EXIT_SUCCESS);
}
