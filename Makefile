# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 12:03:54 by amurcia-          #+#    #+#              #
#    Updated: 2023/04/17 13:37:36 by amurcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRC = 	src/main.c \
		src/check.c src/check_map.c src/check_walls.c \
		src/read_map.c src/upload_images.c src/print_tile.c src/print_map.c src/cant_move.c  src/free.c src/movements.c\
		src/utils/ft_split.c src/utils/get_next_line.c src/utils/strings1.c src/utils/strings2.c \

SRC_BONUS = bonus/src/main_bonus.c bonus/src/check_bonus.c bonus/src/game_bonus.c bonus/src/get_next_line_bonus.c \
			bonus/src/map_bonus.c bonus/src/utils_bonus.c bonus/src/ft_split_bonus.c bonus/src/free_bonus.c bonus/src/cant_move_bonus.c \
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
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ_BONUS) -o $(NAME_BONUS)

run  : 
	./so_long maps/map1.ber
	
run_b  : 
	./so_long maps/map1.ber
	
clean :
	$(RM) $(OBJ)
	$(RM) $(DEPS)
	$(RM) $(OBJ_BONUS)
	$(RM) $(DEPS_BONUS)
	$(RM) @
	make clean -C mlx

fclean : clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re : fclean all

re_b : fclean bonus

.PHONY : all clean fclean re
