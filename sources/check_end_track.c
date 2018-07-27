/*
** EPITECH PROJECT, 2018
** n4s : check_end_track
** File description:
** check if the car has reached the end of the track
*/

#include "nfs.h"

int check_end_track(char *str)
{
	char **array = str_to_word_array(str, ':');

	if (array == NULL)
		return (EXIT_ERROR);
	else if (array[3] != NULL && strcmp(array[3], "Track Cleared") == 0) {
		my_free_tab(array);
		return (1);
	} else {
		my_free_tab(array);
		return (0);
	}
}

int check_dead_end(data_t *data)
{
	for (int i = 7; i < 25; i++)
		if (atof(data->lidar[i]) != atof(data->lidar[i + 1]) && \
atof(data->lidar[i]) != atof(data->lidar[i + 1]) + 250 && \
atof(data->lidar[i]) + 250 != atof(data->lidar[i + 1]))
			return (0);
	return (-1);
}
