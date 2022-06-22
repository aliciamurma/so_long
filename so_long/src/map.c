/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:40:53 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/20 12:46:06 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//abrir el mapa, coger el contenido y guardarlo en una variable, map_bak

#include "../so_long.h"

//leemos el mapa y guardamos el mapa en map_bak
int	ft_read_map(t_game *game, char **argv)
{
	char	*line;
	int		fd;
	size_t	i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return (1);
	game->map_bak = NULL;
	game->height = ft_strlen(line) - 1;
	while (line)
	{
		game->width = ft_strlen(line) - 1;
		game->map_bak = ft_strjoin(game->map_bak, line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	free (line);
	game->width = i - 1;
	close(fd);
	return (0);
}

int	ft_print_map(t_game *game)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	game->collec = 0;
	//PONER IMAGEN EN PANTALLA
	while (game->map[cont1])
	{
		cont2 = 0;
		while (game->map[cont1][cont2])
		{
			if (game->map[cont1][cont2] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->imgs[0].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
			else if (game->map[cont1][cont2] == '0')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->imgs[1].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
			else if (game->map[cont1][cont2] == 'C')
			{
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->imgs[2].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
				game->collec++;
			}
			else if (game->map[cont1][cont2] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->imgs[4].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
			else if (game->map[cont1][cont2] == 'P')
			{
				game->player_x = cont1;
				game->player_y = cont2;
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->imgs[3].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
			}
			else if (game->map[cont1][cont2] == 'M')
			{
				game->enemy_x = cont1;
				game->enemy_y = cont2;
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->imgs[6].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
			}
			cont2++;
		}
		cont1++;
	}
	return (1);
}
