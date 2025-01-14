/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:03:46 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/14 13:56:17 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player(double x, double y, t_game *game)
{
	if (game->mapsets->map[(int)y][(int)game->player->pos_x] != '1')
		game->player->pos_y = y;
	if (game->mapsets->map[(int)game->player->pos_y][(int)x] != '1')
		game->player->pos_x = x;
}

void	rotate(t_game *game, int dir)
{
	double	tmp;
	double	rotation;

	rotation = dir * ROTATION_SPEED;
	tmp = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(rotation)
		- game->player->dir_y * sin(rotation);
	game->player->dir_y = tmp * sin(rotation) + game->player->dir_y
		* cos(rotation);
	tmp = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(rotation)
		- game->player->plane_y * sin(rotation);
	game->player->plane_y = tmp * sin(rotation) + game->player->plane_y
		* cos(rotation);
}
