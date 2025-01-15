/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:29:28 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/15 12:52:15 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static mlx_texture_t	*load_png(char *file)
{
	int		fd;
	size_t	filename_len;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	filename_len = ft_strlen(file);
	if (filename_len > 4 && file[filename_len - 4] == '.'
		&& file[filename_len - 3] == 'p'
		&& file[filename_len - 2] == 'n'
		&& file[filename_len - 1] == 'g')
		return (mlx_load_png(file));
	return (0);
}
 */
void	textures_loading(t_game *game)
{
	game->textures[NORTH] = mlx_load_png(game->mapsets->no_path);
	if (!game->textures[NORTH])
		return (error_exit(ERROR_LOADING, game));
	game->textures[SOUTH] = mlx_load_png(game->mapsets->so_path);
	if (!game->textures[SOUTH])
		return (error_exit(ERROR_LOADING, game));
	game->textures[EAST] = mlx_load_png(game->mapsets->ea_path);
	if (!game->textures[EAST])
		return (error_exit(ERROR_LOADING, game));
	game->textures[WEST] = mlx_load_png(game->mapsets->we_path);
	if (!game->textures[WEST])
		return (error_exit(ERROR_LOADING, game));
}

void	img_loading(t_game *game)
{
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
		return (error_exit(ERROR_LOADING, game));
	game->frame = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->frame)
		return (error_exit(ERROR_LOADING, game));
	mlx_image_to_window(game->mlx, game->frame, 0, 0);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
