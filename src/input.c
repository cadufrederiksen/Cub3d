/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:13:29 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/16 12:28:12 by carmarqu         ###   ########.fr       */
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

char	*check_path(char *line, t_game *game)
{
	int		fd;
	int		len;
	char	*file;

	file = cut_line(line, game);
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		free(file);
		error_exit("Error: Invalid path to images\n", game);
	}
	len = ft_strlen(file) - 1;
	if (len > 4 && file[len - 3] == '.' && file[len - 2] == 'p'
		&& file[len - 1] == 'n' && file[len] == 'g' )
		return (file);
	free(file);
	error_exit("Error: Invalid path to images\n", game);
	return (0);
}

int	parse_path(char *line, t_game *game)
{
	int	x;

	x = 0;
	while (line[x] == ' ' || line[x] == '	')
		x++;
	if (!ft_strncmp(&line[x], "NO ", 3))
		game->mapsets->no_path = check_path(line + 3 + x, game);
	else if (!ft_strncmp(&line[x], "SO ", 3))
		game->mapsets->so_path = check_path(line + 3 + x, game);
	else if (!ft_strncmp(&line[x], "WE ", 3))
		game->mapsets->we_path = check_path(line + 3 + x, game);
	else if (!ft_strncmp(&line[x], "EA ", 3))
		game->mapsets->ea_path = check_path(line + 3 + x, game);
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
	{
		game->mapsets->vert_len++;
	}
	else
		error_exit("Error: Invalid configuration elements\n", game);
	return (0);
}

int	check_input(char *file_name, t_game *game)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("Error: Failed to open file\n", game);
	game->mapsets->line = get_next_line(fd);
	while (game->mapsets->line)
	{
		parse_line(game->mapsets->line, game);
		free(game->mapsets->line);
		game->mapsets->line = get_next_line(fd);
	}
	close(fd);
	if (game->mapsets->vars_flag != 6)
	{
		error_exit("Error: Wrong number of map instructions\n", game);
	}
	get_map(file_name, game);
	get_rgb(game);
	return (close(fd), 0);
}
