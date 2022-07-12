/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:20:15 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/30 09:23:04 by amurcia-         ###   ########.fr       */
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

void	ft_new_game(t_game *game);
int		ft_check_parameters(int argc, char **argv);
char	*get_next_line(int fd);
char	*ft_read(int fs, char *ptr);
char	*ft_cutword(char *ptr);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *s1);
char	*ft_cutword(char *prt);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *ptr);
int		ft_print_map(t_game *game);
int		ft_read_map(t_game *game, char **argv);
char	**ft_split(char *s, char c);
int		ft_check_caracteres(t_game *game);
int		ft_only_caracteres(t_game *game);
int		ft_free_memory(t_game *game);
void	ft_free_map_matrix(t_game *game);
int		ft_rodeado_x(t_game *game);
int		ft_rodeado_y(t_game *game);
int		ft_no_saltos(t_game *game);
char	ft_get_direction(int keycode);
int		ft_movements(int keycode, t_game *game);
int		ft_more_more_movements(t_game *game);
int		ft_cant_move(t_game *game);
void	clean_img(t_game *game);
int		ft_press_p(t_game *game, int cont1, int cont2);
void	ft_error_map(t_game *game);
int		ft_error_read(t_game *game);
int		ft_cant_a(t_game *game);
int		ft_cant_s(t_game *game);
int		ft_cant_w(t_game *game);
int		ft_cant_d(t_game *game);
void	ft_upload_images(t_game *game, int height, int width);
int		ft_more_movements(t_game *game);
void	ft_more_print(t_game *game, int cont1, int cont2);
char	*ft_itoa(int n);
void	ft_destroy(t_game *game);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
int		ft_continue_reading(t_game *game, int fd, int i);

#endif
