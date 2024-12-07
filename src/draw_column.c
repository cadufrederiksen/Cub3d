/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:35:19 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/07 17:49:55 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_texture_t *select_texture(t_game *game)
{
    if (!game || !game->ray)
        return (error("Error: Game or ray structure is NULL\n"), NULL);
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
    double wall_x;

    if (game->ray->side == 0)
        wall_x = game->player->pos_y + game->ray->perp_walldist * game->ray->raydir_y;
    else
        wall_x = game->player->pos_x + game->ray->perp_walldist * game->ray->raydir_x;
    return (wall_x - my_floor(wall_x)); // mantener solo la parte decimal
}

int	calculate_tex_x(t_game *game, mlx_texture_t *texture, double wall_x)
{
    int tex_x; 
	
	tex_x = 0;
	tex_x = (int)(wall_x * (double)texture->width);
    if ((game->ray->side == 0 && game->ray->raydir_x > 0) ||
        (game->ray->side == 1 && game->ray->raydir_y < 0))
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
	int	y;
	int	tex_y;
	int	colour;
	mlx_texture_t *texture;
	double wall_x;

	y = 0;
	tex_y = 0;
	texture = NULL;
	texture = select_texture(game); // Selección de la textura según el lado golpeado
	wall_x = calculate_wall_x(game); // Calcular wall_x dinámicamente
	game->texture->tex_x = calculate_tex_x(game, texture, wall_x); // Cálculo de tex_x basado en wall_x
	y = game->ray->draw_start; // Dibuja la columna, píxel por píxel
	while (y < game->ray->draw_end)
	{
		// Calcula tex_y para cada píxel
		//tex_y = (int)(((y - game->ray->draw_start) * texture->height) / game->ray->line_height);
		tex_y = (int)((double)(y - game->ray->draw_start) / game->ray->line_height * texture->height);
		// Obtén el color del píxel de la textura
		colour = *(int *)(texture->pixels + (tex_y * texture->width + game->texture->tex_x) * 4);
		//uint8_t *pixel = texture->pixels + (tex_y * texture->width + game->texture->tex_x) * 4;
		//colour = (pixel[2] << 16) | (pixel[1] << 8) | (pixel[0]) | (0xFF << 24);
		put_pixel_to_image(game->img, x, y, colour); // Dibuja el píxel en la pantalla
		y++;
	}
}
