/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:42:42 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/03 15:41:49 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_game *game)
{
	double x;
	double y;
	
	x = game->player->pos_x + game->player->dir_x * MOV_SPEED;
	y = game->player->pos_y + game->player->dir_y * MOV_SPEED;
	move_player(x, y, game);
}

void	move_down(t_game *game)
{
	double x;
	double y;
	
	x = game->player->pos_x - game->player->dir_x * MOV_SPEED;
	y = game->player->pos_y - game->player->dir_y * MOV_SPEED;
	move_player(x, y, game);
	
}

void	move_left(t_game *game)	
{
	double x;
	double y;
	
	x = game->player->pos_x + game->player->dir_y * MOV_SPEED;
	y = game->player->pos_y - game->player->dir_x * MOV_SPEED;
	move_player(x, y, game);
}

void	move_right(t_game *game)
{
	double x;
	double y;
	
	x = game->player->pos_x - game->player->dir_y * MOV_SPEED;
	y = game->player->pos_y + game->player->dir_x * MOV_SPEED;
	move_player(x, y, game);
}

void	moves(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	
	game = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		move_up(game);
	else if (keydata.key == MLX_KEY_S && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		move_down(game);
	else if (keydata.key == MLX_KEY_A && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		move_left(game);
	else if (keydata.key == MLX_KEY_D && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
 		move_right(game);
 	else if (keydata.key == MLX_KEY_LEFT && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		rotate(game, -1);
	else if (keydata.key == MLX_KEY_RIGHT && (keydata.action == MLX_PRESS || \
		keydata.action == MLX_REPEAT))
		rotate(game, 1);
}
