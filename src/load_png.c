/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:29:28 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/25 21:21:55 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// como previamente en las funciones de check_input, get_map, etc.. 
// se han implementado checkings, abierto el archivo y guardado datos en la estructura,
// no se muy bien como hacer esta, no se donde se ha guardado el archivo para poder 
// checkear el .png y cargarlo con mlx_load_png
// esta funcion es copiada del repo que te pase solo para indicar aqui que esta pendiente de implementarse
// no se como hacerlo, seguramente tu sepas como hacerlo mejor que yo

/*static mlx_texture_t	*load_png(char *file)
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
}*/

void	textures_loading(t_game *game)
{
	game->textures[NORTH] = load_png(game->mapsets->no_path); //load_png no esta implementada aun
	if (!game->textures[NORTH])
		return (free_game(game), error_exit(ERROR_LOADING));
	game->textures[SOUTH] = load_png(game->mapsets->so_path);
	if (!game->textures[SOUTH])
		return (free_game(game), error_exit(ERROR_LOADING));
	game->textures[EAST] = load_png(game->mapsets->ea_path);
	if (!game->textures[EAST])
		return (free_game(game), error_exit(ERROR_LOADING));
	game->textures[WEST] = load_png(game->mapsets->we_path);
	if (!game->textures[WEST])
		return (free_game(game), error_exit(ERROR_LOADING));
}

void	img_loading(t_game *game)
{
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
		return (free_game(game), error_exit(ERROR_LOADING));
	game->frame = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->frame)
		return (free_game(game), error_exit(ERROR_LOADING));
	mlx_image_to_window(game->mlx, game->frame, 0, 0);
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
