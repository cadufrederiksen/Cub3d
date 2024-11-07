/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:13:29 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/07 16:48:55 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"


char 	*cut_line (int init, char *line, char* type)//type es cual datos vamo a extrae NO, SO, WE, etc
{
	int x;
	char *path;
	
	ft_printf("%s\n", line);
	while (*line = ' ') //añandir tabs 
		*line++;
	path = ft_substr(line, 0, ft_strlen(line));
	ft_printf("%s\n", path);
}

void    parse_line(char *line, t_game *game)
{
    if (!ft_strncmp(line, "NO", 3))
		cut_line(3, *line + 3, "NO");
	/* if (!ft_strncmp(line, "SO", 3))

	if (!ft_strncmp(line, "WE", 3))
		
	if (!ft_strncmp(line, "EA", 3))
	
	if (!ft_strncmp(line, "F", 2))
	
	if (!ft_strncmp(line, "C", 2)) */
}

int     check_file(char *file_name, t_game *game)
{
    int fd;
    char *line;
    
    fd = open(file_name, O_RDONLY);
    line = get_next_line(fd);
    while (line) //analiza linha por linha e tira a informaçao necessaria sem fazer uma cópia
	{
		parse_line(line);
		free(line);
		line = get_next_line(fd);
	}
}