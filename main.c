/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:08:18 by carmarqu          #+#    #+#             */
/*   Updated: 2025/01/18 16:23:52 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game	*allocate_game(void)
{
	t_game	*game;

	game = calloc(1, sizeof(t_game));
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
		printf("aqui\n");
		init_player_from_map(game);
		printf("aqui1\n");
		game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", false);
		printf("aqui2\n");
		if (!game->mlx)
			error_exit("Error: MLX initialization failed\n", game);
		game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
		printf("aqui3\n");
		if (!game->img)
			error_exit("Error: Image creation failed\n", game);
		textures_loading(game);
		printf("aqui4\n");
		img_loading(game);
		printf("aqui5\n");
		mlx_resize_hook(game->mlx, &resize_ptr, game);
		mlx_key_hook(game->mlx, moves, game);
		mlx_loop_hook(game->mlx, (void (*)(void *))draw_frame, game);
		mlx_loop(game->mlx);
		free_game(game);
	}
	return (0);
}