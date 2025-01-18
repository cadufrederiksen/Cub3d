/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:04:16 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/18 18:03:04 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mapsets(t_mapsets *maps)
{
	if (maps->line)
		free(maps->line);
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

	if (!str)
		return ;
	x = 0;
	while (str[x])
		x++;
	x = x -1;
	while (x >= 0)
		free(str[x--]);
	free(str);
}

void	free_images(t_game *game)
{
	int	x;

	if (!game)
		return ;
	x = 3;
	if (game->img)
		mlx_delete_image(game->mlx, game->img);
	if (game->frame)
		mlx_delete_image(game->mlx, game->frame);
	while (x >= 0)
	{
		if (game->textures[x])
			mlx_delete_texture(game->textures[x]);
		x--;
	}
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
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
	free_images(game);
	if (game->texture)
		free(game->texture);
	if (game->mlx)
		mlx_terminate(game->mlx);
	free(game);
}
