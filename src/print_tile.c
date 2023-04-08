/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:57:13 by amurcia-          #+#    #+#             */
/*   Updated: 2023/02/27 13:03:40 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

/**
 * @brief Print the player
 * 
 * @param game 
 * @param cont1 
 * @param cont2 
 * @return int 
 */
int	ft_print_player(t_game *game, int cont1, int cont2)
{
	game->player_x = cont1;
	game->player_y = cont2;
	if (game->pos_player == 'W')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[3].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	else if (game->pos_player == 'S')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[5].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	else if (game->pos_player == 'A')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[6].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->imgs[7].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	}
	return (1);
}

/**
 * @brief Print the 0
 * 
 * @param game 
 * @param cont1 
 * @param cont2 
 */
void	ft_print_nothing(t_game *game, int cont1, int cont2)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[1].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
}

/**
 * @brief Print the collectionable
 * 
 * @param game 
 * @param cont1 
 * @param cont2 
 */
void	ft_print_collect(t_game *game, int cont1, int cont2)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[2].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
	game->collec++;
}

/**
 * @brief Print the wall
 * 
 * @param game 
 * @param cont1 
 * @param cont2 
 */
void	ft_print_wall(t_game *game, int cont1, int cont2)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[0].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
}

/**
 * @brief Print the exit
 * 
 * @param game 
 * @param cont1 
 * @param cont2 
 */
void	ft_print_exit(t_game *game, int cont1, int cont2)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->imgs[4].img_ptr, (cont2 * SIZE), (cont1 * SIZE));
}
