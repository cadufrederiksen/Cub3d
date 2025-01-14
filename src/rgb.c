/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:29:10 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/14 16:13:41 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	format_rgb(char **rgb)
{
	int		x;
	int		i;
	char	*s;

	i = 0;
	x = 0;
	while (rgb[x])
	{
		while (rgb[x][i] == ' ')
			i++;
		s = ft_substr(rgb[x], i, ft_strlen(rgb[x]));
		free(rgb[x]);
		rgb[x] = s;
		x++;
	}
}

int	check_rgb(char **rgb)
{
	int	x;
	int	i;

	x = 0;
	format_rgb(rgb);
	while (rgb[x])
	{
		i = 0;
		while (rgb[x][i])
		{
			if (!ft_isdigit(rgb[x][i]))
				return (1);
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
	rgb2 = ft_split(game->mapsets->c_path, ',');
	if (check_rgb(rgb1) || check_rgb(rgb2))
		return (free2d(rgb2), free2d(rgb1),
			ft_printf("Error: RGB invalid!\n"), 1);
	while (x < 3)
	{
		if ((ft_atoi(rgb2[x]) < 0 || ft_atoi(rgb2[x]) > 255)
			|| (ft_atoi(rgb1[x]) < 0 || ft_atoi(rgb1[x]) > 255))
			return (ft_printf("Error: RGB out of the valid range!\n"), 
				free2d(rgb2), free2d(rgb1), 1);
		game->mapsets->floor_rgb[x] = ft_atoi(rgb1[x]);
		game->mapsets->ceiling_rgb[x] = ft_atoi(rgb2[x]);
		x++;
	}
	free2d(rgb1);
	free2d(rgb2);
	return (0);
}
