/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:04:16 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/14 13:54:57 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mapsets(t_mapsets *maps)
{
	if (maps->no_path)
		free(maps->no_path);
	if (maps->so_path)
		free(maps->so_path);
	if (maps->we_path)
		free(maps->we_path);
	if (maps->ea_path)
		free(maps->ea_path);
	if (maps->c_path)
		free(maps->c_path);
	if (maps->f_path)
		free(maps->f_path);
}

void	free2d(char **str)
{
	int	x;

	x = 0;
	while (str[x])
		x++;
	while (x >= 0)
		free(str[x--]);
	free(str);
}

void	free_images(t_game *game)
{
	int	x;

	x = 3;
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->frame)
		mlx_delete_image(game->mlx, game->frame);
	if (game->textures[3])
		while (x >= 0)
			mlx_delete_texture(game->textures[x--]);
}

void	free_game(t_game *game)
{
	if (game->mapsets && game->mapsets->map)
		free2d(game->mapsets->map);
	if (game->mapsets)
	{
		free_mapsets(game->mapsets);
		free(game->mapsets);
	}
	if (game->player)
		free(game->player);
	if (game->ray)
		free(game->ray);
	if (game->texture)
		free(game->texture);
	free_images(game);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}
