/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:40:28 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/29 20:53:22 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../so_long_bonus.h"

void	ft_destroy(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit (0);
}

void	ft_free_map_matrix(t_game *game)
{
	int	cont;

	if (game->map)
	{
		cont = game->width;
		free(game->map[cont]);
		while (cont > 0)
		{
			cont--;
			free(game->map[cont]);
		}
		free(game->map);
	}
}

int	ft_free_memory(t_game *game)
{
	if (game->map)
		ft_free_map_matrix(game);
	if (game->map_bak)
		free(game->map_bak);
	if (game->imgs)
		free(game->imgs);
	if (game->enemies)
		free(game->enemies);
	ft_destroy(game);
	return (0);
}
