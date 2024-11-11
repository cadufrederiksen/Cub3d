/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:08:18 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/11 16:46:17 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main (int argc, char **argv) //mapa.cub
{
	int x;
	t_game *game;
	
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (init_game(game))
		return (1);
	if (argc != 2)
		return (ft_printf("%s\n", "Error: Wrong number of arguments"), 2);
	x = ft_strlen(argv[1]) - 1;
	if (argv[1][x] == 'b' && argv[1][x - 1] == 'u' && argv[1][x - 2] == 'c' && argv[1][x - 3] == '.')
	{
		if (!check_file(argv[1], game))
			exit (1); //hacer free de las structs
	}
	else
		return (ft_printf("%s\n", "Error: Map name is wrong"), 2);
}