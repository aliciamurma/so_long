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
#include "../so_long.h"

int	ft_cant_w(t_game *game)
{
	if (game->map[game->player_x - 1][game->player_y] == '1'
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
	if (game->map[game->player_x][game->player_y - 1] == '1'
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
	if (game->map[game->player_x + 1][game->player_y] == '1'
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
	if (game->map[game->player_x][game->player_y + 1] == '1'
		|| game->map[game->player_x][game->player_y + 1] == 'E')
		return (0);
	else if (game->map[game->player_x][game->player_y + 1] == 'C')
	{
		game->collec--;
		return (1);
	}
	return (1);
}

/**
 * @brief Check if we can move or not
 * The player has a movement. If we try to do that movement and we can't, return 0. Else, return 1.
 * 
 * @param game 
 * @return int 
 */
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
