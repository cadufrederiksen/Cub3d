/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:34:11 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/07 18:59:20 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/* 
Calcula los pasos step_x y step_y en función de la dirección del rayo, 
y configura las distancias iniciales (sidedist_x y sidedist_y) 
utilizando las coordenadas del jugador y la distancia delta.
 */
void	initialize_step_and_side_dist(t_game *game)
{
	if (game->ray->raydir_x < 0)
	{
		game->ray->step_x = -1;
		game->ray->sidedist_x = (game->player->pos_x - game->ray->map_x) * game->ray->deltadist_x;
	}
	else
	{
		game->ray->step_x = 1;
		game->ray->sidedist_x = (game->ray->map_x + 1.0 - game->player->pos_x) * game->ray->deltadist_x;
	}
	if (game->ray->raydir_y < 0)
	{
		game->ray->step_y = -1;
		game->ray->sidedist_y = (game->player->pos_y - game->ray->map_y) * game->ray->deltadist_y;
	}
	else
	{
		game->ray->step_y = 1;
		game->ray->sidedist_y = (game->ray->map_y + 1.0 - game->player->pos_y) * game->ray->deltadist_y;
	}
}
/* 
Implementa algoritmo de DDA (Digital Differential Analysis) 
para avanzar a través de las celdas del mapa.
Usa side para distinguir si el rayo golpeó en un eje X o Y.
 */
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

// Launch a ray to calculate an intersection with the walls
void	cast_ray(t_game *game, int x)
{
	calculate_ray_direction(game, x);
	calculate_delta_dist(game);
	initialize_step_and_side_dist(game);
	perform_dda(game);
	calculate_perp_wall_dist(game);
	calculate_draw_limits(game);
	draw_ceiling(game, x); // Dibuja el techo antes de `draw_start`
    draw_column(game, x); // Renderizar columna de la textura de pared
	draw_floor(game, x); // Dibuja el suelo después de `draw_end`
}

// Renderiing the full frame
// Llama a cast_ray para cada columna de píxeles y actualiza la ventana con la imagen renderizada.
void	draw_frame(t_game *game)
{
	int	x;

	precalculate_colours(game); // Calcula los colores una vez por frame
	clear_image(game->img); // Clean the image before drawing
	// Launch a ray for each column of pixels
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cast_ray(game, x);
		x++;
	}
	// Update the window with the rendered image
	mlx_image_to_window(game->mlx, game->img, 0, 0);
}
