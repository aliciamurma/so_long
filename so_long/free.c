/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:40:28 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/20 12:40:30 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map_matrix(t_game *game)
{
	if (game->map)
	{
		int	cont;
	
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

//CUANDO MI PROGRAMA HA TERMINADO BIEN
void	ft_free_memory(t_game *game)
{
	if (game->map)
		ft_free_map_matrix(game);
	if (game->map_bak)
		free(game->map_bak);
}

int	ft_exit(t_game *game)
{
	game->player = 0;
	exit (0);
	return (0);
}