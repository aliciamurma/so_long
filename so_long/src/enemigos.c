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

#include "../so_long.h"

int	ft_move_enemy(t_game *game)
{
	if (game->map[game->player_x][game->player_y + 1] == '1' || game->map[game->player_x][game->player_y + 1] == 'C' || game->map[game->player_x][game->player_y + 1] == 'E')
		return (0);
	else
	{
		game->map[game->enemy_x][game->enemy_y] = '0';
		game->player_y = game->enemy_y + 1;
		game->map[game->player_x][game->player_y] = 'M';
	}
	if (game->map[game->player_x - 1][game->player_y] == '1' || game->map[game->player_x - 1][game->player_y] == 'C' || game->map[game->player_x - 1][game->player_y] == 'E')
		return (0);
	else
	{
		game->map[game->enemy_x][game->enemy_y] = '0';
		game->player_x = game->enemy_x + 1;
		game->map[game->player_x][game->player_y] = 'M';
	}
	if (game->map[game->player_x][game->player_y - 1] == '1' || game->map[game->player_x][game->player_y - 1] == 'C' || game->map[game->player_x][game->player_y - 1] == 'E')
		return (0);
	else
	{
		game->map[game->enemy_x][game->enemy_y] = '0';
		game->player_y = game->enemy_y - 1;
		game->map[game->player_x][game->player_y] = 'M';
	}
	return (1);
}

