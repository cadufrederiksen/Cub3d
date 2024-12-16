/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:13:29 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/16 01:04:31 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* int	check_files(char *file) no se si es necesario esas validaciones
{
	if (access(file, F_OK) && access(file, R_OK))
		return (1);
	return (0);
}

int	check_paths(t_game *game)
{
	if (!check_file(game->mapsets->no_path))
		return (0);
	if (!check_file(game->mapsets->so_path))
		return (0);
	if (!check_file(game->mapsets->we_path))
		return (0);
	if (!check_file(game->mapsets->ea_path))
		return (0); 
	return (1); //todos los paath son validos
} */
void	format_rgb(char **rgb)
{
	int x;
	int i;
	char *s;

	i = 0;
	x = 0;
	while (rgb[x])
	{
		while (rgb[x][i] == ' ')
			i++;
		s = ft_substr(rgb[x], i, ft_strlen(rgb[x]));
		free(rgb[x]);
		rgb[x] = s;
		x++;
	}
}

int	check_rgb(char **rgb)
{
	int x; 
	int i;

	x = 0;
	format_rgb(rgb);
	while (rgb[x])
	{
		i = 0;
		while (rgb[x][i])
		{
			if (!ft_isdigit(rgb[x][i]))
				return (1);
			i++;
		}
		x++;
	}
	if (x != 3)
		return (1);
	return (0);
}

int	get_rgb(t_game *game)
{
	char	**rgb1;
	char	**rgb2;
	int		x;

	x = 0;
	rgb1 = ft_split(game->mapsets->f_path, ',');
	rgb2 = ft_split(game->mapsets->c_path, ',');
	if (check_rgb(rgb1) || check_rgb(rgb2))//garantiza que siempre haya 3 numeros, ni mas ni menos
		return (free2d(rgb2), free2d(rgb1), ft_printf("Error: RGB invalid!\n"), 1);
	while (x < 3)
	{
		if ((ft_atoi(rgb2[x]) < 0 || ft_atoi(rgb2[x]) > 255) 
			|| (ft_atoi(rgb1[x]) < 0 || ft_atoi(rgb1[x]) > 255))
			return (ft_printf("Error: RGB out of the valid range!\n"), 1); //si esta fuera de rango, podriamos retornar 1 indicando error
		game->mapsets->floor_rgb[x] = ft_atoi(rgb1[x]);
		game->mapsets->ceiling_rgb[x] = ft_atoi(rgb2[x]);
		x++;
	}
	free2d(rgb1);
	free2d(rgb2);
	return (0);
}

int	check_line(char *line, t_game *game, int vert_len) //checkea si los caracteres del mapa son validos
{
	int			x;
	static int	spawn = 0;

	x = 0;
	while ((line[x] == '0' || line[x] == '1' || line[x] == 'W' || line[x] == 'N'
		|| line[x] == 'E' || line[x] == 'S' || line[x] == ' ') && line[x]  != '\n')
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

int	parse_line(char *line, t_game *game) //guarda todos las instruciones pero no las checkeas
{
	if (line[0] == '\n') //checkear si estan todas las instrucciones NO, C, F, etc..
		return (0);
	else if (!ft_strncmp(line, "NO ", 3))
		game->mapsets->no_path = cut_line(line + 3, game);
	else if (!ft_strncmp(line, "SO ", 3))
		game->mapsets->so_path = cut_line(line + 3, game);
	else if (!ft_strncmp(line, "WE ", 3))
		game->mapsets->we_path = cut_line(line + 3, game);
	else if (!ft_strncmp(line, "EA ", 3))
		game->mapsets->ea_path = cut_line(line + 3, game);
	else if (!ft_strncmp(line, "F ", 2))
		game->mapsets->f_path =	cut_line(line + 2, game);
	else if (!ft_strncmp(line, "C ", 2)) 
		game->mapsets->c_path =	cut_line(line + 2, game);
	else if(!check_line(line, game, game->mapsets->vert_len)
		&& game->mapsets->vars_flag == 6) //si devuelve una linea valida del mapa
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
	if (game->mapsets->vars_flag != 6)
		return (ft_printf("Error: Wrong number of map instructions\n"), close(fd), free(line), 1); //si hay error y usamos la salida de error, deberiamos de retornar 1 aqui
	get_map(file_name, game);//guarda el mapa en un array char **
	//print2d(game->mapsets->map);
	if (get_rgb(game))
		return (close(fd), free(line), 1);
	return (close(fd), free(line), 0);
}
