/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:35:19 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/12 15:21:47 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t	*select_texture(t_game *game)
{
	if (game->ray->side == 1)
	{
		if (game->ray->raydir_y > 0)
			return (game->textures[SOUTH]);
		else
			return (game->textures[NORTH]);
	}
	else
	{
		if (game->ray->raydir_x > 0)
			return (game->textures[EAST]);
		else
			return (game->textures[WEST]);
	}
}

double	calculate_wall_x(t_game *game)
{
	double	wall_x;

	if (game->ray->side == 0)
		wall_x = game->player->pos_y + game->ray->perp_walldist
			* game->ray->raydir_y;
	else
		wall_x = game->player->pos_x + game->ray->perp_walldist
			* game->ray->raydir_x;
	return (wall_x - my_floor(wall_x)); // mantener solo la parte decimal
}

int	calculate_tex_x(t_game *game, mlx_texture_t *texture, double wall_x)
{
	int	tex_x;

	tex_x = 0;
	tex_x = (int)(wall_x * (double)texture->width);
	if ((game->ray->side == 0 && game->ray->raydir_x > 0)
		|| (game->ray->side == 1 && game->ray->raydir_y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

/*
Selecciona la textura según el lado golpeado (side) y la dirección del rayo.
Calcula wall_x para encontrar la posición precisa del impacto en la pared
y usa esto para determinar las coordenadas de la textura (tex_x y tex_y).
 */
void	draw_column(t_game *game, int x)
{
	int				y;
	mlx_texture_t	*texture;
	double			wall_x;
	uint8_t			*pixel;
	int				colour;

	texture = select_texture(game);
		// Selección de la textura según el lado golpeado
	wall_x = calculate_wall_x(game);
		// Calcular wall_x dinámicamente
	game->texture->tex_x = calculate_tex_x(game, texture, wall_x);
		// Cálculo de tex_x basado en wall_x
	game->texture->step = 1.0 * IMG_SIZE / game->ray->line_height;
	game->texture->tex_pos = (game->ray->draw_start - SCREEN_HEIGHT / 2
			+ game->ray->line_height / 2) * game->texture->step;
	y = game->ray->draw_start - 1; // Dibuja la columna, píxel por píxel
	while (++y < game->ray->draw_end)
	{// Calcula tex_y para cada píxel
		game->texture->tex_y = (int)(game->texture->tex_pos) & (IMG_SIZE - 1);
		game->texture->tex_pos += game->texture->step;
		pixel = &texture->pixels[IMG_SIZE * game->texture->tex_y * 4
			+ game->texture->tex_x * 4];
		colour = pixel[0] << 24 | pixel[1] << 16 | pixel[2] << 8 | pixel[3];
		mlx_put_pixel(game->img, x, y, colour);
	}
}

/*
Construcción del color:

pixel[2] << 16: Componente roja en el formato RGB.
pixel[1] << 8: Componente verde.
pixel[0]: Componente azul.
0xFF << 24: Canal alfa (opacidad).
 */