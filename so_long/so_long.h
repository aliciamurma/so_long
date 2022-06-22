#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include "mlx/mlx.h"

# define BUFFER_SIZE 1
# define SIZE 32
//inicializa las variables y al final del aprentesis se le da el nombre y debe ir a una libreria

//definimos las variables de las imagenes
typedef struct	s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	//identidad del juego
	void	*mlx_ptr;
	//identidad de la ventada
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
	int		pos_temp;
	int		player_x;
	int		player_y;
	int		cont;
	int		enemy_x;
	int		enemy_y;
}	t_game;
/*
move gives the list of sprites for a player
typedef struct	s_move
{
	t_list	*up;
	t_list	*down;
	t_list	*right;
	t_list	*left;
}	t_move;*/

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
int 	ft_check_caracteres(t_game *game);
int 	ft_solo_caracteres(t_game *game);
void	ft_free_memory(t_game *game);
void	ft_free_map_matrix(t_game *game);
int 	ft_rodeado_x(t_game *game);
int 	ft_rodeado_y(t_game *game);
int 	ft_no_saltos(t_game *game);
char	ft_get_direction(int keycode);
int		ft_movements(int keycode, t_game *game);
int		ft_cant_move(t_game *game);
void	clean_img(t_game *game);
int		ft_exit(t_game *game);
int	ft_move_enemy(t_game *game);

#endif
