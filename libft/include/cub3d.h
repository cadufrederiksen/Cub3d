 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:06:37 by carmarqu          #+#    #+#             */
/*   Updated: 2023/11/14 15:15:32 by carmarqu         ###   ########.fr       */
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
	int		spawnflag; //flags para verificar
	int 	no;
	int		so;
	int		we;
	int		ea;//flags
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	int	ceiling_rgb[3];
	int	floor_rgb[3];


} t_mapsets;

typedef struct s_game
{
	t_mapsets mapsets;//hacer malloc

} t_game;

#endif