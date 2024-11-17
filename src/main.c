/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:08:18 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/17 14:11:05 by sheferna         ###   ########.fr       */
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

int	main(int argc, char **argv) // mapa.cub
{
	int		x;
	t_game	*game;

	if (argc != 2)
		return (ft_printf("%s\n", "Error: Wrong number of arguments"), 2);
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	if (init_game(game))
		return (1);
	x = ft_strlen(argv[1]) - 1;
	if (argv[1][x] == 'b' && argv[1][x - 1] == 'u' && argv[1][x - 2] == 'c'
		&& argv[1][x - 3] == '.') // checkea nombre
	{
		if (!check_input(argv[1], game)) // checkea inputs del archivo
			return (free_game(game), 1); // hacer free de las structs
	}
	else
		return (ft_printf("%s\n", "Error: Map name is wrong"), 2);
	print2d(game->mapsets->map);
	// Inicializar MLX42
	game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", true);
	if (!game->mlx)
		return (free_game(game),
			ft_printf("Error: MLX initialization failed\n"), 1);
	// Crear la imagen donde dibujar
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
		return (free_game(game), ft_printf("Error: Image creation failed\n"),
			1);
	// Configurar el render loop
	mlx_loop_hook(game->mlx, (void (*)(void *))draw_frame, game);
	// Iniciar el bucle de eventos
	mlx_loop(game->mlx);
	free_game(game);
	return (0);
}
