/*
** EPITECH PROJECT, 2018
** n4s : need_for_stek
** File description:
** need_for_stek
*/

#include "nfs.h"

int check_value(int max, int min, float speed, data_t *data)
{
	if (data->value < max && data->value > min) {
		data->speed = speed;
		dprintf(1, "CAR_FORWARD:%2.f", data->speed);
		return (true);
	}
	return (false);
}

int loop_race(data_t *data)
{
	float speed = 0.5;

	get_lidar(data);
	steer_car(&data->val, speed);
	speed = adjust_car_speed(&data->val, speed, data);
	if (speed == -84 || speed == -1)
		return (speed * (-1));
	return (0);
}

int need_for_stek(void)
{
	data_t *data = malloc(sizeof(data_t));
	int loop = 0;

	if (data == NULL)
		return (84);
	data->val.prev = NULL;
	data->lidar = NULL;
	my_free(check_getline("START_SIMULATION\n", data));
	my_free(check_getline("CAR_FORWARD:0.5\n", data));
	get_lidar(data);
	if (check_dead_end(data) == -1) {
		free_data(data);
		return (0);
	}
	while (loop == 0)
		loop = loop_race(data);
	free_data(data);
	my_free(check_getline("CAR_FORWARD:0\n", data));
	my_free(check_getline("CYCLE_WAIT:50\n", data));
	my_free(check_getline("STOP_SIMULATION\n", data));
	return (loop);
}
