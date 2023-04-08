/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:23:01 by amurcia-          #+#    #+#             */
/*   Updated: 2023/04/08 18:20:50 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"


int	main(int argc, char **argv)
{
	t_game	game;

	game.cont = 0;
	ft_errors(argc, argv, &game);
	// ft_check_parameters(argc, argv);
	// if (ft_read_map(&game, argv) == 1)
	// 	ft_error_read(&game);
	// if (ft_leaps(&game) == 1 || ft_only_caracteres(&game) == 1
	// 	|| ft_check_caracteres(&game) == 1 || ft_surrounded_x(&game) == 1
	// 	|| ft_surrounded_y(&game) == 1)
	// 	ft_error_map(&game);
	game.mlx_ptr = mlx_init();
	ft_new_game(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.height * SIZE,
			game.width * SIZE, "Alice in wonderland");
	ft_print_map(&game);
	mlx_hook(game.win_ptr, 2, 0, ft_movements, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_free_memory, &game);
	mlx_loop(game.mlx_ptr);
	ft_free_memory(&game);
	return (0);
}
