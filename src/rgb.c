/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:10 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/18 18:19:36 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_rgb(char **rgb, char **rgb2, t_game *game)
{
	int	x;
	int	i;

	x = 0;
	while (rgb[x])
	{
		i = 0;
		while (rgb[x][i])
		{
			if (!ft_isdigit(rgb[x][i]))
			{
				free2d(rgb);
				error_exit("Error: RGB invalid!\n", game);
			}
			i++;
		}
		x++;
	}
	if (x != 3)
	{
		free2d(rgb);
		error_exit("Error: RGB invalid!\n", game);
	}
}

int	get_rgb(t_game *game)
{
	char	**rgb1;
	char	**rgb2;
	int		x;

	x = 0;
	rgb1 = ft_split(game->mapsets->f_path, ',');
	check_rgb(rgb1, rgb2, game);
	rgb2 = ft_split(game->mapsets->c_path, ',');
	check_rgb(rgb2, rgb1, game);
	while (x < 3)
	{
		if ((ft_atoi(rgb2[x]) < 0 || ft_atoi(rgb2[x]) > 255)
			|| (ft_atoi(rgb1[x]) < 0 || ft_atoi(rgb1[x]) > 255))
		{
			free2d(rgb2);
			free2d(rgb1);
			error_exit("Error: RGB out of the valid range!\n", game);
		}
		game->mapsets->floor_rgb[x] = ft_atoi(rgb1[x]);
		game->mapsets->ceiling_rgb[x] = ft_atoi(rgb2[x]);
		x++;
	}
	free2d(rgb1);
	free2d(rgb2);
	return (0);
}
