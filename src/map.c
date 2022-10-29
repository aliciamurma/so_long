/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:40:53 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/29 20:48:23 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

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
			game->imgs[5].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	else if (game->pos_player == 'A')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[6].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[7].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	return (1);
}

void	ft_more_print(t_game *game, int cont1, int cont2)
{
	if (game->map[cont1][cont2] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[1].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	else if (game->map[cont1][cont2] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[2].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
		game->collec++;
	}
}

void	ft_print_map(t_game *game)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	game->collec = 0;
	while (game->map[cont1])
	{
		cont2 = 0;
		while (game->map[cont1][cont2])
		{
			if (game->map[cont1][cont2] == '1')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->imgs[0].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
			else if (game->map[cont1][cont2] == 'E')
				mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
					game->imgs[4].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
			else if (game->map[cont1][cont2] == 'P')
				ft_press_p(game, cont1, cont2);
			ft_more_print(game, cont1, cont2);
			cont2++;
		}
		cont1++;
	}
}
