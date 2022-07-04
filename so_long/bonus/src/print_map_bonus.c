/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 21:28:14 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/28 21:28:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"
#include "../mlx/mlx.h"

int	ft_print_invaders(t_game *game, int cont1, int cont2, int conte)
{
	if (game->map[cont1][cont2] == 'M' && game->movement == 0)
	{
		game->enemies[conte].enemy_x = cont1;
		game->enemies[conte].enemy_y = cont2;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[1].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[5].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
		conte++;
	}
	else if (game->map[cont1][cont2] == 'M' && game->movement == 1)
	{
		game->enemies[conte].enemy_x = cont1;
		game->enemies[conte].enemy_y = cont2;
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[1].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[6].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
		conte++;
	}
	return (conte);
}

void	ft_print_others(t_game *game, int cont1, int cont2)
{
	if (game->map[cont1][cont2] == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[0].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	else if (game->map[cont1][cont2] == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[1].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	else if (game->map[cont1][cont2] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[2].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
		game->collec++;
	}
	else if (game->map[cont1][cont2] == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[4].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	else if (game->map[cont1][cont2] == 'P')
		ft_press_p(game, cont1, cont2);
}

void	ft_print_all(t_game *game)
{
	int		cont1;
	int		cont2;
	int		conte;

	cont1 = 0;
	cont2 = 0;
	conte = 0;
	while (game->map[cont1])
	{
		cont2 = 0;
		while (game->map[cont1][cont2])
		{
			ft_print_others(game, cont1, cont2);
			conte = ft_print_invaders(game, cont1, cont2, conte);
			cont2++;
		}
		cont1++;
	}
}

int	ft_print_map(t_game *game)
{
	char	*str;

	game->collec = 0;
	str = ft_itoa(game->cont);
	ft_print_all(game);
	if (game->collec == 0 && (game->map[game->player_x]
			[game->player_y + 1] == 'E'
			|| game->map[game->player_x][game->player_y - 1] == 'E'
		|| game->map[game->player_x + 1][game->player_y] == 'E'
		|| game->map[game->player_x - 1][game->player_y] == 'E'))
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15,
			15, 66000000, "CONGRATULATIONS");
		return (0);
	}
	mlx_string_put(game->mlx_ptr, game->win_ptr, 15, 10, 66000000, str);
	free(str);
	return (1);
}
