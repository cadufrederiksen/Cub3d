/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 20:02:39 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/14 14:02:05 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_validation(char *argv[1], t_game *game)
{
	int	x;

	x = ft_strlen(argv[1]) - 1;
	if (argv[1][x] == 'b' && argv[1][x - 1] == 'u' && argv[1][x - 2] == 'c'
		&& argv[1][x - 3] == '.')
	{
		if (check_input(argv[1], game))
			error_exit("", game);
	}
	else
		error_exit("Error: Map name is wrong\n", game);
	if (check_border(game->mapsets->map, game->mapsets->vert_len))
		error_exit("Error: Map is not surrounded by walls\n", game);
}

void	validate_game(t_game *game)
{
	if (!game->textures[NORTH])
		error("Error: NORTH texture is missing\n");
	if (!game->textures[SOUTH])
		error("Error: SOUTH texture is missing\n");
	if (!game->mapsets->map)
		error("Error: Map data is missing\n");
}

void	validate_frame(t_game *game)
{
	if (!game->player)
		error("Error: Player data is NULL\n");
	if (game->player->pos_x < 0 || game->player->pos_y < 0)
	{
		if (error("Error: Player position is invalid\n"))
			return ;
	}
}

int	validate_ray(t_ray *ray, t_mapsets *mapsets)
{
	if (!ray)
		return (error("Error: Ray structure is NULL\n"));
	if (ray->raydir_x == 0 && ray->raydir_y == 0)
		return (error("Error: Ray direction is invalid\n"));
	if (ray->map_x < 0 || ray->map_y < 0 || ray->map_x >= mapsets->hor_len
		|| ray->map_y >= mapsets->vert_len)
		return (error("Error: Ray map coordinates out of bounds\n"));
	if (ray->deltadist_x <= 0 || ray->deltadist_y <= 0)
		return (error("Error: Delta distances are invalid\n"));
	return (0);
}
