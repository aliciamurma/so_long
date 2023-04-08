/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:23:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/29 20:53:34 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../so_long_bonus.h"

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

void	ft_start(int argc, char **argv, t_game *game)
{
	ft_check_parameters(argc, argv);
	if (ft_read_map(game, argv) == 1)
		ft_error_read(game);
	if (ft_leaps(game) == 1 || ft_only_caracteres(game) == 1
		|| ft_check_caracteres(game) == 1
		|| ft_surrounded_x(game) == 1 || ft_surrounded_y(game) == 1)
		ft_error_map(game);
	game->mlx_ptr = mlx_init();
	ft_new_game(game);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->height * SIZE,
			game->width * SIZE, "Alice in wonderland");
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		count;

	count = 0;
	game.game_num_enemies = 3;
	game.alive = 1;
	game.cont = 0;
	ft_start(argc, argv, &game);
	game.enemies = malloc(sizeof(t_enemy) * (game.game_num_enemies));
	if (!game.enemies)
		return (0);
	while (count < game.game_num_enemies)
	{
		game.enemies[count].direction = 1;
		count++;
	}
	ft_print_map(&game);
	mlx_loop_hook(game.mlx_ptr, &ft_move_enemy, &game);
	mlx_hook(game.win_ptr, 2, 0, ft_movements, &game);
	mlx_hook(game.win_ptr, 17, 0, ft_free_memory, &game);
	mlx_loop(game.mlx_ptr);
	ft_free_memory(&game);
	return (0);
}
