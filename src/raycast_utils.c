/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:30:57 by sheferna          #+#    #+#             */
/*   Updated: 2024/11/17 16:25:18 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Place a pixel on the image
void	put_pixel_to_image(mlx_image_t *img, int x, int y, int color)
{
	int	index;

	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		index = (y * img->width + x) * 4;
			// Each pixel has 4 bytes (RGBA)
		img->pixels[index] = (color >> 16) & 0xFF;    // Red
		img->pixels[index + 1] = (color >> 8) & 0xFF; // Green
		img->pixels[index + 2] = color & 0xFF;        // Blue
		img->pixels[index + 3] = 0xFF;                // Alpha
	}
}

// Clean the image
void	clear_image(mlx_image_t *img)
{
	uint32_t	i;

	i = 0;
	while (i < img->width * img->height * 4)
	{
		img->pixels[i] = 0; // Place a black pixel (RGBA: 0, 0, 0, 0)
		i++;
	}
}
