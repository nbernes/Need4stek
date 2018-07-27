/*
** EPITECH PROJECT, 2018
** n4s
** File description:
** speed values
*/

#include "nfs.h"

float get_wheels_dir(data_t *data)
{
	float wheels;
	char *line = check_getline("GET_CURRENT_WHEELS\n", data);

	if (index_str_char(line, ':', 3) == -1)
		return (return_free(EXIT_ERROR, line));
	wheels = atof(&line[index_str_char(line, ':', 3) + 1]);
	return (return_free(wheels, line));
}

int go_backwards(data_t *data)
{
	float wheels = 0;
	char *line = NULL;
	size_t n = 0;

	if (data->val.left < 300 && data->val.right > 300)
		wheels = -0.5;
	else if (data->val.right < 300 && data->val.left > 300)
		wheels = 0.5;
	dprintf(1, "WHEELS_DIR:%.2f\n", wheels);
	if (getline(&line, &n, stdin) == -1)
		return (return_free(EXIT_ERROR, line));
	my_free(line);
	my_free(check_getline("CAR_BACKWARDS:0.5\n", data));
	if (usleep(1000000) == -1)
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

float check_proximity(values_t *val, data_t *data)
{
	if (val->top < 150 || val->left < 100 || val->right < 100)
		if (go_backwards(data) == EXIT_ERROR)
			return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

float get_speed(values_t *val, float speed)
{
	if (val->top > 1000)
		speed = 1.0;
	else {
		speed = (int)val->top % 1000 / 100;
		speed /= 10;
	}
	if (speed > 0.1 && (val->left < 200 || val->right < 200))
		speed /= 2;
	if (speed < 0.1)
		speed = 0.1;
	return (speed);
}

float adjust_car_speed(values_t *val, float speed, data_t *data)
{
	char *line = NULL;
	int i = 0;
	size_t n = 0;

	if (check_proximity(val, data) == EXIT_ERROR)
		return (EXIT_ERROR);
	get_speed(val, speed);
	dprintf(1, "car_forward:%.2f\n", speed);
	if (getline(&line, &n, stdin) == -1)
		return (return_free(EXIT_ERROR, line));
	i = check_end_track(line);
	switch (i) {
	case 1: return (return_free(-1, line));
	case 84: return (return_free(-84, line));
	default : return (return_free(speed, line));
	}
}
