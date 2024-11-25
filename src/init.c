/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:43:12 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/25 20:10:10 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_player *player)
{
	player->pos_x = 0.0;
	player->pos_y = 0.0;
	player->dir_x = 0.0;
	player->dir_y = 0.0;
	player->plane_x = 0.0;
	player->plane_y = 0.0;
}

void	init_mapsets(t_mapsets *mapsets)
{
	mapsets->spawn = 0;
	mapsets->p_x = 0;
	mapsets->p_y = 0;
	mapsets->no_path = NULL;
	mapsets->so_path = NULL;
	mapsets->we_path = NULL;
	mapsets->ea_path = NULL;
	mapsets->f_path = NULL;
	mapsets->c_path = NULL;
	mapsets->map = NULL;
	mapsets->ceiling_rgb[0] = 0;
	mapsets->floor_rgb[0] = 0;
	mapsets->vert_len = 0;
	mapsets->hor_len = 0;
	mapsets->vars_flag = 0;
}

void	init_ray(t_ray *ray)
{
	ray->raydir_x = 0.0;
	ray->raydir_y = 0.0;
	ray->deltadist_x = 0.0;
	ray->deltadist_y = 0.0;
	ray->sidedist_x = 0.0;
	ray->sidedist_y = 0.0;
	ray->perp_walldist = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->side = 0;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
}

void	init_texture(t_texture_data *texture)
{
	texture->tex_x = 0;
	texture->tex_y = 0;
	texture->step = 0.0;
	texture->tex_pos = 0.0;
}

int	init_game(t_game *game)
{
	game->mlx = NULL;
	game->img = NULL;
	game->frame = NULL;
	game->mapsets = calloc(1, sizeof(t_mapsets));
	if (!game->mapsets)
		return (1);
	init_mapsets(game->mapsets);
	game->player = calloc(1, sizeof(t_player));
	if (!game->player)
		return (1);
	init_player(game->player);
	game->ray = calloc(1, sizeof(t_ray));
	if (!game->ray)
		return (1);
	init_ray(game->ray);
	game->texture = calloc(1, sizeof(t_texture_data));
	if (!game->texture)
		return (1);
	init_texture(game->texture);
	game->textures[0] = NULL;
	return (0);
}

void	set_player_direction(t_player *player, char spawn)
{
	if (spawn == 'N')
	{
		player->dir_x = 0.0;
		player->dir_y = -1.0;
		player->plane_x = 0.66; //PI
		player->plane_y = 0.0;
	}
	else if (spawn == 'S')
	{
		player->dir_x = 0.0;
		player->dir_y = 1.0;
		player->plane_x = -0.66;
		player->plane_y = 0.0;
	}
	else if (spawn == 'E')
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

void	init_player_from_map(t_game *game)
{
	if (game->mapsets->spawn == 0)
		error_exit("Error: Player spawn not found\n");
	game->player->pos_x = (double)game->mapsets->p_x + 0.5; // + 0.5 para centrar en la celda
	game->player->pos_y = (double)game->mapsets->p_y + 0.5; // + 0.5 para centrar en la celda
	set_player_direction(game->player, game->mapsets->spawn);
	game->mapsets->map[game->mapsets->p_y][game->mapsets->p_x] = '0';
}
