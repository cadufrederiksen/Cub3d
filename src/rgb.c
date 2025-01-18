/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:10 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/18 18:08:23 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_rgb(char **rgb, t_game *game)
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
		return (1);
	return (0);
}

int	get_rgb(t_game *game)
{
	char	**rgb1;
	char	**rgb2;
	int		x;

	x = 0;
	rgb1 = ft_split(game->mapsets->f_path, ',');
	check_rgb(rgb1, game);
	rgb2 = ft_split(game->mapsets->c_path, ',');
	check_rgb(rgb2, game);
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
