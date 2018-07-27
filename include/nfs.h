/*
** EPITECH PROJECT, 2018
** n4s : nfs.h
** File description:
** include
*/

#ifndef __NFS_H__
#define __NFS_H__

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_ERROR 84

struct landmark_values {
	float left;
	float top;
	float right;
	float dir;
	struct landmark_values *prev;
};

typedef struct landmark_values values_t;

struct data {
	float speed;
	float angle;
	values_t val;
	char **lidar;
	int value;
};

typedef struct data data_t;

int need_for_stek(void);
int loop_race(data_t *);
void get_lidar(data_t *);
char **get_array_lidar(char **);
int get_landmark_values(char **, values_t *);
int stay_in_center(values_t *, float);
int steer_car(values_t *, float);
int manage_turns(float, float, int);
int index_lidar(char *);
float get_wheels_dir(data_t *data);
int go_backwards(data_t *data);
float check_proximity(values_t *val, data_t *data);
float get_speed(values_t *val, float speed);
float adjust_car_speed(values_t *, float, data_t *);
int check_dead_end(data_t *);
void free_data(data_t *data);
int check_end_track(char *);
int index_str_char(char *, char, int);
void my_free(void *ptr);
void *my_malloc(int size);
void free_data(data_t *);
int return_free(int, void *);
void my_free_tab(char **tab);
char *check_getline(char *, data_t *);
float get_simtime(void);
int get_delay(values_t *);
void get_biggest_value(char **, values_t *);

/* STR_TO_WORD_ARRAY */

struct arr {
	int col;
	int cols;
	int row;
	int rows;
	int cnt;
};

typedef struct arr arr_t;

char **str_to_word_array(char *str, char wall);
int find_end_of_word(char *str, int pos, char wall);
int find_start_of_word(char *str, int pos, char wall);
int find_params_nbr(char *str, char wall);

#endif
