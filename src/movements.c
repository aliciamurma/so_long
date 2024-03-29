/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:59:52 by amurcia-          #+#    #+#             */
/*   Updated: 2023/02/27 13:08:56 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../so_long.h"

static char	ft_get_direction(int keycode)
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
		return (-1);
	return ('0');
}

static void	ft_move_w_a(t_game *game)
{
	if (game->new_pos == 'W')
	{
		game->cont = game->cont + 1;
		printf("Num de movimientos: %d \n", game->cont);
			game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x - 1;
		game->map[game->player_x][game->player_y] = 'P';
		game->pos_player = 'W';
	}
	else if (game->new_pos == 'A')
	{
		game->cont = game->cont + 1;
		printf("Num de movimientos: %d \n", game->cont);
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y - 1;
		game->map[game->player_x][game->player_y] = 'P';
		game->pos_player = 'A';
	}
}

static void	ft_move_s_d(t_game *game)
{
	if (game->new_pos == 'S')
	{
		game->cont = game->cont + 1;
		printf("Num de movimientos: %d \n", game->cont);
		game->map[game->player_x][game->player_y] = '0';
		game->player_x = game->player_x + 1;
		game->map[game->player_x][game->player_y] = 'P';
		game->pos_player = 'S';
	}
	else if (game->new_pos == 'D')
	{
		game->cont = game->cont + 1;
		printf("Num de movimientos: %d \n", game->cont);
		game->map[game->player_x][game->player_y] = '0';
		game->player_y = game->player_y + 1;
		game->map[game->player_x][game->player_y] = 'P';
		game->pos_player = 'D';
	}
}

static int	ft_can_exit(t_game *game)
{
	if (game->collec == 0 && (game->map[game->player_x]
			[game->player_y + 1] == 'E'
			|| game->map[game->player_x][game->player_y - 1] == 'E'
		|| game->map[game->player_x + 1][game->player_y] == 'E'
		|| game->map[game->player_x - 1][game->player_y] == 'E'))
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
			15, 66000000, "CONGRATULATIONS");
		return (1);
	}
	return (0);
}

int	ft_movements(int keycode, t_game *game)
{
	game->new_pos = ft_get_direction(keycode);
	if (game->new_pos == -1)
		ft_free_memory(game);
	if (ft_can_exit(game) == 1)
		return (0);
	if (ft_cant_move(game) == 0)
		return (0);
	ft_move_w_a(game);
	ft_move_s_d(game);
	ft_print_map(game);
	return (0);
}
