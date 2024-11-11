/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:29:04 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/11 22:56:45 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	while (line) //analiza linha por linha e tira a informaçao necessaria sem fazer uma cópia de todo o aqruivo
	{
		game->mapsets->map[x] = ft_substr(line, 0, ft_strlen_map(line));
		//printf("%s\n", game->mapsets->map[x]);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	game->mapsets->map[x] = NULL;
	return (close(fd), free(line), 0);
}
