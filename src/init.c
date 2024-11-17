/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:43:12 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/17 16:31:53 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_game(t_game *game)
{
	game->mapsets = malloc(sizeof(t_mapsets));
	if (!game->mapsets)
		return (1);
	game->mapsets->vert_len = 0;
	game->mapsets->vars_flag = 0;
	return (0);
}

void	free_mapsets(t_mapsets *maps)
{
	if (maps->no_path)
		free(maps->no_path);
	if (maps->so_path)
		free(maps->so_path);
	if (maps->we_path)
		free(maps->we_path);
	if (maps->ea_path)
		free(maps->ea_path);
	if (maps->c_path)
		free(maps->c_path);
	if (maps->f_path)
		free(maps->f_path);
}

void	free2d(char **str)
{
	int x;
	
	x = 0;
	while(str[x])
		x++;
	while (x >= 0)
		free(str[x--]);
	free(str);
}

void	free_game(t_game *game)
{
	if (game->mapsets->map)
		free2d(game->mapsets->map);
	free_mapsets(game->mapsets);
	free(game->mapsets);
	free(game);
}
