/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 09:24:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/30 09:26:18 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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

typedef struct s_enemy
{
	int		enemy_x;
	int		enemy_y;
	int		direction;
}	t_enemy;

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
	t_enemy	*enemies;
	int		movement;
	int		temp_move;
	int		alive;
	int		game_num_enemies;
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
int		ft_surrounded_x(t_game *game);
int		ft_surrounded_y(t_game *game);
int		ft_leaps(t_game *game);
char	ft_get_direction(int keycode);
int		ft_movements(int keycode, t_game *game);
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
void	ft_more_print(t_game *game, int cont1, int cont2);
char	*ft_itoa(int n);
void	ft_destroy(t_game *game);
int		ft_move_enemy(t_game *game);
int		ft_kill_plus(t_game *game);
void	ft_num_enemies_in_map(t_game *game);
int		ft_move_right_and_left(t_game *game, int cont_e);
int		ft_move_right(t_game *game, int cont_e);
int		ft_more_movements(t_game *game);
int		ft_more_more_movements(t_game *game);
int		ft_movements(int keycode, t_game *game);
void	ft_print_others(t_game *game, int cont1, int cont2);
int		ft_print_invaders(t_game *game, int cont1, int cont2, int cont_e);
int		ft_press_p(t_game *game, int cont1, int cont2);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
int		ft_continue_reading(t_game *game, int fd, int i);
int		ft_if_win(t_game *game);
void	ft_print_all(t_game *game);
void	ft_start(int argc, char **argv, t_game *game);

#endif
