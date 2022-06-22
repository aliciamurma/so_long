/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:23:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/06/11 18:48:01 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "mlx/mlx.h"
#include "so_long.h"

//si inicializo la var en el mismo sitio, ponemos var.id. Si la enviamos, enviamos con un & y no es punto, es flecha

int	main(int argc, char **argv)
{
	t_game	game;

	game.cont = 0;
	ft_check_parameters(argc, argv);
	if (ft_read_map(&game, argv) == 1)
	{
		free(game.map_bak);
		printf("Error de lectura\n");
		exit (0);
	}
	if (ft_no_saltos(&game) == 1 || ft_solo_caracteres(&game) == 1 || ft_check_caracteres(&game) == 1
		|| ft_rodeado_x(&game) == 1 || ft_rodeado_y(&game) == 1)
	{
		ft_free_map_matrix(&game);
		printf("Error en el mapa\n");
		exit (0);
	}
	game.mlx_ptr = mlx_init();
	ft_new_game(&game);
	// //MIRAMOS NUESTRO MAPA
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.height * SIZE, game.width * SIZE, "Alice in wonderland");
	ft_print_map(&game);
	mlx_hook(game.win_ptr, 2, 0, ft_movements, &game);
	//2 para input, 17 para siempre
	mlx_hook(game.win_ptr, 17, 0, ft_exit, &game);
	//hacemos un loop para que no se salga del juego
	mlx_loop(game.mlx_ptr);
	ft_free_memory(&game);
	return (0);
}