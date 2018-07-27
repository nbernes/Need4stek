/*
** EPITECH PROJECT, 2018
** nfs
** File description:
** little functions
*/

#include "nfs.h"

void my_free(void *ptr)
{
	if (!ptr)
		return;
	free(ptr);
}

void *my_malloc(int size)
{
	void *ptr;

	if (size <= 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	return (ptr);
}

void my_free_tab(char **tab)
{
	if (tab == NULL)
		return;
	for (int i = 0; tab[i]; i++)
		my_free(tab[i]);
	my_free(tab);
}

void free_data(data_t *data)
{
	my_free_tab(data->lidar);
	my_free(data);
}

int return_free(int return_val, void *ptr)
{
	my_free(ptr);
	return (return_val);
}
