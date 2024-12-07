/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sheferna <sheferna@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:08:18 by carmarqu          #+#    #+#             */
/*   Updated: 2024/12/07 18:18:00 by sheferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_game *allocate_game(void)
{
    t_game *game;

    game = calloc(1, sizeof(t_game));
    if (!game)
        error_exit("Error: Failed to allocate memory for game\n", NULL);
    if (init_game(game))
        error_exit("Error: Game initialisation failed\n", game);
    return (game);
}

int main(int argc, char **argv)
{
    t_game *game;

    if (argc != 2)
        return (error("Error: Wrong number of arguments\n"));
	game = allocate_game();
    if (map_validation(argv, game))
        error_exit("Error: Map validation failed\n", game);
    if (validate_texture_paths(game->mapsets))
        error_exit("Error: Invalid texture paths\n", game);
    init_player_from_map(game);
    game->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D", true);
    if (!game->mlx)
        error_exit("Error: MLX initialization failed\n", game);
    game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->img)
        error_exit("Error: Image creation failed\n", game);
    textures_loading(game);
    img_loading(game);
    mlx_resize_hook(game->mlx, &resize_ptr, game);
    mlx_key_hook(game->mlx, moves, game);
    mlx_loop_hook(game->mlx, (void (*)(void *))draw_frame, game);
    mlx_loop(game->mlx);
    free_game(game);
    return (0);
}
