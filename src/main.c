/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:08:18 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/14 18:14:05 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game	*allocate_game(void)
{
	t_game	*game;

	game = calloc(1, sizeof(t_game)); // Use calloc para inicializar todos os campos com 0/NULL
	if (!game)
		error_exit("Error: Failed to allocate memory for game\n", NULL);
	if (init_game(game))
		error_exit("Error: Game initialisation failed\n", game);
	return (game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (error("Error: Wrong number of arguments\n"));
	else
	{
		game = allocate_game();
		map_validation(argv, game);
		init_player_from_map(game);
		game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", true);
		if (!game->mlx)
			error_exit("Error: MLX initialization failed\n", game);
		game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		if (!game->img)
			error_exit("Error: Image creation failed\n", game);
		textures_loading(game);
		img_loading(game);//el error sale antes de aqui
		mlx_resize_hook(game->mlx, &resize_ptr, game);
		mlx_key_hook(game->mlx, moves, game);
		mlx_loop_hook(game->mlx, (void (*)(void *))draw_frame, game);
		mlx_loop(game->mlx);
		free_game(game);
	}
	return (0);
}
