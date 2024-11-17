/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:32:26 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/17 14:40:44 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_ray_direction(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	game->ray.raydir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.raydir_y = game->player.dir_y + game->player.plane_y * camera_x;
	game->ray.map_x = (int)game->player.pos_x;
	game->ray.map_y = (int)game->player.pos_y;
}

void	calculate_delta_dist(t_game *game)
{
	game->ray.deltadist_x = fabs(1 / game->ray.raydir_x);
	game->ray.deltadist_y = fabs(1 / game->ray.raydir_y);
}

void	calculate_perp_wall_dist(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.perp_walldist = (game->ray.map_x - game->player.pos_x + (1 - game->ray.step_x) / 2) / game->ray.raydir_x;
	else
		game->ray.perp_walldist = (game->ray.map_y - game->player.pos_y + (1 - game->ray.step_y) / 2) / game->ray.raydir_y;
}

void	calculate_draw_limits(t_game *game)
{
	game->ray.line_height = (int)(SCREEN_HEIGHT / game->ray.perp_walldist);
	game->ray.draw_start = -game->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + SCREEN_HEIGHT / 2;
	if (game->ray.draw_end >= SCREEN_HEIGHT)
		game->ray.draw_end = SCREEN_HEIGHT - 1;
}
