/*
** EPITECH PROJECT, 2018
** n4s : get_lidar
** File description:
** get lidar
*/

#include "nfs.h"

char **get_array_lidar(char **array)
{
	char **lidar = malloc(sizeof(char *) * 17);

	for (int i = 0; i < 16; i++)
		lidar[i] = strdup(array[i + 2]);
	for (unsigned int i = 0; i < strlen(lidar[15]); i++)
		if (lidar[15][i] == '\n')
			lidar[15][i] = '\0';
	lidar[16] = NULL;
	return (lidar);
}

void get_lidar(data_t *data)
{
	char *line = NULL;
	int cnt;

	line = check_getline("GET_INFO_LIDAR\n", data);
	if (line == NULL)
		return;
	for (cnt = 0; line[cnt] != '\n'; cnt++);
	line[cnt] = '\0';
	if (index_lidar(line) == -1) {
		data->lidar = NULL;
		free(line);
		return;
	}
	data->lidar = str_to_word_array(&line[index_lidar(line)], ':');
	free(line);
	if (!data->lidar)
		exit(84);
	get_landmark_values(data->lidar, &data->val);
	get_biggest_value(data->lidar, &data->val);
}
