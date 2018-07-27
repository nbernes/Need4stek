/*
** EPITECH PROJECT, 2017
** fill_double_array
** File description:
** fills a double array based on the buffer's content
*/

#include "nfs.h"

int find_params_nbr(char *str, char wall)
{
	int cnt;
	int params = 1;

	for (cnt = 0; str[cnt] != '\0'; cnt++)
		if ((str[cnt] == wall) && (str[cnt + 1] > 32))
			params++;
	return (params);
}

int find_start_of_word(char *str, int pos, char wall)
{
	while (str[pos] == wall && str[pos] != '\0')
		pos++;
	return (pos);
}

int find_end_of_word(char *str, int pos, char wall)
{
	while (str[pos] != wall && str[pos] != '\0')
		pos++;
	return (pos);
}

char **alloc_each_row(char **arr, arr_t *pos, char *str, char wall)
{
	for (pos->row = 0; pos->row < pos->rows; pos->row++) {
		pos->col = find_start_of_word(str, pos->col, wall);
		pos->cols = find_end_of_word(str, pos->col, wall);
		pos->cols -= pos->col;
		arr[pos->row] = malloc(sizeof(char) * (pos->cols + 1));
		if (!arr[pos->row])
			return (NULL);
		arr[pos->row][pos->cols] = '\0';
		for (pos->cnt = 0; pos->cnt < pos->cols; pos->cnt++)
			arr[pos->row][pos->cnt] = str[pos->col++];
	}
	return (arr);
}

char **str_to_word_array(char *str, char wall)
{
	arr_t pos = {0, 0, 0, 0, 0};
	char **arr;

	if (str == NULL)
		return (NULL);
	pos.rows = find_params_nbr(str, wall);
	arr = malloc(sizeof(char *) * (pos.rows + 1));
	if (!arr)
		return (NULL);
	arr[pos.rows] = NULL;
	arr = alloc_each_row(arr, &pos, str, wall);
	if (!arr)
		return (NULL);
	return (arr);
}
