/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:59:52 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/20 19:40:26 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../so_long.h"

void	ft_new_game(t_game *game)
{
	int		height;
	int		width;

	game->imgs = malloc(sizeof(t_img) * (7 + 1));
	//CARGAMOS EL TAMPON DE LA PARED
	game->imgs[0].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "images/pared.xpm", &width, &height);
	game->imgs[0].data = (int *)mlx_get_data_addr(game->imgs[0].img_ptr, &game->imgs[0].bpp, &game->imgs[0].size_l, &game->imgs[0].endian);
	//CARGAMOS EL TAMPON DEL ESPACIO
	game->imgs[1].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "images/espacio.xpm", &width, &height);
	game->imgs[1].data = (int *)mlx_get_data_addr(game->imgs[1].img_ptr, &game->imgs[1].bpp, &game->imgs[1].size_l, &game->imgs[1].endian);
	//CARGAMOS EL TAMPON DEL COLECCIONABLE
	game->imgs[2].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "images/coleccionable.xpm", &width, &height);
	game->imgs[2].data = (int *)mlx_get_data_addr(game->imgs[2].img_ptr, &game->imgs[2].bpp, &game->imgs[2].size_l, &game->imgs[2].endian);
	//CARGAMOS EL TAMPON DEL PLAYER
	game->imgs[3].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "images/heroe.xpm", &width, &height);
	game->imgs[3].data = (int *)mlx_get_data_addr(game->imgs[3].img_ptr, &game->imgs[3].bpp, &game->imgs[3].size_l, &game->imgs[3].endian);
	//CARGAMOS EL TAMPON DE LA SALIDA
	game->imgs[4].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "images/exit.xpm", &width, &height);
	game->imgs[4].data = (int *)mlx_get_data_addr(game->imgs[4].img_ptr, &game->imgs[4].bpp, &game->imgs[4].size_l, &game->imgs[4].endian);
	//CARGAMOS EL TAMPON DE LA VILLANO CON LOS BRAZOS ARRIBA
	game->imgs[5].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "images/invader_down.xpm", &width, &height);
	game->imgs[5].data = (int *)mlx_get_data_addr(game->imgs[5].img_ptr, &game->imgs[5].bpp, &game->imgs[5].size_l, &game->imgs[5].endian);
	//CARGAMOS EL TAMPON DE LA VILLANO CON LOS BRAZOS ABAJO
	game->imgs[6].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr, "images/invader_up.xpm", &width, &height);
	game->imgs[6].data = (int *)mlx_get_data_addr(game->imgs[6].img_ptr, &game->imgs[6].bpp, &game->imgs[6].size_l, &game->imgs[6].endian);
}

char	ft_get_direction(int keycode)
{
	if (keycode == 13)
		return ('W');
	else if (keycode == 0)
		return ('A');
	else if (keycode == 1)
		return ('S');
	else if (keycode == 2)
		return ('D');
	else if (keycode == 53)
		exit (0);
	return ('0');
}

//keycode nos la da desde mlx_key_hook
int	ft_movements(int keycode, t_game *game)
{
	game->new_pos = ft_get_direction(keycode);
	if (ft_cant_move(game) == 0)
		return (0);
	if (game->new_pos == 'W')
	{
		game->cont = game->cont + 1;
		printf("Te has movido hacia arriba. Num de movimientos: %d \n", game->cont);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 1, 2, 2, "game->cont");
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x - 1;
		game->map[game->player_x][game->player_y] = 'P';
	}
	else if (game->new_pos == 'A')
	{
		game->cont = game->cont + 1;
		printf("Te has movido hacia la izquierda. Num de movimientos: %d \n", game->cont);
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y - 1;
		game->map[game->player_x][game->player_y] = 'P';
	}
	else if (game->new_pos == 'S')
	{
		game->cont = game->cont + 1;
		printf("Te has movido hacia abajo. Num de movimientos: %d \n", game->cont);
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x + 1;
		game->map[game->player_x][game->player_y] = 'P';
	}
	else if (game->new_pos == 'D')
	{
		game->cont = game->cont + 1;
		printf("Te has movido hacia la derecha. Num de movimientos: %d \n", game->cont);
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y + 1;
		game->map[game->player_x][game->player_y] = 'P';
	}
	if (game->collec == 0 && (game->map[game->player_x][game->player_y] == 'E'))
		exit (0);
	ft_print_map(game);
	return (0);
}

int	ft_cant_move(t_game *game)
{
	if (game->new_pos == 'W')
	{
		if (game->map[game->player_x - 1][game->player_y] == 'M')
			exit (0);
		else if (game->collec == 0 && game->map[game->player_x - 1][game->player_y] == 'E')
			exit (0);
		else if (game->map[game->player_x - 1][game->player_y] == '1' || game->map[game->player_x - 1][game->player_y] == 'E')
			return (0);

		else if (game->map[game->player_x - 1][game->player_y] == 'C')
		{
			game->collec--;
			return (1);
		}
	}
	if (game->new_pos == 'A')
	{
		if (game->map[game->player_x][game->player_y - 1] == 'M')
			exit (0);
		else if (game->collec == 0 && game->map[game->player_x][game->player_y - 1] == 'E')
			exit (0);
		else if (game->map[game->player_x][game->player_y - 1] == '1' || game->map[game->player_x][game->player_y - 1] == 'E')
			return (0);
		else if (game->map[game->player_x][game->player_y - 1] == 'C')
		{
			game->collec--;
			return (1);
		}
	}
	if (game->new_pos == 'S')
	{
		if (game->map[game->player_x + 1][game->player_y] == 'M')
			exit (0);
		else if (game->collec == 0 && game->map[game->player_x + 1][game->player_y] == 'E')
			exit (0);
		else if (game->map[game->player_x + 1][game->player_y] == '1' || game->map[game->player_x + 1][game->player_y] == 'E')
			return (0);
		else if (game->map[game->player_x + 1][game->player_y] == 'C')
		{
			game->collec--;
			return (1);
		}
	}
	if (game->new_pos == 'D')
	{
		if (game->map[game->player_x][game->player_y + 1] == 'M')
			exit (0);
		else if (game->collec == 0 && game->map[game->player_x][game->player_y + 1] == 'E')
			exit (0);
		else if (game->map[game->player_x][game->player_y + 1] == '1' || game->map[game->player_x][game->player_y + 1] == 'E')
			return (0);
		else if (game->map[game->player_x][game->player_y + 1] == 'C')
		{
			game->collec--;
			return (1);
		}
	}
	return (1);
}
/*
void	clean_img(t_game *game)
{
	int	i;

	i = 0;
	while (game->imgs[i].img_ptr)
	{
		mlx_destroy_image(game->mlx_ptr, game->img_ptr);
		i++;
	}
}*/
