/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:30:57 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/14 13:49:09 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	put_pixel_to_image(mlx_image_t *img, int x, int y, int color)
{
	int	index;

	if (!img || !img->pixels)
		return (error("Error: Invalid image or pixel data\n"));
	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return (error("Error: Pixel out of image bounds\n"));
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{
		index = (y * (int)img->width + x) * 4;
		img->pixels[index] = (color >> 16) & 0xFF;
		img->pixels[index + 1] = (color >> 8) & 0xFF;
		img->pixels[index + 2] = color & 0xFF;
		img->pixels[index + 3] = 0xFF;
	}
	return (0);
}

void	clear_image(mlx_image_t *img)
{
	if (!img || !img->pixels)
		return ;
	ft_memset(img->pixels, 0, img->width * img->height * 4);
}

double	my_floor(double x)
{
	int	int_part;

	int_part = (int)x;
	if (x >= 0)
		return ((double)int_part);
	if (x == (double)int_part)
		return (x);
	return ((double)int_part - 1);
}

double	my_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
