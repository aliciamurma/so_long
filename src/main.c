/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:23:01 by amurcia-          #+#    #+#             */
/*   Updated: 2023/04/08 18:29:39 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

int	main(int argc, char **argv)
{
	t_game	game;

	game.cont = 0;
	ft_errors(argc, argv, &game);
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
