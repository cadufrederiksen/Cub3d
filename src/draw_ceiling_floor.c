/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_floor_render.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:21:21 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/07 17:24:59 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	precalculate_colours(t_game *game)
{
    game->ceiling_colour = (game->mapsets->ceiling_rgb[0] << 16) |
                           (game->mapsets->ceiling_rgb[1] << 8) |
                           (game->mapsets->ceiling_rgb[2]);

    game->floor_colour = (game->mapsets->floor_rgb[0] << 16) |
                         (game->mapsets->floor_rgb[1] << 8) |
                         (game->mapsets->floor_rgb[2]);
}

// rellena los píxeles por encima de draw_start con colores sólidos
void	draw_ceiling(t_game *game, int x)
{
	int	y;
	
	y = 0;
	while(y < game->ray->draw_start)
    {
        put_pixel_to_image(game->img, x, y, game->ceiling_colour);
		y++;
    }
}
// rellenan los píxeles por debajo de draw_end con colores sólidos
void	draw_floor(t_game *game, int x)
{
	int	y;
	
	y = 0;
	y = game->ray->draw_end + 1;
	while (y < SCREEN_HEIGHT)
    {
        put_pixel_to_image(game->img, x, y, game->floor_colour);
		y++;
    }
}
