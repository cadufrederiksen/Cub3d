/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:29:04 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/18 16:04:45 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_spaces(char **map)
{
	int	x;
	int	i;

	x = 0;
	while (map[x])
	{
		i = 0;
		while (map[x][i])
		{
			if (map[x][i] == '0')
			{
				if ((map[x - 1][i] != '1' && map[x - 1][i] != '0')
				|| (map[x + 1][i] != '1' && map[x + 1][i] != '0')
				|| (map[x][i + 1] != '1' && map[x][i + 1] != '0')
				|| (map[x][i - 1] != '1' && map[x][i - 1] != '0'))
					return (1);
			}
			i++;
		}
		x++;
	}
	return (0);
}

int	check_border(char **map, int vert)
{
	int	x;
	int	i;

	x = 0;
	while (map[x])
	{
		i = 0;
		while (map[x][i] == ' ')
			i++;
		if (map[x][i] == '0' || map[x][ft_strlen_map(map[x]) - 1] == '0')
			return (1);
		x++;
	}
	i = 0;
	x = 0;
	while (map[0][i] && map[0][i] != '0')
		i++;
	while (map[vert - 1][x] && map[vert - 1][x] != '0')
		x++;
	if (i != ft_strlen_map(map[0]) || x != ft_strlen_map(map[vert - 1]))
		return (1);
	if (check_spaces(map))
		return (1);
	return (0);
}

int	is_spawn(char *line)
{
	unsigned int	x;

	x = 0;
	while (line[x] != 'N' && line[x] != 'E' && line[x] != 'S'
		&& line[x] != 'W' && line[x])
		x++;
	if (x != ft_strlen(line))
		line[x] = '0';
	return (1);
}

int	is_map(char *line)
{
	int	x;

	x = 0;
	if (line[x] == '\n')
		return (0);
	while (line[x] == ' ' || line[x] == '	')
		x++;
	if (!ft_strncmp(&line[x], "NO ", 3))
		return (0);
	else if (!ft_strncmp(&line[x], "SO ", 3))
		return (0);
	else if (!ft_strncmp(&line[x], "WE ", 3))
		return (0);
	else if (!ft_strncmp(&line[x], "EA ", 3))
		return (0);
	else if (!ft_strncmp(&line[x], "F ", 2))
		return (0);
	else if (!ft_strncmp(&line[x], "C", 2))
		return (0);
	else if (is_spawn(line))
		return (1);
	else
		return (1);
}

int	get_map(char *file_name, t_game *game)//error d ememoria puede s
{
	char	*line;
	int		fd;
	int		x;

	x = 0;
	game->mapsets->map = (char **)malloc(sizeof(char *)
			* (game->mapsets->vert_len + 1));
	if (!game->mapsets->map)
		error_exit("Error: Failed to allocate memory for map\n", game);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		error_exit("Error: Failed to open file\n", game);
	}
	line = get_next_line(fd);
	while (line)
	{
		if (is_map(line))
			game->mapsets->map[x++] = ft_substr(line, 0, ft_strlen_map(line));
		free(line);
		line = get_next_line(fd);
	}
	game->mapsets->map[x] = NULL;
	return (close(fd), free(line), 0);
}
