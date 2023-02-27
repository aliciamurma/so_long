/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upload_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:20:15 by amurcia-          #+#    #+#             */
/*   Updated: 2023/02/23 18:17:34 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../so_long.h"

/**
 * @brief Upload the other 4 images
 * 
 * @param game 
 * @param height 
 * @param width 
 */
void	ft_upload_images(t_game *game, int height, int width)
{
	game->imgs[3].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/heroe_w.xpm", &width, &height);
	game->imgs[3].data = (int *)mlx_get_data_addr(game->imgs[3].img_ptr,
			&game->imgs[3].bpp, &game->imgs[3].size_l, &game->imgs[3].endian);
	game->imgs[5].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/heroe_s.xpm", &width, &height);
	game->imgs[5].data = (int *)mlx_get_data_addr(game->imgs[5].img_ptr,
			&game->imgs[5].bpp, &game->imgs[5].size_l, &game->imgs[5].endian);
	game->imgs[6].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/heroe_a.xpm", &width, &height);
	game->imgs[6].data = (int *)mlx_get_data_addr(game->imgs[6].img_ptr,
			&game->imgs[6].bpp, &game->imgs[6].size_l, &game->imgs[6].endian);
	game->imgs[7].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/heroe_d.xpm", &width, &height);
	game->imgs[7].data = (int *)mlx_get_data_addr(game->imgs[7].img_ptr,
			&game->imgs[7].bpp, &game->imgs[7].size_l, &game->imgs[7].endian);
}

/**
 * @brief Upload the first 4 images
 * 
 * @param game 
 */
void	ft_new_game(t_game *game)
{
	int		height;
	int		width;

	game->imgs = malloc(sizeof(t_img) * (7 + 1));
	game->imgs[0].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/pared.xpm", &width, &height);
	game->imgs[0].data = (int *)mlx_get_data_addr(game->imgs[0].img_ptr,
			&game->imgs[0].bpp, &game->imgs[0].size_l, &game->imgs[0].endian);
	game->imgs[1].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/espacio.xpm", &width, &height);
	game->imgs[1].data = (int *)mlx_get_data_addr(game->imgs[1].img_ptr,
			&game->imgs[1].bpp, &game->imgs[1].size_l, &game->imgs[1].endian);
	game->imgs[2].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/coleccionable.xpm", &width, &height);
	game->imgs[2].data = (int *)mlx_get_data_addr(game->imgs[2].img_ptr,
			&game->imgs[2].bpp, &game->imgs[2].size_l, &game->imgs[2].endian);
	game->imgs[4].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"images/exit.xpm", &width, &height);
	game->imgs[4].data = (int *)mlx_get_data_addr(game->imgs[4].img_ptr,
			&game->imgs[4].bpp, &game->imgs[4].size_l, &game->imgs[4].endian);
	ft_upload_images(game, height, width);
}
