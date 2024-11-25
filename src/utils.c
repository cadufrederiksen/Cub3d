/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:46:05 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/25 20:27:23 by sheferna         ###   ########.fr       */
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

char	*cut_line (char *line, t_game *game)
{
	int		x;
	char	*path;

	x = 0;
	while (line[x] == ' ')	//añadir tabs si hace falta
		x++;
	path = ft_substr(line, x, ft_strlen_map(line)); //hace un malloc y copia sin el \0 y \n
	game->mapsets->vars_flag++;
	return (path);
}
