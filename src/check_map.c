/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:40:38 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/20 19:54:14 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

/**
 * @brief Check that the number of parameters and the fd be correct
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	ft_check_parameters(int argc, char **argv)
{
	int		fd;
	size_t	len;

	len = 0;
	if (argc != 2)
	{
		printf("Error\nWrong number of arguments\n");
		exit (0);
	}
	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nCan't read the map\n");
		exit (0);
	}
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len - 4], ".ber", 4))
	{
		printf("Error\nWrong extension\n");
		exit (0);
	}
	return (0);
}

int	ft_only_caracteres(t_game *game)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	game->map = ft_split(game->map_bak, '\n');
	while (cont2 < game->height)
	{
		cont1 = 0;
		while (cont1 < game->width)
		{
			if (game->map[cont1][cont2] != '1' && game->map[cont1][cont2] != '0'
				&& game->map[cont1][cont2] != 'C'
				&& game->map[cont1][cont2] != 'E'
				&& game->map[cont1][cont2] != 'P'
				&& game->map[cont1][cont2] != '\0'
				&& game->map[cont1][cont2] != '\n')
				return (1);
			cont1++;
		}
		cont2++;
	}
	return (0);
}

int	ft_check_caracteres(t_game *game)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	while (cont1 < game->width)
	{
		cont2 = 0;
		while (cont2 < game->height)
		{
			if (game->map[cont1][cont2] == 'C')
				game->col = 1;
			if (game->map[cont1][cont2] == 'E')
				game->ext = game->ext + 1;
			if (game->map[cont1][cont2] == 'P')
				game->playr = game->playr + 1;
			cont2++;
		}
		cont1++;
	}
	if (game->col == 1 && game->ext == 1 && game->playr == 1)
		return (0);
	else
		return (1);
}
