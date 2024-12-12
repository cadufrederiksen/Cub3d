/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:30:08 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/07 17:56:26 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_north_south(t_player *player, char spawn)
{
	if (spawn == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66;
		player->plane_y = 0.0;
	}
	else if (spawn == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
}

static void	set_east_west(t_player *player, char spawn)
{
	if (spawn == 'E')
	{
		player->dir_x = 1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = 0.66;
	}
	else if (spawn == 'W')
	{
		player->dir_x = -1.0;
		player->dir_y = 0.0;
		player->plane_x = 0.0;
		player->plane_y = -0.66;
	}
}

void	set_player_direction(t_player *player, char spawn)
{
	if (spawn == 'N' || spawn == 'S')
		set_north_south(player, spawn);
	else if (spawn == 'E' || spawn == 'W')
		set_east_west(player, spawn);
}

void	init_player_from_map(t_game *game)
{
	if (game->mapsets->spawn == 0)
		error_exit("Error: Player spawn not found\n", game);
	game->player->pos_x = (double)game->mapsets->p_x + 0.5; // + 0.5 para centrar en la celda
	game->player->pos_y = (double)game->mapsets->p_y + 0.5; // + 0.5 para centrar en la celda
	set_player_direction(game->player, game->mapsets->spawn);
	//game->mapsets->map[game->mapsets->p_y][game->mapsets->p_x] = '0';
}
