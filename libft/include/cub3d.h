/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:41:06 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/15 20:25:00 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct s_mapsets
{
	char	spawn; //flags para verificar
	int		p_x; //hor
	int		p_y; //vert
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	*f_path; //rgb como str
	char	*c_path;
	char	**map;
	int		ceiling_rgb[3];
	int		floor_rgb[3];
	int		vert_len;
	int		hor_len;
	int		vars_flag; //checkea si hay 6 innstrucciones

} t_mapsets;

typedef struct s_player
{
    double	posX; 	// Posición del jugador
	double	posY;   // Posición del jugador
    double	dirX; 	// Dirección del jugador
	double	dirY;   // Dirección del jugador
    double	planeX; // Plano de la cámara
	double	planeY; // Plano de la cámara
} t_player;

typedef struct s_game
{
    mlx_t *mlx;         // Conexión con MLX42
    mlx_image_t *img;   // Imagen para dibujar
    t_mapsets *mapsets; // Estructura del mapa
    t_player player;    // Jugador
} t_game;

void	free2d(char **str);
int		ft_strlen_map(const char *s);
int		get_map(char * file_name, t_game *game);
int		check_input(char *file_name, t_game *game);
int		init_game(t_game *game);
void	free_game(t_game *game);
char	*cut_line (char *line, t_game *game);

// raycasting
void	put_pixel_to_image(mlx_image_t *img, int x, int y, int color);
void	clear_image(mlx_image_t *img);
void	cast_ray(t_game *game, int x);         // Lanza un rayo y calcula la intersección con las paredes
void	draw_frame(t_game *game);              // Renderiza un frame completo

#endif