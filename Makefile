# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 12:03:54 by amurcia-          #+#    #+#              #
#    Updated: 2022/07/04 21:47:05 by amurcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c src/check.c src/game.c src/get_next_line.c src/map.c src/utils.c src/ft_split.c \
			free.c src/cant_move.c src/check_if_surrounded.c src/upload_images.c src/ft_strnstr.c

SRC_BONUS = bonus/main_bonus.c bonus/src/check_bonus.c bonus/src/game_bonus.c bonus/src/get_next_line_bonus.c \
			bonus/src/map_bonus.c bonus/src/utils_bonus.c bonus/src/ft_split_bonus.c bonus/free_bonus.c bonus/src/cant_move_bonus.c \
			bonus/src/enemigos_bonus.c bonus/src/ft_itoa_bonus.c bonus/src/check_if_surrounded_bonus.c \
			bonus/src/upload_images_bonus.c bonus/src/print_map_bonus.c bonus/src/ft_strnstr_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

DEPS = $(SRC:.c=.d)
DEPS_BONUS = $(SRC_BONUS:.c=.d)

HEADER = so_long.h
HEADER_BONUS = bonus/so_long_bonus.h

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror -MMD

%.o : %.c
	make -C mlx
	$(CC) -c $(FLAGS) -Imlx -I mlx/mlx.h $< -o $@

all: $(NAME)

-include $(DEPS)

$(NAME) : $(OBJ) $(HEADER) $(HEADER_BONUS)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ_BONUS) -o $(NAME)
	touch @

clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	$(RM) $(OBJ_BONUS)
	$(RM) $(DEPS_BONUS)
	make clean -C mlx

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
