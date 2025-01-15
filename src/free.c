/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:04:16 by sheferna          #+#    #+#             */
/*   Updated: 2025/01/15 13:57:27 by carmarqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_mapsets(t_mapsets *maps)
{
    if (maps->no_path)
    {
        printf("Freeing no_path\n");
        free(maps->no_path);
    }
    if (maps->so_path)
    {
        printf("Freeing so_path\n");
        free(maps->so_path);
    }
    if (maps->we_path)
    {
        printf("Freeing we_path\n");
        free(maps->we_path);
    }
    if (maps->ea_path)
    {
        printf("Freeing ea_path\n");
        free(maps->ea_path);
    }
    if (maps->c_path)
    {
        printf("Freeing c_path\n");
        free(maps->c_path);
    }
    if (maps->f_path)
    {
        printf("Freeing f_path\n");
        free(maps->f_path);
    }
}

void free2d(char **str)
{
    int x;

    if (!str)
        return;
    x = 0;
    while (str[x])
        x++;
    while (x >= 0)
    {
        printf("Freeing str[%d]\n", x);
        free(str[x--]);
    }
    printf("Freeing str\n");
    free(str);
}

void free_images(t_game *game)
{
    int x;

    if (!game)
        return;
    x = 3;
    if (game->img)
    {
        printf("Deleting image\n");
        mlx_delete_image(game->mlx, game->img);
    }
    if (game->frame)
    {
        printf("Deleting frame\n");
        mlx_delete_image(game->mlx, game->frame);
    }
    while (x >= 0)
    {
        if (game->textures[x])
        {
            printf("Deleting texture[%d]\n", x);
            mlx_delete_texture(game->textures[x]);
        }
        x--;
    }
}

void free_game(t_game *game)
{
    if (!game)
        return;
    if (game->mapsets && game->mapsets->map)
        free2d(game->mapsets->map);
    if (game->mapsets)
    {
        free_mapsets(game->mapsets);
		printf("Freeing mapsets\n");
        free(game->mapsets);
    }
    if (game->player)
    {
        printf("Freeing player\n");
        free(game->player);
    }
    if (game->ray)
    {
        printf("Freeing ray\n");
        free(game->ray);
    }
    if (game->texture)
    {
        printf("Freeing texture\n");
        free(game->texture);
    }
    free_images(game);
    if (game->mlx)
    {
        printf("Terminating mlx\n");
        mlx_terminate(game->mlx);
    }
    printf("Freeing game\n");
    free(game);
}
