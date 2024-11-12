/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 10:43:12 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/12 13:37:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int init_game(t_game *game)
{
	game->mapsets = malloc(sizeof(t_mapsets));
	if (!game->mapsets)
		return (1);
	game->mapsets->vert_len = 0;
	return (0);
}

void	free_game(t_game *game)
{
	int x;
	
	x = 0;
	x = game->mapsets->vert_len;
	while(game->mapsets->map[x])
	{
		printf("%s\n", game->mapsets->map[x]);
		free(game->mapsets->map[x--]);
	}
	free(game->mapsets->map); //hacer free de los paths
	free(game->mapsets);
	free(game);
}