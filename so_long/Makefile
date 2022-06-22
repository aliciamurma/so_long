# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/10 12:03:54 by amurcia-          #+#    #+#              #
#    Updated: 2022/06/20 12:58:40 by amurcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = main.c src/check.c src/game.c src/get_next_line.c src/map.c src/utils.c src/ft_split.c free.c src/enemigos.c

OBJ = $(SRC:.c=.o)

HEADER = so_long.h

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o : %.c
	make -C mlx
	$(CC) -c $(FLAGS) -Imlx -I mlx/mlx.h $< -o $@

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

clean :
	$(RM) $(OBJ)
	make clean -C mlx

fclean : clean
	$(RM) $(NAME)
	make clean -C mlx
	
re : fclean all

.PHONY : all clean fclean re