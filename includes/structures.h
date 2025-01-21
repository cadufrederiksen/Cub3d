/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:41:06 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/21 20:15:38 by carmarqu         ###   ########.fr       */
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
	char			*line;
	char			**file;
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
	double			deltadist_y;
	double			sidedist_x;
	double			sidedist_y;
	double			perp_walldist;
	int				map_x;
	int				map_y;
	t_axis			step_x;
	t_axis			step_y;
	t_hit_point		side;
	int				line_height;
	int				draw_start;
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
	mlx_image_t		*frame;
	t_mapsets		*mapsets;
	t_player		*player;
	t_ray			*ray;
	t_texture_data	*texture;
	mlx_texture_t	*textures[4];
	int				ceiling_colour;
	int				floor_colour;
}					t_game;

#endif