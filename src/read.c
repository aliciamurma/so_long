/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:42:01 by amurcia-          #+#    #+#             */
/*   Updated: 2023/02/23 18:17:53 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../mlx/mlx.h"

/**
 * @brief Read the map
 * 
 * @param game 
 * @param fd 
 * @param i 
 * @return int 
 */
int	ft_continue_reading(t_game *game, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		exit(-1);
	game->map_bak = NULL;
	game->height = ft_strlen(line) - 1;
	while (line)
	{
		game->width = ft_strlen(line) - 1;
		game->map_bak = ft_strjoin(game->map_bak, line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	free (line);
	game->width = i - 1;
	return (fd);
}

/**
 * @brief Open and close the map
 * 
 * @param game 
 * @param argv 
 * @return int 
 */
int	ft_read_map(t_game *game, char **argv)
{
	int		fd;
	size_t	i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nNo se puede abrir\n");
		exit(1);
	}
	fd = ft_continue_reading(game, fd, i);
	close(fd);
	return (0);
}
