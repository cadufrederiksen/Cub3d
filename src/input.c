/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:13:29 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/14 18:38:08 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *l, t_game *game, int vert_len)
{
	int			x;
	static int	spawn = 0;

	x = 0;
	while ((l[x] == '0' || l[x] == '1' || l[x] == 'W' || l[x] == 'N'
			|| l[x] == 'E' || l[x] == 'S' || l[x] == ' ') && l[x] != '\n')
	{
		if (l[x] == 'W' || l[x] == 'N' || l[x] == 'E' || l[x] == 'S')
		{
			if (spawn == 1)
				return (1);
			spawn++;
			game->mapsets->spawn = l[x];
			l[x] = '0';
			game->mapsets->p_x = x;
			game->mapsets->p_y = vert_len;
		}
		x++;
	}
	if (x != ft_strlen_map(l))
		return (1);
	if (game->mapsets->hor_len < x)
		game->mapsets->hor_len = x;
	return (0);
}

int	parse_path(char *line, t_game *game)
{
	int	x;

	x = 0;
	while (line[x] == ' ' || line[x] == '	')
		x++;
	if (!ft_strncmp(&line[x], "NO ", 3))
		game->mapsets->no_path = cut_line(line + 3 + x, game);
	else if (!ft_strncmp(&line[x], "SO ", 3))
		game->mapsets->so_path = cut_line(line + 3 + x, game);
	else if (!ft_strncmp(&line[x], "WE ", 3))
		game->mapsets->we_path = cut_line(line + 3 + x, game);
	else if (!ft_strncmp(&line[x], "EA ", 3))
		game->mapsets->ea_path = cut_line(line + 3 + x, game);
	else if (!ft_strncmp(&line[x], "F ", 2))
		game->mapsets->f_path = cut_line(line + 2 + x, game);
	else if (!ft_strncmp(&line[x], "C ", 2))
		game->mapsets->c_path = cut_line(line + 2 + x, game);
	else
		return (1);
	return (0);
}

int	parse_line(char *line, t_game *game)
{
	static int	flag = 0;

	if (line[0] == '\n')
	{
		if (game->mapsets->vert_len != 0)
			flag = 1;
		return (0);
	}
	else if (!parse_path(line, game))
		return (0);
	else if (!check_line(line, game, game->mapsets->vert_len)
		&& game->mapsets->vars_flag == 6 && flag == 0)
		game->mapsets->vert_len++;
	else
		error_exit("Error: Invalid configuration elements\n", game);
	return (0);
}

int	check_input(char *file_name, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("Error: Failed to open file\n", game);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, game) == 1)
			return (close(fd), free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	if (game->mapsets->vars_flag != 6)
	{
		close(fd);
		free(line);
		error_exit("Error: Wrong number of map instructions\n", game);
	}
	get_map(file_name, game);
	if (get_rgb(game))
		return (close(fd), free(line), 1);
	return (close(fd), free(line), 0);
}
