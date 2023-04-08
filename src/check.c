/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:09:04 by amurcia-          #+#    #+#             */
/*   Updated: 2023/04/08 18:29:29 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_error_read(t_game *game)
{
	free(game->map_bak);
	printf("Error\nImposible de leer\n");
	exit (0);
}

void	ft_error_map(t_game *game)
{
	ft_free_map_matrix(game);
	printf("Error\nMapa incorrecto\n");
	exit (0);
}

void	ft_errors(int argc, char **argv, t_game *game)
{
	ft_check_parameters(argc, argv);
	if (ft_read_map(game, argv) == 1)
		ft_error_read(game);
	if (ft_leaps(game) == 1 || ft_only_caracteres(game) == 1
		|| ft_check_caracteres(game) == 1 || ft_surrounded_x(game) == 1
		|| ft_surrounded_y(game) == 1)
		ft_error_map(game);
}
