/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:29:04 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/27 19:21:02 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_spaces(char **map)
{
	int x;
	int i;

	x = 0;
	while (map[x])
	{
		i = 0;
		while (map[x][i])
		{
			if (map[x][i] == '0')
			{
				if (map[x - 1][i] == ' ' || map[x + 1][i] == ' '
					|| map[x][i + 1] == ' ' || map[x][i - 1] == ' ')
						return (1);
			}
			i++;		
		}
		x++;
	}
	return (0);
}

int		check_border(char **map, t_game *game)
{
	int x;
	int i;
	
	x = 0;
	while (map[x])
	{
		i = 0;
		if (map[x][i] == '0' || map[x][ft_strlen_map(map[x]) - 1] == '0')
				return (1);
		while (map[x][i])
		{	
			if (map[game->mapsets->vert_len - 1][i] == '0' || map[0][i] == '0')
				return (1);
			i++;
		}
		x++;
	}
	if (check_spaces(map))
		return (1);
	return (0);
}

int		is_map(char *line)//buscar manera de checkear si hay los 6 elementos
{
	if (line[0] == '\n')
		return (0);
	if (!ft_strncmp(line, "NO", 3))
		return (0);
	else if (!ft_strncmp(line, "SO", 3))
		return (0);
	else if (!ft_strncmp(line, "WE", 3))
		return (0);
	else if (!ft_strncmp(line, "EA", 3))
		return (0);
	else if (!ft_strncmp(line, "F", 2))
		return (0);
	else if (!ft_strncmp(line, "C", 2)) 
		return (0);
	else 
		return(1);
}

int		get_map(char *file_name, t_game* game)
{
	char	*line;
	int		fd;
	int		x;

	x = 0;
	game->mapsets->map = (char **)malloc(sizeof(char *) * (game->mapsets->vert_len + 1));
	if(!game->mapsets->map)
		return (0);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);	
	while (line) //mira linea por linea para obtener las infos
	{
		if (is_map(line))
		{
			game->mapsets->map[x] = ft_substr(line, 0, ft_strlen_map(line));
			x++;
		}
		free(line);
		line = get_next_line(fd);
	}
	game->mapsets->map[x] = NULL;
	return (close(fd), free(line), 0);
}
