/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:34:11 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/17 13:35:26 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>
#include <stdlib.h>

// Poner un píxel en la imagen
void put_pixel_to_image(mlx_image_t *img, int x, int y, int color)
{
    if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
    {
        int index = (y * img->width + x) * 4; // Cada píxel tiene 4 bytes (RGBA)
        img->pixels[index] = (color >> 16) & 0xFF;   // Rojo
        img->pixels[index + 1] = (color >> 8) & 0xFF; // Verde
        img->pixels[index + 2] = color & 0xFF;        // Azul
        img->pixels[index + 3] = 0xFF;               // Alpha
    }
}

// Limpiar la imagen
void clear_image(mlx_image_t *img)
{
    for (uint32_t i = 0; i < img->width * img->height * 4; i++)
    {
        img->pixels[i] = 0; // Poner cada píxel a negro (RGBA: 0, 0, 0, 0)
    }
}

// Lanza un rayo para calcular la intersección con las paredes
void cast_ray(t_game *game, int x)
{
    double cameraX = 2 * x / (double)SCREEN_WIDTH - 1; // Posición en el plano de la cámara
    double rayDirX = game->player.dirX + game->player.planeX * cameraX;
    double rayDirY = game->player.dirY + game->player.planeY * cameraX;

    int mapX = (int)game->player.posX;
    int mapY = (int)game->player.posY;

    double sideDistX, sideDistY;
    double deltaDistX = fabs(1 / rayDirX);
    double deltaDistY = fabs(1 / rayDirY);
    double perpWallDist;

    int stepX, stepY;
    int hit = 0;
    int side;

    // Calcular paso e inicializar distancias
    if (rayDirX < 0)
    {
        stepX = -1;
        sideDistX = (game->player.posX - mapX) * deltaDistX;
    }
    else
    {
        stepX = 1;
        sideDistX = (mapX + 1.0 - game->player.posX) * deltaDistX;
    }
    if (rayDirY < 0)
    {
        stepY = -1;
        sideDistY = (game->player.posY - mapY) * deltaDistY;
    }
    else
    {
        stepY = 1;
        sideDistY = (mapY + 1.0 - game->player.posY) * deltaDistY;
    }

    // DDA para encontrar la pared
    while (hit == 0)
    {
        if (sideDistX < sideDistY)
        {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        }
        else
        {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }

        if (game->mapsets->map[mapY][mapX] == '1') // Si el rayo golpea una pared
            hit = 1;
    }

    // Calcular la distancia perpendicular a la pared
    if (side == 0)
        perpWallDist = (mapX - game->player.posX + (1 - stepX) / 2) / rayDirX;
    else
        perpWallDist = (mapY - game->player.posY + (1 - stepY) / 2) / rayDirY;

    // Calcular la altura de la línea en pantalla
    int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

    // Calcular los límites de dibujo
    int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
    if (drawStart < 0)
        drawStart = 0;
    int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
    if (drawEnd >= SCREEN_HEIGHT)
        drawEnd = SCREEN_HEIGHT - 1;

    // Dibujar la columna en la pantalla
    int color = (side == 0) ? 0xFF0000 : 0x00FF00; // Diferente color según el lado
    for (int y = drawStart; y < drawEnd; y++)
    {
        put_pixel_to_image(game->img, x, y, color);
    }
}

// Renderizar un frame completo
void draw_frame(t_game *game)
{
    // Limpiar la imagen antes de dibujar
    clear_image(game->img);

    // Lanza un rayo para cada columna de píxeles
    for (int x = 0; x < SCREEN_WIDTH; x++)
    {
        cast_ray(game, x);
    }
    // Actualizar la ventana con la imagen renderizada
    mlx_image_to_window(game->mlx, game->img, 0, 0);
}
