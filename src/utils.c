/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:46:05 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/08 13:16:54 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen_map(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int		get_end_path(char *line, int start)
{
	int end;
	
	end = 0;
	while (line[start] != ' ' && line[start] != '	'
		&& line[start != '\0'] && line[start] != '\n')
	{
		start++;
		end++;
	}
	return (end);
}

char	*cut_line(char *line, t_game *game)//flag para saber si es un path o numeros del rgb
{
	int		x;
	char	*path;

	x = 0;
	while (line[x] == ' ' || line[x] == '	')
		x++;
	path = ft_substr(line, x, get_end_path(line, x));//hace un malloc y copia sin el \0 y \n
	ft_printf("%s\n", path);
	game->mapsets->vars_flag++;
	return (path);
}

void	print2d(char **str)
{
	int	x;

	x = 0;
	while (str[x])
		ft_printf("%s\n", str[x++]);
}

void	resize_ptr(int32_t width, int32_t height, void *param)
{
	(void)width;
	(void)height;
	(void)param;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}
