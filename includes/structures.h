/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:41:06 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/07 19:56:00 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "cub3d.h"
# include <math.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define IMG_SIZE 64
# define ROTATION_SPEED 0.05
# define MOV_SPEED 0.25

# define ERROR_LOADING "Error: Loading process failed\n"

typedef struct s_mapsets
{
	char			spawn; // flags para verificar
	int				p_x; // hor
	int				p_y; // vert
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
	char			*f_path; // rgb como str
	char			*c_path;
	char			**map;
	int				ceiling_rgb[3];
	int				floor_rgb[3];
	int				vert_len;
	int				hor_len;
	int				vars_flag; // checkea si hay 6 innstrucciones
}					t_mapsets;

typedef enum e_axis
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_axis;

typedef enum e_hit_point
{
	HIT_X,
	HIT_Y,
}	t_hit_point;

typedef struct s_player
{
	double			pos_x; // Posición del jugador
	double			pos_y; // Posición del jugador
	double			dir_x; // Dirección del jugador
	double			dir_y; // Dirección del jugador
	double			plane_x; // Plano de la cámara FOV
	double			plane_y; // Plano de la cámara FOV
}					t_player;

typedef struct s_ray
{
	double			raydir_x;
	double			raydir_y;
	double			deltadist_x;
	// deltadist: Distancia que el rayo necesita para recorrer un bloque de mapa en los ejes X e Y
	double			deltadist_y;
	double			sidedist_x;
	// sidedist: Distancia desde la posición actual del rayo hasta la próxima intersección con una línea de la cuadrícula
	double			sidedist_y;
	double			perp_walldist;
	// Distancia perpendicular desde el jugador hasta la pared que el rayo golpea
	int				map_x; // map_: Coordenadas del bloque del mapa
	int				map_y;
	t_axis			step_x;
	t_axis			step_y;
	t_hit_point		side;
	// Indica si el rayo golpeó una pared vertical (0) u horizontal (1)
	int				line_height;
	// Altura de la línea a dibujar en pantalla para esta columna
	int				draw_start;
	// draw_: Puntos en la pantalla donde empieza y termina la línea que representa la pared
	int				draw_end;
}					t_ray;

typedef struct s_texture_data
{
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
}					t_texture_data;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_image_t		*frame; // Imagen donde dibujar cada frame antes de actualizar la ventana
	// Imagen donde dibujar cada frame antes de actualizar la ventana
	t_mapsets		*mapsets;
	t_player		*player;
	// Estructura para manejar la posición y orientación del jugador
	t_ray			*ray;
	// Estructura para almacenar datos relacionados con el raycasting
	t_texture_data	*texture;
	// Almacena las texturas necesarias para renderizar los elementos
	mlx_texture_t	*textures[4];
	int				ceiling_colour; // Color precalculado del techo
    int				floor_colour;   // Color precalculado del suelo
}					t_game;

#endif