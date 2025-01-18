/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:13:29 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/18 15:47:34 by carmarqu         ###   ########.fr       */
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

void	check_empty_file(int fd, t_game *game)
{
	if (!game->mapsets->line)
	{
		close(fd);
		error_exit("Error: The map file is empty\n", game);
	}
}

int	check_input(char *file_name, t_game *game)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("Error: Failed to open file\n", game);
	game->mapsets->line = get_next_line(fd);
	check_empty_file(fd, game);
	while (game->mapsets->line)
	{
		parse_line(game->mapsets->line, game);
		free(game->mapsets->line);
		game->mapsets->line = get_next_line(fd);
	}
	close(fd);
	validate_paths(game->mapsets, game);
	if (game->mapsets->vars_flag != 6 || game->mapsets->vert_len == 0)
		error_exit("Error: Incorrect number of map instructions\n", game);
	get_map(file_name, game);
	get_rgb(game);
	return (0);
}
