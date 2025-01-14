/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:34:11 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/14 13:47:59 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_step_and_side_dist(t_game *game)
{
	if (game->ray->raydir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->sidedist_x = (game->player->pos_x - game->ray->map_x)
			* game->ray->deltadist_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->sidedist_x = (game->ray->map_x + 1.0 - game->player->pos_x)
			* game->ray->deltadist_x;
	}
	if (game->ray->raydir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->sidedist_y = (game->player->pos_y - game->ray->map_y)
			* game->ray->deltadist_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->sidedist_y = (game->ray->map_y + 1.0 - game->player->pos_y)
			* game->ray->deltadist_y;
	}
}

void	perform_dda(t_game *game)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (game->ray->sidedist_x < game->ray->sidedist_y)
		{
			game->ray->sidedist_x += game->ray->deltadist_x;
			game->ray->map_x += game->ray->step_x;
			game->ray->side = 0;
		}
		else
		{
			game->ray->sidedist_y += game->ray->deltadist_y;
			game->ray->map_y += game->ray->step_y;
			game->ray->side = 1;
		}
		if (game->mapsets->map[game->ray->map_y][game->ray->map_x] == '1')
			hit = 1;
	}
}

void	cast_ray(t_game *game, int x)
{
	calculate_ray_direction(game, x);
	calculate_delta_dist(game);
	initialize_step_and_side_dist(game);
	perform_dda(game);
	calculate_perp_wall_dist(game);
	calculate_draw_limits(game);
	draw_ceiling(game, x);
	draw_column(game, x);
	draw_floor(game, x);
}

void	draw_frame(t_game *game)
{
	int	x;

	precalculate_colours(game);
	clear_image(game->img);
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cast_ray(game, x);
		x++;
	}
	if (!mlx_image_to_window(game->mlx, game->img, 0, 0))
		return (error_exit(ERROR_LOADING, game));
}
