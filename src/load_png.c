/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_png.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:29:28 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/19 17:03:10 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_img *load_png(t_game *game)
{
	t_img *img;

	img = malloc (sizeof(t_img));
	if (!img)
		return (ft_fprintf(2, "Error: Failed to load one or more textures\n"), 0);
	
}

t_textures	*load_textures()
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		return (NULL);
	textures->wall = mlx_load_png("images/wall.png");
	textures->floor = mlx_load_png("images/floor.png");
	textures->player = mlx_load_png("images/dungeon1.png");
	if (!textures->wall || !textures->floor || !textures->player)
	{
		ft_fprintf(2, "Error: Failed to load one or more textures\n");
		if (textures->wall)
			mlx_delete_texture(textures->wall);
		if (textures->floor)
			mlx_delete_texture(textures->floor);
		if (textures->player)
			mlx_delete_texture(textures->player);
		free(textures);
		return (NULL);
	}
	return (textures);
}


