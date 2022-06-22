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

//validamos que el numero de parametros y el fd sea correcto
int	ft_check_parameters(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		printf("Error argumentos\n");
		exit (0);
	}
	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
	{
		printf("Error mapa\n");
		exit (0);
	}
	return (0);
}

int	ft_no_saltos(t_game *game)
{
	int	cont;

	cont = 0;
	while (game->map_bak[cont] != '\0')
	{
		if (game->map_bak[cont] == '\n' && game->map_bak[cont + 1] == '\0')
			return (1);
		if (game->map_bak[cont] == '\n' && game->map_bak[cont + 1] == '\n')
			return (1);
		cont++;
	}
	return (0);
}

//SI NOS ENCONTRAMOS CON ALGO QUE NO SEA C, E, P, 0 O 1, ERROR
int	ft_solo_caracteres(t_game *game)
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
				&& game->map[cont1][cont2] != 'C' && game->map[cont1][cont2] != 'E'
				&& game->map[cont1][cont2] != 'P' && game->map[cont1][cont2] != '\0'
				&& game->map[cont1][cont2] != '\n' && game->map[cont1][cont2] != 'M')
				return (1);
			cont1++;
		}
		cont2++;
	}
	return (0);
}

//VALIDAMOS QUE SIEMPRE HAYA UNA C, E, P
int	ft_check_caracteres(t_game *game)
{
	int	col;
	int	ext;
	int	player;
	int	cont1;
	int	cont2;

	col = 0;
	ext = 0;
	player = 0;
	cont1 = 0;
	cont2 = 0;
	while (cont1 < game->width)
	{
		cont2 = 0;
		while (cont2 < game->height)
		{
			if (game->map[cont1][cont2] == 'C')
				col = 1;
			if (game->map[cont1][cont2] == 'E')
				ext = 1;
			if (game->map[cont1][cont2] == 'P')
				player = 1;
			cont2++;
		}
		cont1++;
	}
	if (col == 1 && ext == 1 && player == 1)
		return (0);
	else
		return (1);
}

//VALIDAMOS QUE EL MAPA ESTE RODEADO DE UNOS POR ARRIBA Y POR ABAJO
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

//VALIDAMOS QUE EL MAPA ESTE RODEADO DE UNOS POR LOS LADOS
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
