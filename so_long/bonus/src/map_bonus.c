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

#include "../so_long_bonus.h"
#include "../mlx/mlx.h"

//leemos el mapa y guardamos el mapa en map_bak

void	ft_num_enemies_in_map(t_game *game)
{
	int	cont;

	cont = 0;
	game->game_num_enemies = 0;
	while (game->map_bak[cont] != '\0')
	{
		if (game->map_bak[cont] == 'M')
			game->game_num_enemies++;
		cont++;
	}
}

int	ft_continue_reading(t_game *game, int fd, int i)
{
	char	*line;

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
	ft_num_enemies_in_map(game);
	game->width = i - 1;
	return (fd);
}

int	ft_read_map(t_game *game, char **argv)
{
	int		fd;
	size_t	i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nNo se puede abrir\n");
		exit(1);
	}
	fd = ft_continue_reading(game, fd, i);
	close(fd);
	return (0);
}

int	ft_press_p(t_game *game, int cont1, int cont2)
{
	game->player_x = cont1;
	game->player_y = cont2;
	if (game->pos_player == 'W')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[3].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	else if (game->pos_player == 'S')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[7].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	else if (game->pos_player == 'A')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[8].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[9].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	return (1);
}
