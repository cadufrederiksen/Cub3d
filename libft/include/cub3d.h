/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:41:06 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/11 22:57:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

typedef struct s_mapsets
{
	char	spawn; //flags para verificar
	int 	no;
	int		so;
	int		we;
	int		ea;//flags
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

} t_mapsets;

typedef struct s_game
{
	t_mapsets *mapsets;//hacer malloc

} t_game;

int		ft_strlen_map(const char *s);
int		get_map(char * file_name, t_game *game);
int     check_file(char *file_name, t_game *game);
int		init_game(t_game *game);

#endif