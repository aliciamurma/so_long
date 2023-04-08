/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:40:53 by amurcia-          #+#    #+#             */
/*   Updated: 2023/04/08 18:31:28 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

static void	ft_preprint(t_game *game, int cont1, int cont2)
{
	ft_print_nothing(game, cont1, cont2);
	ft_print_player(game, cont1, cont2);
}

/**
 * @brief Print the map
 * 
 * @param game 
 */
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
				ft_print_wall(game, cont1, cont2);
			else if (game->map[cont1][cont2] == 'E')
				ft_print_exit(game, cont1, cont2);
			else if (game->map[cont1][cont2] == 'P')
				ft_preprint(game, cont1, cont2);
			else if (game->map[cont1][cont2] == 'C')
				ft_print_collect(game, cont1, cont2);
			else if (game->map[cont1][cont2] == '0')
				ft_print_nothing(game, cont1, cont2);
			cont2++;
		}
		cont1++;
	}
}
