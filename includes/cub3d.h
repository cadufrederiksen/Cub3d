/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:41:06 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/17 17:36:10 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <math.h>
# include <stdlib.h>

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

typedef struct s_mapsets
{
	char	spawn; // flags para verificar
	int		p_x;   // hor
	int		p_y;   // vert
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char 	*f_path; // rgb como str
	char	*c_path;
	char	**map;
	int		ceiling_rgb[3];
	int		floor_rgb[3];
	int		vert_len;
	int		hor_len;
	int 	vars_flag; // checkea si hay 6 innstrucciones
}				t_mapsets;

typedef struct s_player
{
	double	pos_x;		// Posición del jugador
	double	pos_y;		// Posición del jugador
	double	dir_x;		// Dirección del jugador
	double	dir_y;		// Dirección del jugador
	double	plane_x;	// Plano de la cámara
	double	plane_y;	// Plano de la cámara
}				t_player;

typedef struct s_ray
{
	double		raydir_x;
	double		raydir_y;
	double		deltadist_x;
	double		deltadist_y;
	double		sidedist_x;
	double		sidedist_y;
	double		perp_walldist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_ray;

typedef struct s_game
{
	mlx_t		*mlx;
	mlx_image_t	*img;	// Imagen para dibujar
	t_mapsets	*mapsets;
	t_player	player;
	t_ray		ray;
}				t_game;

void			free2d(char **str);
int				ft_strlen_map(const char *s);
int				get_map(char *file_name, t_game *game);
int				check_input(char *file_name, t_game *game);
int				init_game(t_game *game);
void			free_game(t_game *game);
char			*cut_line(char *line, t_game *game);

// calculations
void			calculate_ray_direction(t_game *game, int x);
void			calculate_delta_dist(t_game *game);
void			calculate_perp_wall_dist(t_game *game);
void			calculate_draw_limits(t_game *game);
// raycasting
void			put_pixel_to_image(mlx_image_t *img, int x, int y, int color);
void			clear_image(mlx_image_t *img);
void			initialize_step_and_side_dist(t_game *game);
void			perform_dda(t_game *game);
void			draw_column(t_game *game, int x);
void			cast_ray(t_game *game, int x);
void			draw_frame(t_game *game);

#endif