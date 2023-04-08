/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:20:15 by amurcia-          #+#    #+#             */
/*   Updated: 2023/04/08 18:22:41 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 1
# define SIZE 32

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	char	*map_bak;
	t_img	*imgs;
	int		error;
	int		new_pos;
	int		width;
	int		height;
	int		collec;
	int		player;
	int		pos_player;
	int		player_x;
	int		player_y;
	int		cont;
	int		col;
	int		ext;
	int		playr;
	int		enemy_x;
	int		enemy_y;
	int		movement;
	int		temp_move;
}	t_game;

// CHECK
void	ft_errors(int argc, char **argv, t_game *game);
int		ft_error_read(t_game *game);
void	ft_error_map(t_game *game);

// CHECK MAP
int		ft_check_parameters(int argc, char **argv);
int		ft_only_caracteres(t_game *game);
int		ft_check_caracteres(t_game *game);

// CHECK_WALLS
int		ft_surrounded_x(t_game *game);
int		ft_surrounded_y(t_game *game);
int		ft_leaps(t_game *game);

// UPLOAD_IMAGES
void	ft_new_game(t_game *game);

// UTILS
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
char	*ft_itoa(int n);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	**ft_split(char *s, char c);

// READ MAP
int		ft_continue_reading(t_game *game, int fd, int i);
int		ft_read_map(t_game *game, char **argv);

// FREE
void	ft_destroy(t_game *game);
void	ft_free_map_matrix(t_game *game);
int		ft_free_memory(t_game *game);

// PRINT MAP
void	ft_print_map(t_game *game);

// MOVEMENTS
int		ft_movements(int keycode, t_game *game);

// CANT MOVE
int		ft_cant_move(t_game *game);

// PRINT_TILE
int		ft_print_player(t_game *game, int cont1, int cont2);
void	ft_print_nothing(t_game *game, int cont1, int cont2);
void	ft_print_collect(t_game *game, int cont1, int cont2);
void	ft_print_wall(t_game *game, int cont1, int cont2);
void	ft_print_exit(t_game *game, int cont1, int cont2);

#endif
