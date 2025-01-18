/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:34:13 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/18 14:32:02 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structures.h"

// moves & rotation
void				moves(mlx_key_data_t keydata, void *param);
void				move_player(double x, double y, t_game *game);
void				rotate(t_game *game, int dir);

// parser
int					parse_path(char *line, t_game *game);
int					parse_line(char *line, t_game *game);
int					check_line(char *l, t_game *game, int vert_len);
char				*check_path(char *line, t_game *game);
int					get_rgb(t_game *game);
int					check_border(char **map, int vert);
int					ft_strlen_map(const char *s);
int					get_map(char *file_name, t_game *game);
void				check_empty_file(int fd, t_game *game);
int					check_input(char *file_name, t_game *game);
void				free_game(t_game *game);
void				print2d(char **str);
char				*cut_line(char *line, t_game *game);
void				free2d(char **str);

void				resize_ptr(int32_t width, int32_t height, void *param);

// validations
void				validate_paths(t_mapsets *mapsets, t_game *game);
void				map_validation(char *argv[1], t_game *game);
void				validate_game(t_game *game);
void				validate_frame(t_game *game);
int					validate_ray(t_ray *ray, t_mapsets *mapsets);

// init structures
int					init_game(t_game *game);
void				init_player(t_player *player);
void				set_player_direction(t_player *player, char spawn);
void				init_player_from_map(t_game *game);

// error handling
int					error(char *message);
void				error_exit(char *message, t_game *game);

// loading png
void				textures_loading(t_game *game);
void				img_loading(t_game *game);

// calculations
void				calculate_ray_direction(t_game *game, int x);
void				calculate_delta_dist(t_game *game);
void				calculate_perp_wall_dist(t_game *game);
void				calculate_draw_limits(t_game *game);

// ceiling and floor render
void				precalculate_colours(t_game *game);
void				draw_ceiling(t_game *game, int x);
void				draw_floor(t_game *game, int x);

// raycasting
int					put_pixel_to_image(mlx_image_t *img, int x, int y,
						int color);
void				clear_image(mlx_image_t *img);
void				initialize_step_and_side_dist(t_game *game);
void				perform_dda(t_game *game);
void				draw_column(t_game *game, int x);
void				cast_ray(t_game *game, int x);
void				draw_frame(t_game *game);
double				my_floor(double x);
double				my_fabs(double x);

#endif