/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:13:29 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/18 15:38:08 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *line, t_game *game, int vert_len) //checkea si los caracteres del mapa son validos
{
	int			x;
	static int	spawn = 0;

	x = 0;
	while ((line[x] == '0' || line[x] == '1' || line[x] == 'W' || line[x] == 'N'
			|| line[x] == 'E' || line[x] == 'S' || line[x] == ' ') && line[x] != '\n')
	{
		if (line[x] == 'W' || line[x] == 'N' || line[x] == 'E' || line[x] == 'S')
		{
			if (spawn == 1)
				return (1); //no puede haber mas de un spawn
			spawn++;
			game->mapsets->spawn = line[x];
			line[x] = '0';
			game->mapsets->p_x = x;
			game->mapsets->p_y = vert_len;
		}
		x++;
	}
	if (x != ft_strlen_map(line)) //algun caracter no valido en la linea
		return (1);
	if (game->mapsets->hor_len < x)
		game->mapsets->hor_len = x;
	return (0);
}

int	parse_path(char *line, t_game *game)
{
	if (!ft_strncmp(line, "NO ", 3))
		game->mapsets->no_path = cut_line(line + 3, game);
	else if (!ft_strncmp(line, "SO ", 3))
		game->mapsets->so_path = cut_line(line + 3, game);
	else if (!ft_strncmp(line, "WE ", 3))
		game->mapsets->we_path = cut_line(line + 3, game);
	else if (!ft_strncmp(line, "EA ", 3))
		game->mapsets->ea_path = cut_line(line + 3, game);
	else if (!ft_strncmp(line, "F ", 2))
		game->mapsets->f_path = cut_line(line + 2, game);
	else if (!ft_strncmp(line, "C ", 2))
		game->mapsets->c_path = cut_line(line + 2, game);
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
	} //checkear si estan todas las instrucciones NO, C, F, etc..
	else if (!parse_path(line, game))
		return (0);
	else if (!check_line(line, game, game->mapsets->vert_len)
		&& game->mapsets->vars_flag == 6 && flag == 0) //si devuelve una linea valida del mapa
		game->mapsets->vert_len++;
	else
		return (ft_printf("Error: Invalid map file\n"), 1);
	return (0);
}

int	check_input(char *file_name, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(line, game) == 1) //guarda la informacion de las variables y checkea los chars del mapa
			return (close(fd), free(line), 1);
		free(line);
		line = get_next_line(fd);
	}
	if (game->mapsets->vars_flag != 6 || game->mapsets->spawn == 0)
		return (ft_printf("Error: Wrong number of map instructions\n"),
			close(fd), free(line), 1); //si hay error y usamos la salida de error, deberiamos de retornar 1 aqui
	get_map(file_name, game);//guarda el mapa en un array char **
	if (get_rgb(game))
		return (close(fd), free(line), 1);
	return (close(fd), free(line), 0);
}
