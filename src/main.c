/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carmarqu <carmarqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:08:18 by carmarqu          #+#    #+#             */
/*   Updated: 2024/11/07 16:52:23 by carmarqu         ###   ########.fr       */
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
    if (argc != 3)
        return (ft_printf("%s\n", "Error: Wrong number of arguments"), 2);
    x = ft_strlen(argv[1]) - 1;
    if (argv[i] == 'b' && argv[i - 1] == 'u' && argv[i - 2] == 'c' && argv[i - 3] == '.')
    {
        check_file(argv[1]);
    }
    return (ft_printf("%s\n", "Error: Map name is wrong"), 2)
}