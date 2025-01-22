/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:13:29 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/22 12:13:12 by carmarqu         ###   ########.fr       */
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
	if (len > 4 && file[len - 3] == '.' && file[len - 2] == 'p' && file[len
			- 1] == 'n' && file[len] == 'g')
	{
		close(fd);
		return (file);
	}
	close(fd);
	free(file);
	error_exit("Error: Invalid image format (must be .png)\n", game);
	return (0);
}

int	get_file_len(char *file, t_game *game)
{
	int		x;
	char	*line;
	int		fd;

	x = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_exit("Error: Failed to open file\n", game);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		error_exit("Error: The map file is empty\n", game);
	}
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		x++;
	}
	close(fd);
	return (x);
}

int	get_file(char *file_name, t_game *game)
{
	int	fd;
	int	x;
	int	len;

	x = 0;
	len = get_file_len(file_name, game);
	game->mapsets->file = (char **)malloc(sizeof(char *) * (len + 1));
	if (!game->mapsets->file)
		error_exit("Error: Failed to allocate memory for file\n", game);
	fd = open(file_name, O_RDONLY);
	game->mapsets->line = get_next_line(fd);
	while (game->mapsets->line)
	{
		game->mapsets->file[x] = ft_strdup(game->mapsets->line);
		free(game->mapsets->line);
		game->mapsets->line = get_next_line(fd);
		x++;
	}
	return (len);
}

int	check_input(char *file_name, t_game *game)
{
	int	x;
	int	len;

	len = get_file(file_name, game);
	x = 0;
	while (x < len)
	{
		parse_line(game->mapsets->file[x], game);
		x++;
	}
	validate_paths(game->mapsets, game);
	if (game->mapsets->vars_flag != 6 || game->mapsets->vert_len == 0)
		error_exit("Error: Incorrect number of map instructions\n", game);
	get_map(file_name, game);
	get_rgb(game);
	return (0);
}
