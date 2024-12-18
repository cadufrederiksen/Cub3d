/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 14:30:57 by sheferna          #+#    #+#             */
/*   Updated: 2024/12/18 15:04:26 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Place a pixel on the image
// cada píxel se define como un valor de 32 bits (RGBA)
// Los tipos como uint32_t son estándar definidos por stdint.h y 
// garantizan que el tamaño sea exactamente de 32 bits, 
// independientemente de la arquitectura
// MLX usa uint32_t para asegurarse que no se usan numeros negativos
int	put_pixel_to_image(mlx_image_t *img, int x, int y, int color)
{
	int	index;

	if (!img || !img->pixels)
		return (error("Error: Invalid image or pixel data\n"));
	if (x < 0 || x >= (int)img->width || y < 0 || y >= (int)img->height)
		return (error("Error: Pixel out of image bounds\n"));
	if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT)
	{	//calculate the index of the array of pixels
		index = (y * (int)img->width + x) * 4;
		// Each pixel has 4 bytes (RGBA)
		img->pixels[index] = (color >> 16) & 0xFF;// Red
		img->pixels[index + 1] = (color >> 8) & 0xFF;// Green
		img->pixels[index + 2] = color & 0xFF;// Blue
		img->pixels[index + 3] = 0xFF;// Opaco
	}
	return (0);
}

// Clean the image
/*
Qué memoria llenar: img->pixels.
Qué valor usar: 0 (especificado como el segundo argumento).
Cuánto llenar: img->width * img->height * 4 (el tamaño total en bytes del área de píxeles).
*/
// Llena toda la memoria de img->pixels con ceros
void	clear_image(mlx_image_t *img)
{
	if (!img || !img->pixels)
		return ;
	ft_memset(img->pixels, 0, img->width * img->height * 4);
}

double	my_floor(double x)
{
	int	int_part;

	int_part = (int)x; // Truncar la parte decimal
	if (x >= 0)
		return ((double)int_part); // Si es positivo, devolver directamente la parte entera
	if (x == (double)int_part)
		return (x); // Si es un número entero negativo, devolver tal cual
	return (double)(int_part - 1); // Si es negativo y tiene parte decimal, restar 1
}

double	my_fabs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}
