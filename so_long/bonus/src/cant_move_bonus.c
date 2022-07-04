/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cant_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:20:19 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/24 12:20:21 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../so_long_bonus.h"

int	ft_cant_w(t_game *game)
{
	if (game->map[game->player_x - 1][game->player_y] == 'M')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 100,
			66000000, "YOU CAN'T BE BETTER THAN AN INVADER");
		game->alive = 0;
		return (-1);
	}
	else if (game->map[game->player_x - 1][game->player_y] == '1'
		|| game->map[game->player_x - 1][game->player_y] == 'E')
		return (0);
	else if (game->map[game->player_x - 1][game->player_y] == 'C')
	{
		game->collec--;
		return (1);
	}
	return (1);
}

int	ft_cant_a(t_game *game)
{
	if (game->map[game->player_x][game->player_y - 1] == 'M')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 100,
			66000000, "YOU CAN'T BE BETTER THAN AN INVADER");
		game->alive = 0;
		return (-1);
	}
	else if (game->map[game->player_x][game->player_y - 1] == '1'
		|| game->map[game->player_x][game->player_y - 1] == 'E')
		return (0);
	else if (game->map[game->player_x][game->player_y - 1] == 'C')
	{
		game->collec--;
		return (1);
	}
	return (1);
}

int	ft_cant_s(t_game *game)
{
	if (game->map[game->player_x + 1][game->player_y] == 'M')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 100,
			66000000, "YOU CAN'T BE BETTER THAN AN INVADER");
		game->alive = 0;
		return (-1);
	}
	else if (game->map[game->player_x + 1][game->player_y] == '1'
		|| game->map[game->player_x + 1][game->player_y] == 'E')
		return (0);
	else if (game->map[game->player_x + 1][game->player_y] == 'C')
	{
		game->collec--;
		return (1);
	}
	return (1);
}

int	ft_cant_d(t_game *game)
{
	if (game->map[game->player_x][game->player_y + 1] == 'M')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 100, 100,
			66000000, "YOU CAN'T BE BETTER THAN AN INVADER");
		game->alive = 0;
		return (-1);
	}
	else if (game->map[game->player_x][game->player_y + 1] == '1'
		|| game->map[game->player_x][game->player_y + 1] == 'E')
		return (0);
	else if (game->map[game->player_x][game->player_y + 1] == 'C')
	{
		game->collec--;
		return (1);
	}
	return (1);
}

int	ft_cant_move(t_game *game)
{
	if (game->new_pos == 'W')
	{
		if (ft_cant_w(game) == 0)
			return (0);
	}
	else if (game->new_pos == 'A')
	{
		if (ft_cant_a(game) == 0)
			return (0);
	}
	else if (game->new_pos == 'S')
	{
		if (ft_cant_s(game) == 0)
			return (0);
	}
	else if (game->new_pos == 'D')
	{
		if (ft_cant_d(game) == 0)
			return (0);
	}
	return (1);
}
