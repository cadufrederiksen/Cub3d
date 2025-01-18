/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 14:26:34 by sheferna          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/01/18 15:41:13 by carmarqu         ###   ########.fr       */
=======
/*   Updated: 2025/01/18 14:52:29 by sheferna         ###   ########.fr       */
>>>>>>> 0b7f2de5b921c3b969b0f95894a23695d1175003
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_path(char *line, t_game *game)
{
	int	x;

	x = 0;
	while (line[x] == ' ' || line[x] == '\t')
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
<<<<<<< HEAD
		return (1);//aqui
=======
		return (1); //error_exit("Error: Invalid map element\n", game);
>>>>>>> 0b7f2de5b921c3b969b0f95894a23695d1175003
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
