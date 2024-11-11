/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:13:29 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/11 22:55:40 by carmarqu         ###   ########.fr       */
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

int		check_line(char *line, t_game *game) //checkea si los caracteres del mapa son validos
{
	int x;
	int spawn;;

	x = 0;
	spawn = 0;
	while ((line[x] == '0' || line[x] == '1' || line[x] == 'W' || line[x] == 'N'
		|| line[x] == 'E' || line[x] == 'S' || line[x] == ' ') && line[x]  != '\n')
	{
		if (line[x] == 'W' || line[x] == 'N' || line[x] == 'E' || line[x] == 'S')
		{
			if (spawn == 1)
				return (0); //no puede haber mas de un spawn
			spawn = 1;
			game->mapsets->spawn = line[x];
		}
		x++;
	}
	if (x != ft_strlen_map(line))
		return (0);
	if (game->mapsets->hor_len < x)
		game->mapsets->hor_len = x;
	return (1);
}

char	*cut_line (char *line)
{
	int x;
	char *path;
	
	x = 0;
	while (line[x] == ' ') //añandir tabs 
		x++;
	path = ft_substr(line, x, ft_strlen(line) - 2);//hace un malloc y copia sin el \0 y \n
	return (path);
}

int		parse_line(char *line, t_game *game)//guarda todos las instruciones pero no las checkeas
{
	if (line[0] == '\n')
		return (0);
	if (!ft_strncmp(line, "NO", 3))
		game->mapsets->no_path = cut_line(line + 2);
	else if (!ft_strncmp(line, "SO", 3))
		game->mapsets->so_path = cut_line(line + 2);
	else if (!ft_strncmp(line, "WE", 3))
		game->mapsets->we_path = cut_line(line + 2);
	else if (!ft_strncmp(line, "EA", 3))
		game->mapsets->ea_path = cut_line(line + 2);
	else if (!ft_strncmp(line, "F", 2))
		game->mapsets->f_path =	cut_line(line + 1);
	else if (!ft_strncmp(line, "C", 2)) 
		game->mapsets->c_path =	cut_line(line + 1);
	else if(check_line(line, game))//si devuelve una linea valida del mapa
		game->mapsets->vert_len++;
	else
		return (ft_printf("Invalid instruction in map file\n"), 1);
	return (0);
	//si hay una linea que no es salto de línea me da error
} 

int     check_file(char *file_name, t_game *game)
{
    int fd;
    char *line;
    
    fd = open(file_name, O_RDONLY);
    line = get_next_line(fd);
    while (line) //analiza linha por linha e tira a informaçao necessaria sem fazer uma cópia de todo o aqruivo
	{
		if (parse_line(line, game) == 1)
			return (close(fd), free(line), 0);
		free(line);
		line = get_next_line(fd);
	}
	get_map(file_name, game);
	return (close(fd), free(line), 1);
}