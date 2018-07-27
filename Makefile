##
## EPITECH PROJECT, 2018
## n4s : Makefile
## File description:
## Compilation via makefile
##

NAME	=	ai

SOURCE	=	sources/

SOURCES	=	$(SOURCE)main.c			\
		$(SOURCE)need_for_stek.c	\
		$(SOURCE)get_lidar.c		\
		$(SOURCE)sort_lidar_values.c	\
		$(SOURCE)steer_car.c		\
		$(SOURCE)str_to_word_array.c	\
		$(SOURCE)index_fcts.c		\
		$(SOURCE)adjust_car_speed.c	\
		$(SOURCE)check_end_track.c	\
		$(SOURCE)nfs_little_fcts.c	\
		$(SOURCE)check_getline.c

OBJ	=	$(SOURCES:%.c=%.o)

INCLUDE	=	-I./include

CFLAGS	=	$(INCLUDE) -W -Wall -Wextra -Wshadow

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re
