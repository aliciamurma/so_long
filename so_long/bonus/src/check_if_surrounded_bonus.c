/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_surrounded.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:49:34 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/28 20:50:42 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_rodeado_x(t_game *game)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	while (cont1 < game->height)
	{
		if (game->map[0][cont1] != '1')
			return (1);
		cont1++;
	}
	if (cont1 != game->height)
		return (1);
	cont2 = 0;
	while (cont2 < game->height)
	{
		if (game->map[game->width - 1][cont2] != '1')
			return (1);
		cont2++;
	}
	if (cont2 != game->height)
		return (1);
	return (0);
}

int	ft_rodeado_y(t_game *game)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	while (cont1 < game->width)
	{
		if (game->map[cont1][0] != '1')
			return (1);
		cont1++;
	}
	if (cont1 != game->width)
		return (1);
	cont2 = 0;
	while (cont2 < game->width)
	{
		if (game->map[cont2][game->height - 1] != '1')
			return (1);
		cont2++;
	}
	if (cont2 != game->width)
		return (1);
	return (0);
}
