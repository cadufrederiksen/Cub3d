/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:08:18 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/07 14:26:51 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print2d(char **str)
{
	int	x;

	x = 0;
	while (str[x])
		ft_printf("%s\n", str[x++]);
}

void	resize_ptr(int32_t width, int32_t height, void *param)
{
	(void)width;
	(void)height;
	(void)param;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
}

int	map_validation(char *argv[1], t_game *game)
{
	int		x;

	x = ft_strlen(argv[1]) - 1;
	if (argv[1][x] == 'b' && argv[1][x - 1] == 'u' && argv[1][x - 2] == 'c'
		&& argv[1][x - 3] == '.') // checkea nombre
	{
		if (!check_input(argv[1], game)) // checkea inputs del archivo
			return (free_game(game), 1); // hacer free de las structs
	}
	else
		return (free_game(game), error("Error: Map name is wrong\n"));
	if (check_border(game->mapsets->map, game))
		return (free_game(game), error("Error: Map is not surrounded by walls\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (error("Error: Wrong number of arguments\n"));
	game = calloc(1, sizeof(t_game));
	if (!game)
		return (1);
	if (init_game(game))
		return (free_game(game), error("Error: Game initialisation failed\n"));
	if (map_validation(argv, game))
		return (1);
	init_player_from_map(game);
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", true);
	if (!game->mlx)
		return (free_game(game), error("Error: MLX initialisation failed\n"));
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
		return (free_game(game), error("Error: Image creation failed\n"));
	textures_loading(game);
	img_loading(game);
	mlx_resize_hook(game->mlx, &resize_ptr, game);//puede que no sea necesario
	//ceil_and_floor();
	mlx_key_hook(game->mlx, moves, game);		
	mlx_loop_hook(game->mlx, (void (*)(void *))draw_frame, game); // rendering config
	mlx_loop(game->mlx); // start the event loop
	free_game(game);
	return (0);
}
