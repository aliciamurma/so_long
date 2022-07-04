/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemigos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:53:12 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/22 11:53:24 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include "../mlx/mlx.h"

int	ft_kill_plus(t_game *game)
{
	mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 100,
		66000000, "YOU CAN'T BE BETTER THAN AN INVADER");
	return (0);
}

int	ft_move_left(t_game *game, int cont_e)
{
	if (game->map[game->enemies[cont_e].enemy_x]
		[game->enemies[cont_e].enemy_y + 1] == '0')
	{
		game->map[game->enemies[cont_e].enemy_x]
		[game->enemies[cont_e].enemy_y] = '0';
		game->enemies[cont_e].enemy_y = game->enemies[cont_e].enemy_y + 1;
		game->map[game->enemies[cont_e].enemy_x]
		[game->enemies[cont_e].enemy_y] = 'M';
	}
	else
		game->enemies[cont_e].direction = 1;
	return (cont_e);
}

int	ft_move_right(t_game *game, int cont_e)
{
	if (game->map[game->enemies[cont_e].enemy_x]
		[game->enemies[cont_e].enemy_y - 1] == '0')
	{
		game->map[game->enemies[cont_e].enemy_x]
		[game->enemies[cont_e].enemy_y] = '0';
		game->enemies[cont_e].enemy_y = game->enemies[cont_e].enemy_y - 1;
		game->map[game->enemies[cont_e].enemy_x]
		[game->enemies[cont_e].enemy_y] = 'M';
	}
	else
		game->enemies[cont_e].direction = 3;
	return (cont_e);
}

int	ft_move_right_and_left(t_game *game, int cont_e)
{
	while (cont_e < game->game_num_enemies)
	{
		if (game->enemies[cont_e].direction == 1)
		{
			if (game->map[game->enemies[cont_e].enemy_x]
				[game->enemies[cont_e].enemy_y - 1] == 'P')
			{
				game->alive = 0;
				return (-1);
			}
			ft_move_right(game, cont_e);
		}
		else if (game->enemies[cont_e].direction == 3)
		{
			if (game->map[game->enemies[cont_e].enemy_x]
				[game->enemies[cont_e].enemy_y + 1] == 'P')
			{
				game->alive = 0;
				return (-1);
			}
			ft_move_left(game, cont_e);
		}
		cont_e++;
	}
	return (cont_e);
}

int	ft_move_enemy(t_game *game)
{
	int	cont_e;

	if (!game->alive)
	{
		return (0);
	}
	cont_e = 0;
	if (game->temp_move % 10 == 0)
	{
		if (ft_move_right_and_left(game, cont_e) == -1)
		{
			ft_kill_plus(game);
			return (0);
		}
	}
	ft_print_map(game);
	game->temp_move++;
	return (1);
}
